/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fregat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:59:42 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/08 12:10:38 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREGAT_HPP
# define FREGAT_HPP

# include "Enemy.hpp"

class Fregat : public Enemy
{
	public:
		Fregat(GameEntity ***map, int x, int y);
};


#endif
