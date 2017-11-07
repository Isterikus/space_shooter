/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:48:09 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/11/04 17:48:10 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Object.hpp"

Object::Object() : _x(0), _y(0), _hp(0), _radius(0), _ch('\"') { }

Object::Object(int x, int y, int hp, int radius, char ch) : _x(x), _y(y), _hp(hp), _radius(radius), _ch(ch) { }

Object::Object(Object const & copy) { *this = copy; }

Object::~Object(void) { }

bool	Object::Collision(int x, int y, int radius)
{
	while (radius != -1)
	{
		if ((_x + radius == x || _x - radius == x) &&
			(_y + radius == y || _y - radius == y))
		{
			_hp--;
			return (true);
		}
		radius--;
	}
	return (false);
}

Object&	Object::operator=(Object const & copy)
{
	if (this != & copy)
	{
		_hp = copy.getHP();
		_x = copy.getX();
		_y = copy.getY();
		_ch = copy.getCh();
		_radius = copy.getRadius();
	}

	return (*this);
}

void	Object::update()
{
	_y += 1;
	mvaddch(_y, _x, _ch);
}

void	Object::reset()
{
	mvaddch(_y, _x, ' ');
}

int		Object::getX() const { return _x; }

int		Object::getY() const { return _y; }

int		Object::getHP() const { return _hp; }

int		Object::getRadius() const { return _radius; }

char	Object::getCh() const { return _ch; }

void	Object::setRadius(int radius) { _radius = radius; }

void	Object::setHP(int hp) { _hp = hp; }

void	Object::setX(int x) { _x = x; }

void	Object::setY(int y) { _y = y; }

void	Object::setCh(char ch) { _ch = ch; }
