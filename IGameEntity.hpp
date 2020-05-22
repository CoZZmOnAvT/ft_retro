/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGameEntity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:09:54 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 13:00:56 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	MOVE DIRECTION: X = (-2 / 2), Y = (-1 / 1)

#ifndef IGAMEENTITY_HPP
# define IGAMEENTITY_HPP

class IGameEntity
{
	public:
		virtual	~IGameEntity(void) {};

		virtual void	move(int dir) = 0;
};

#endif
