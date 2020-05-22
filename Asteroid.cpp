/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:59:26 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 12:10:29 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroid.hpp"

Asteroid::Asteroid(GameEntity ***map, int x, int y) : Enemy(map, x, y)
{
	this->_enemy_type = ASTEROID;
	this->_hp = 40;
	this->_max_hp = 40;
	this->_damage = 20;
}
