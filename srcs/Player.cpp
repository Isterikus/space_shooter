/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:54:42 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/11/04 16:54:44 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"

Player::Player() : Object(20, 20, 5, 2, '*') {
	for (int i = 0; i < BULLETS_AMOUNT; i++){
		this->bullets[i] = 0;
	}
}

Player::Player(Player const & copy)
{
	*this = copy;
}

Player::~Player() {
	for (int i = 0; i < BULLETS_AMOUNT; i++) {
		if (this->bullets[i]) {
			delete(this->bullets[i]);
		}
	}
}

void	Player::shoot() {
	for (int i = 0; i < BULLETS_AMOUNT; i++) {
		if (!this->bullets[i]) {
			this->bullets[i] = new Object(this->getX(), this->getY() - 1, 1, 1, BULLET_P);
			return ;
		}
	}
}

// void	Player::refresh() {
// 	attron(COLOR_PAIR(3));
// 	for (int i = 0; i < BULLETS_AMOUNT; i++) {
// 		if (this->bullets[i]) {
// 			this->bullets[i]->setY(this->bullets[i]->getY() - 1);
// 			if (this->bullets[i]->getY() < 0) {
// 				delete(this->bullets[i]);
// 				this->bullets[i] = 0;
// 			} else {
// 				mvaddch(this->bullets[i]->getY(), this->bullets[i]->getX(), BULLET_P);
// 			}
// 		}
// 	}
// 	attroff(COLOR_PAIR(3));
// }

void	Player::update()
{
	mvaddch(_y, _x, '+');
	mvaddch(_y - 1, _x, '^');
	mvaddch(_y + 1, _x, '_');
	mvaddch(_y, _x + 1, ':');
	mvaddch(_y, _x - 1, ':');
	mvaddch(_y + 1, _x - 1, '\\');
	mvaddch(_y + 1, _x + 1, '/');
	mvaddch(_y - 1, _x - 1, '/');
	mvaddch(_y - 1, _x + 1, '\\');
}

void	Player::reset()
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
}

Player&	Player::operator=(Player const & copy)
{
	if (this != &copy)
	{
		_hp = copy.getHP();
		_x = copy.getX();
		_y = copy.getY();
		_ch = copy.getCh();
		for (int i = 0; i < BULLETS_AMOUNT; i++){
			this->bullets[i] = copy.bullets[i];
		}
	}

	return (*this);
}