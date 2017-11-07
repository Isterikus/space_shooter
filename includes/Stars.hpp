/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 23:08:13 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/11/04 23:08:14 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARS_HPP
# define STARS_HPP

# include "Object.hpp"

class	Stars : public Object
{

public:

		Stars();
		Stars(Stars const & copy);
		~Stars();

		Stars&	operator=(Stars const & copy);
};

#endif
