/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:50:29 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/07 23:54:47 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shoot.hpp"

Shoot::Shoot(void) {}

Shoot::Shoot(GameEntity ***map, int x, int y, int damage, int dir) : GameEntity(map, x, y)
{
	this->_type = SHOOT;
	this->_damage = damage;
	this->_dir = dir;
}

Shoot::~Shoot(void) {}

int		Shoot::getDir(void) const { return (this->_dir); }
