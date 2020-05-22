/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:50:32 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/07 19:10:08 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOT_HPP
# define SHOOT_HPP

# include "GameEntity.hpp"

class Shoot : public GameEntity
{
	public:
		Shoot(GameEntity ***map, int x, int y, int damage, int dir);
		~Shoot(void);

		int		getDir(void) const;

	private:
		Shoot(void);

		int		_dir;
};

#endif
