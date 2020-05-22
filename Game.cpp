/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:22:38 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 16:31:18 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

#include <cstring>

Game::Game(void) {}

Game::Game(int w, int h) : _map_width(w), _map_height(h)
{
	this->_map = new GameEntity ** [this->_map_height]();
	for (int i = 0; i < this->_map_height; i++)
		this->_map[i] = new GameEntity * [this->_map_width]();
}

Game::~Game(void)
{
	for (int i = 0; i < this->_map_height; i++)
		delete[] this->_map[i];
	delete[] this->_map;
}

GameEntity	***Game::getMap(void) const { return (this->_map); }
int			Game::getWidth(void) const { return (this->_map_width); }
int			Game::getHeight(void) const { return (this->_map_height); }

void		Game::start(void)
{
	Player	*player1 = new Player(this->_map, 2, this->_map_height / 2);
	this->_map[this->_map_height / 2][2] = player1;
	for (int i = 1; i < this->_map_height - 1; i++)
	{
		this->_map[i][this->_map_width - 1] = new Border(this->_map, this->_map_width - 1, i);
		this->_map[i][0] = new Border(this->_map, 0, i);
	}

	while (true)
	{
		int ch = getch();

		clear();
		this->_makeActions();

		if (!this->_checkPlayerPosition(player1))
		{
			this->_displayDeadScreen();
			break ;
		}

		switch (ch)
		{
			case 258:
				if (player1->getY() < this->_map_height - 2)
					player1->move(1);
				break;
			case 259:
				if (player1->getY() > 3)
					player1->move(-1);
				break;
			case 260:
				if (player1->getX() > 2)
					player1->move(-2);
				break;
			case 261:
				if (player1->getX() < this->_map_width - 3)
					player1->move(2);
				break;
			case 113:
				endwin();
				exit(0);
				break;
			case 32:
				if (this->_map[player1->getY()][player1->getX() + 1] == 0)
					this->_map[player1->getY()][player1->getX() + 1] = new Shoot(this->_map, player1->getX() + 1, player1->getY(), player1->getDamage() / 2, 1);
				break;
			default:
				break;
		}
		this->_displayHud(player1);
		this->_drawMap();
		usleep(40000);
	}
}

void	Game::_drawMap(void) const
{
	border(0, 0, 0, 0, 0, 0, 0, 0);
	for (int i = 0; i < this->_map_height; i++)
		for (int j = 0; j < this->_map_width; j++)
		{
			if (!this->_map[i][j])
				continue ;

			move(i, j);
			if (this->_map[i][j]->getType() == GameEntity::PLAYER)
			{
				attron(COLOR_PAIR(3));
				addch(ACS_DIAMOND);
				move(i - 1, j);
				addch(ACS_UARROW);
				move(i + 1, j);
				addch(ACS_DARROW);
				move(i, j - 1);
				addch(ACS_LARROW);
				move(i, j + 1);
				addch(ACS_RARROW);
				attroff(COLOR_PAIR(3));
			}
			else if (this->_map[i][j]->getType() == GameEntity::ENEMY)
			{
				if (((Enemy *)this->_map[i][j])->getEnemyType() == Enemy::ASTEROID)
				{
					attron(COLOR_PAIR(2));
					addch('*');
					attroff(COLOR_PAIR(2));
				}
				else if (((Enemy *)this->_map[i][j])->getEnemyType() == Enemy::FREGAT)
				{
					attron(COLOR_PAIR(1));
					addch('<');
					attroff(COLOR_PAIR(1));
					if (j > 3 && rand() % 37 == 0 && this->_map[i][j - 2] == 0)
						this->_map[i][j - 2] = new Shoot(this->_map, j - 2, i, this->_map[i][j]->getDamage() / 2, -1);
				}
				this->_map[i][j]->move(-2);
			}
			else if (this->_map[i][j]->getType() == GameEntity::SHOOT)
			{
				int		dir = ((Shoot *)this->_map[i][j])->getDir();
				addch('-');
				this->_map[i][j]->move(dir * 2);
				if (this->_map[i][j + dir] != 0 && this->_map[i][j + dir]->getType() == GameEntity::SHOOT)
					this->_map[i][j + dir]->move(dir * 2);
				if (dir > 0)
					j += 2;
			}
		}
	refresh();
}

void	Game::_makeActions(void) const
{
	for (int i = 3; i < this->_map_height - 1; i++)
	{
		if (this->_map[i][this->_map_width - 2] == 0 && rand() % 101 == 0)
			this->_map[i][this->_map_width - 2] = new Asteroid(this->_map, this->_map_width - 2, i);
		else if (this->_map[i][this->_map_width - 2] == 0 && rand() % 257 == 0)
			this->_map[i][this->_map_width - 2] = new Fregat(this->_map, this->_map_width - 2, i);
		else if (this->_map[i][this->_map_width - 2] != 0 && this->_map[i][this->_map_width - 2]->getType() == GameEntity::SHOOT)
		{
			delete this->_map[i][this->_map_width - 2];
			this->_map[i][this->_map_width - 2] = 0;
		}
	}

	for (int i = 1; i < this->_map_height - 1; i++)
	{
		if (this->_map[i][0] != 0
			&& (this->_map[i][0]->getType() == GameEntity::ENEMY
				|| this->_map[i][0]->getType() == GameEntity::SHOOT))
		{
			delete this->_map[i][0];
			this->_map[i][0] = 0;
		}
	}
}

bool	Game::_checkPlayerPosition(Player *player)
{
	int		x = player->getX();
	int		y = player->getY();

	if (this->_map[y + 1][x] != 0 && this->_map[y + 1][x]->getType() != GameEntity::BORDER)
	{
		player->takeDamage(this->_map[y + 1][x]->getDamage());
		delete this->_map[y + 1][x];
		this->_map[y + 1][x] = 0;
	}
	else if (this->_map[y - 1][x] != 0 && this->_map[y - 1][x]->getType() != GameEntity::BORDER)
	{
		player->takeDamage(this->_map[y - 1][x]->getDamage());
		delete this->_map[y - 1][x];
		this->_map[y - 1][x] = 0;
	}
	else if (this->_map[y][x + 1] != 0 && this->_map[y][x + 1]->getType() != GameEntity::BORDER)
	{
		player->takeDamage(this->_map[y][x + 1]->getDamage());
		delete this->_map[y][x + 1];
		this->_map[y][x + 1] = 0;
	}
	else if (this->_map[y][x - 1] != 0 && this->_map[y][x - 1]->getType() != GameEntity::BORDER)
	{
		player->takeDamage(this->_map[y][x - 1]->getDamage());
		delete this->_map[y][x - 1];
		this->_map[y][x - 1] = 0;
	}

	if (player->getHP() <= 0)
		return (false);
	else
		return (true);
}

void	Game::_displayHud(Player *player1) const
{
	move(1, 1);
	printw("HP: %d, Score: %d", player1->getHP(), GameEntity::score);
}

void	Game::_displayDeadScreen(void) const
{
	char	msg[] = "You lose!";
	char	msg2[] = "Your score: ";
	int		row;
	int		col;

	clear();
	border(0, 0, 0, 0, 0, 0, 0, 0);
	getmaxyx(stdscr, row, col);
	attron(COLOR_PAIR(1));
	mvwprintw(stdscr, row / 2, (col - strlen(msg)) / 2, "%s", msg);
	mvwprintw(stdscr, row / 2 + 1, (col - strlen(msg2) - 4) / 2, "%s%d", msg2, GameEntity::score);
	attroff(COLOR_PAIR(1));
	refresh();
	sleep(3);
}