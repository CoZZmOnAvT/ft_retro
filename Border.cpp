/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Border.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 12:06:42 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 12:25:30 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Border.hpp"

Border::Border(void) {}

Border::Border(GameEntity ***map, int x, int y) : GameEntity(map, x, y)
{
	this->_type = BORDER;
	this->_hp = 9999999;
	this->_max_hp = 9999999;
	this->_damage = 9999999;
}

Border::~Border() {}
