/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:40:06 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 15:13:39 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_HPP
# define GAMEENTITY_HPP

# include "IGameEntity.hpp"

class GameEntity : public IGameEntity
{
	public:
		enum type_e {ENEMY = 1, SHOOT, PLAYER, BORDER};

		GameEntity(void);
		GameEntity(GameEntity ***map, int x, int y);
		GameEntity(GameEntity const & arg);
		~GameEntity(void);

		void	move(int dir);
		void	takeDamage(int amount);
		int		getHP() const;
		int		getDamage() const;
		int		getMaxHP() const;
		int		getX() const;
		int		getY() const;
		type_e	getType() const;

		GameEntity &operator = (GameEntity const & arg);

	static int	score;

	protected:
		GameEntity	***_map;
		type_e		_type;
		int			_x;
		int			_y;
		int			_max_hp;
		int			_hp;
		int			_damage;
};

#endif
