/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fregat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:59:39 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/07 19:04:25 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fregat.hpp"

Fregat::Fregat(GameEntity ***map, int x, int y) : Enemy(map, x, y)
{
	this->_enemy_type = FREGAT;
	this->_hp = 60;
	this->_max_hp = 60;
	this->_damage = 40;
}
