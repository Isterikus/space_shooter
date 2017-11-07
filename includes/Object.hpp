/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:48:11 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/11/04 17:48:12 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP
# define OBJECT_HPP

#include <ncurses.h>

class	Object
{

protected:

		int		_x;
		int		_y;
		int		_hp;
		int		_radius;
		char	_ch;

public:

		Object(void);
		Object(int x, int y, int hp, int radius, char ch);
		Object(Object const & copy);
		virtual	~Object();

		int		getX() const;
		int		getY() const;
		int		getHP() const;
		char	getCh() const;
		int		getRadius() const;

		void	setRadius(int);
		void	setHP(int);
		void	setX(int);
		void	setY(int);
		void	setCh(char);

		virtual	void	update();
		virtual	void	reset();
		
		bool	Collision(int x, int y, int radius);

		Object&	operator=(Object const & copy);

};

#endif
