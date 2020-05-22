/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:23:25 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 15:18:14 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "GameEntity.hpp"
# include "Player.hpp"
# include "Border.hpp"
# include "Shoot.hpp"
# include "Enemy.hpp"
# include "Fregat.hpp"
# include "Asteroid.hpp"
# include <iostream>
# include <ncurses.h>
# include <unistd.h>

class Game
{
	public:
		Game(int w, int h);
		~Game(void);

		GameEntity	***getMap(void) const;
		int			getWidth(void) const;
		int			getHeight(void) const;

		void		start(void);

	protected:
		Game(void);

		GameEntity	***_map;
		int			_map_width;
		int			_map_height;

	private:
		void	_drawMap(void) const;
		void	_makeActions(void) const;
		bool	_checkPlayerPosition(Player *player);
		void	_displayHud(Player *player1) const;
		void	_displayDeadScreen(void) const;
};

#endif
