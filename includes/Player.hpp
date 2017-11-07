/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:54:54 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/11/04 16:54:58 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Object.hpp"

# define BULLET_P ':'
# define BULLETS_AMOUNT 20

class	Player : public Object
{

public:

		Object*	bullets[BULLETS_AMOUNT];
		Player();
		Player(Player const & copy);
		~Player();

		void	refresh();
		void	shoot();
		void	update();
		void	reset();

		Player&		operator=(Player const & copy);
};

#endif
