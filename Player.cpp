/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:57:31 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 12:24:39 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void) {}

Player::Player(GameEntity ***map, int x, int y) : GameEntity(map, x, y)
{
	this->_type = PLAYER;
	this->_hp = 100;
	this->_max_hp = 100;
	this->_damage = 40;
}

Player::~Player() {}
