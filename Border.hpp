/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Border.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 12:06:44 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 12:23:48 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BORDER_HPP
# define BORDER_HPP

#include "GameEntity.hpp"

class Border : public GameEntity
{
	public:
		Border(GameEntity ***map, int x, int y);
		~Border();

	private:
		Border();

};

#endif
