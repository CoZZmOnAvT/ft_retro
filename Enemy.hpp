/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:22:52 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 12:11:37 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "GameEntity.hpp"

class Enemy : public GameEntity
{
	public:
		enum type_enemy_e {ASTEROID = 1, FREGAT};

		Enemy(GameEntity ***map, int x, int y);
		Enemy(Enemy const & obj);
		~Enemy(void);

		Enemy	&operator = (Enemy const & obj);

		type_enemy_e	getEnemyType(void) const;


	protected:
		type_enemy_e	_enemy_type;

		void			_copy(Enemy const & obj);

	private:
		Enemy(void);
};

#endif
