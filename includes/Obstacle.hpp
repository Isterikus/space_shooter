/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:51:05 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/11/04 17:51:06 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_HPP
# define OBSTACLE_HPP

# include "Object.hpp"

class	Obstacle : public Object
{

public:

		Obstacle();
		Obstacle(Obstacle const & copy);
		~Obstacle();

		void		update();
		void		reset();

		Obstacle&	operator=(Obstacle const & copy);
};

#endif

