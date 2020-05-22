/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:31:07 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 15:08:18 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Player.hpp"
#include "Asteroid.hpp"
#include <iostream>
#include <ncurses.h>
#include <locale.h>

int		main(void)
{
	srand(time(NULL));
	initscr();
	nodelay(stdscr, true);
	noecho();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	if (COLS < 10 || LINES < 10)
	{
		std::cout << "Window too small!" << std::endl;
		endwin();
		return (-1);
	}
	Game ko = Game(COLS, LINES);
	curs_set(0);
	keypad(stdscr, true);

	ko.start();
	endwin();
	return (0);
}
