/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:51:07 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/11/04 17:51:08 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Obstacle.hpp"

Obstacle::Obstacle() : Object(5, 5, 3, 3, '&') { }

Obstacle::Obstacle(Obstacle const & copy) { *this = copy; }

Obstacle::~Obstacle() { }

void		Obstacle::reset()
{
	if (_radius == 3)
	{
		mvaddch(_y, _x, ' ');
		mvaddch(_y - 1, _x, ' ');
		mvaddch(_y + 1, _x, ' ');
		mvaddch(_y, _x + 1, ' ');
		mvaddch(_y, _x - 1, ' ');
		mvaddch(_y + 1, _x - 1, ' ');
		mvaddch(_y + 1, _x + 1, ' ');
		mvaddch(_y - 1, _x - 1, ' ');
		mvaddch(_y - 1, _x + 1, ' ');
		mvaddch(_y, _x + 2, ' ');
		mvaddch(_y + 2, _x, ' ');
		mvaddch(_y - 2, _x, ' ');
		mvaddch(_y, _x - 2, ' ');
	}
	else if (_radius == 2)
	{
		mvaddch(_y, _x, ' ');
		mvaddch(_y - 1, _x, ' ');
		mvaddch(_y + 1, _x, ' ');
		mvaddch(_y, _x + 1, ' ');
		mvaddch(_y, _x - 1, ' ');
	}
	else
		mvaddch(_y, _x, ' ');
}

void		Obstacle::update()
{	
	_y += 1;
	if (_radius == 3)
	{
		mvaddch(_y, _x, '*');
		mvaddch(_y - 1, _x, '*');
		mvaddch(_y + 1, _x, '*');
		mvaddch(_y, _x + 1, '*');
		mvaddch(_y, _x - 1, '*');
		mvaddch(_y + 1, _x - 1, '*');
		mvaddch(_y + 1, _x + 1, '*');
		mvaddch(_y - 1, _x - 1, '*');
		mvaddch(_y - 1, _x + 1, '*');
		mvaddch(_y, _x + 2, '*');
		mvaddch(_y + 2, _x, '*');
		mvaddch(_y - 2, _x, '*');
		mvaddch(_y , _x - 2, '*');
	}
	else if (_radius == 2)
	{
		mvaddch(_y, _x, '*');
		mvaddch(_y - 1, _x, '*');
		mvaddch(_y + 1, _x, '*');
		mvaddch(_y, _x + 1, '*');
		mvaddch(_y, _x - 1, '*');
	}
	else if (_radius == 1)
		mvaddch(_y, _x, '*');
}

Obstacle&	Obstacle::operator=(Obstacle const & copy)
{
	if (this != &copy)
		Object::operator=(copy);

	return (*this);
}

