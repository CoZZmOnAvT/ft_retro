/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:22:46 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 12:11:31 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void) {}

Enemy::Enemy(GameEntity ***map, int x, int y) : GameEntity(map, x, y)
{
	this->_type = ENEMY;
}

Enemy::Enemy(Enemy const & obj) { this->_copy(obj); }

Enemy::~Enemy(void) {}

Enemy			&Enemy::operator = (Enemy const & obj)
{
	this->_copy(obj);
	return (*this);
}

Enemy::type_enemy_e	Enemy::getEnemyType(void) const { return (this->_enemy_type); }

void			Enemy::_copy(Enemy const & obj)
{
	this->_type = obj._type;
	this->_enemy_type = obj._enemy_type;
	this->_x = obj._x;
	this->_y = obj._y;
	this->_max_hp = obj._max_hp;
	this->_hp = obj._hp;
	this->_damage = obj._damage;
}
