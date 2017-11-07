/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 23:08:10 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/11/04 23:08:11 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Stars.hpp"

Stars::Stars() : Object(5, 5, 1, 1, '7') { }

Stars::Stars(Stars const & copy) { *this = copy; }

Stars::~Stars() { }

Stars&	Stars::operator=(Stars const & copy)
{
	if (this != &copy)
		Object::operator=(copy);

	return (*this);
}
