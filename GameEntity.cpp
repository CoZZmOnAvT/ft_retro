/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:19:14 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 15:13:43 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"
#include "Shoot.hpp"
#include <iostream>

int	GameEntity::score = 0;

GameEntity::GameEntity(void) {}

GameEntity::GameEntity(GameEntity ***map, int x, int y) : _map(map), _x(x), _y(y) {}

GameEntity::~GameEntity(){}

GameEntity::GameEntity(const GameEntity &arg)
{
	*this = arg;
}

int GameEntity::getHP() const
{
	return (this->_hp);
}

int GameEntity::getMaxHP() const
{
	return (this->_max_hp);
}

int GameEntity::getX() const
{
	return (this->_x);
}

int GameEntity::getY() const
{
	return (this->_y);
}

int GameEntity::getDamage() const
{
	return (this->_damage);
}

GameEntity::type_e GameEntity::getType() const
{
	return (this->_type);
}

void GameEntity::move(int dir)
{
	this->_map[this->_y][this->_x] = 0;

	if (dir == 1 || dir == -1)
		this->_y += (dir == 1) ? 1 : -1;
	else if (dir == 2 || dir == -2)
		this->_x += (dir == 2) ? 1 : -1;

	if (this->_map[this->_y][this->_x] != 0
		&& (this->_map[this->_y][this->_x]->getType() == PLAYER || this->_map[this->_y][this->_x]->getType() == BORDER))
		delete this;
	else if (this->_map[this->_y][this->_x] != 0)
	{
		if ((this->getType() == SHOOT && ((Shoot *)this)->getDir() > 0)
			|| (this->_map[this->_y][this->_x]->getType() == SHOOT && ((Shoot *)this->_map[this->_y][this->_x])->getDir() > 0))
			score++;
		delete this->_map[this->_y][this->_x];
		this->_map[this->_y][this->_x] = 0;
		delete this;
	}
	else
		this->_map[this->_y][this->_x] = this;
}

void GameEntity::takeDamage(int amount)
{
	this->_hp -= amount;
	if (this->_hp <= 0)
		this->_hp = 0;
}

GameEntity &GameEntity::operator = (const GameEntity &arg)
{
	this->_map = arg._map;
	this->_type = arg.getType();
	this->_x = arg.getX();
	this->_y = arg.getY();
	this->_hp = arg.getHP();
	this->_max_hp = arg.getMaxHP();
	this->_damage = arg.getDamage();
	return (*this);
}
