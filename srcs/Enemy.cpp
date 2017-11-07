#include "../includes/Enemy.hpp"

Enemy::Enemy() : Object(100, 2, 2, 2, '*') {
	this->type = 1;
	this->exist = false;
	for (int i = 0; i < BULLETS_AMOUNT_E; i++){
		this->bullets[i] = 0;
	}
}

Enemy::Enemy(Enemy const & copy)
{
	*this = copy;
}

Enemy::~Enemy() {
	for (int i = 0; i < BULLETS_AMOUNT_E; i++) {
		if (this->bullets[i]) {
			delete(this->bullets[i]);
		}
	}
}

int		Enemy::getType() {
	return this->type;
}

void	Enemy::shoot() {
	int		count = 0;
	int		x = 0;
	int		y = 0;
	if (this->type == 1) {
		for (int i = 0; i < BULLETS_AMOUNT_E; i++) {
			if (!this->bullets[i]) {
				this->bullets[i] = new Object(this->getX(), this->getY() + 2, 1, 1, BULLET_E);
				return;
			}
		}
	} else if (this->type == 3) {
		for (int i = 0; i < BULLETS_AMOUNT_E; i++) {
			if (count == 3)
				return;
			if (!this->bullets[i]) {
				if (count == 0) {
					x = -2;
					y = 1;
				} else if (count == 1) {
					x = 0;
					y = 2;
				} else if (count == 2) {
					x = 2;
					y = 1;
				}
				this->bullets[i] = new Object(this->getX() + x, this->getY() + y, 1, 1, BULLET_E);
				count++;
			}
		}
	}
}

void	Enemy::refresh(int x, int y) {
	attron(COLOR_PAIR(6));
	if (this->type == 1) {
		if (_x > x) {
			if (rand() % 2 != 0)
				_x--;
		} else {
			if (rand() % 2 != 0)
				_x++;
		}
		for (int i = 0; i < BULLETS_AMOUNT_E; i++) {
			if (this->bullets[i]) {
				this->bullets[i]->setY(this->bullets[i]->getY() + 1);
				if (this->bullets[i]->getY() > 150) {
					delete(this->bullets[i]);
					this->bullets[i] = 0;
				} else {
					mvaddch(this->bullets[i]->getY(), this->bullets[i]->getX(), BULLET_E);
				}
			}
		}
	} else if (this->type == 2) {
		if (_y >= y) {
			_y++;
		} else {
			if (_x > x) {
				if (rand() % 2 != 0)
					_x--;
			} else {
				if (rand() % 2 != 0)
					_x++;
			}
			if (_y > y) {
				if (rand() % 2 != 0)
					_y--;
			} else {
				if (rand() % 2 != 0)
					_y++;
			}
		}
	} else if (this->type == 3) {
		if (_x > x) {
			_x--;
		} else {
			_x++;
		}
		for (int i = 0; i < BULLETS_AMOUNT_E; i++) {
			if (this->bullets[i]) {
				this->bullets[i]->setY(this->bullets[i]->getY() + 1);
				if (this->bullets[i]->getY() > 200) {
					delete(this->bullets[i]);
					this->bullets[i] = 0;
				} else {
					mvaddch(this->bullets[i]->getY(), this->bullets[i]->getX(), BULLET_E);
				}
			}
		}
	}
	attroff(COLOR_PAIR(6));
}

void	Enemy::update()
{
	if (this->type == 1) {
		mvaddch(_y, _x, '#');
		mvaddch(_y - 1, _x, '-');
		mvaddch(_y + 1, _x, '|');
		mvaddch(_y, _x + 1, ']');
		mvaddch(_y, _x - 1, '[');
		mvaddch(_y + 1, _x - 1, ' ');
		mvaddch(_y + 1, _x + 1, ' ');
		mvaddch(_y - 1, _x - 1, '/');
		mvaddch(_y - 1, _x + 1, '\\');
	} else if (this->type == 2) {
		mvaddch(_y, _x, '@');
		mvaddch(_y - 1, _x, ' ');
		mvaddch(_y + 1, _x, '!');
		mvaddch(_y, _x + 1, '>');
		mvaddch(_y, _x - 1, '<');
		mvaddch(_y + 1, _x - 1, '\\');
		mvaddch(_y + 1, _x + 1, '/');
		mvaddch(_y - 1, _x - 1, '/');
		mvaddch(_y - 1, _x + 1, '\\');
	} else if (this->type == 3) {
		mvaddch(_y, _x, '#');
		mvaddch(_y - 1, _x, '#');
		mvaddch(_y + 1, _x, '#');
		mvaddch(_y + 2, _x, '|');
		mvaddch(_y, _x + 1, '#');
		mvaddch(_y, _x - 1, '#');
		mvaddch(_y, _x + 2, '#');
		mvaddch(_y, _x - 2, '#');
		mvaddch(_y, _x + 3, '/');
		mvaddch(_y, _x - 3, '\\');
		mvaddch(_y - 1, _x + 3, '-');
		mvaddch(_y - 1, _x - 3, '-');
		mvaddch(_y + 1, _x - 1, '\\');
		mvaddch(_y + 1, _x + 1, '/');
		mvaddch(_y + 1, _x - 2, '|');
		mvaddch(_y + 1, _x + 2, '|');
		mvaddch(_y - 1, _x - 1, '#');
		mvaddch(_y - 1, _x + 1, '#');
		mvaddch(_y - 1, _x - 2, '-');
		mvaddch(_y - 1, _x + 2, '-');
	}
}

void	Enemy::reset()
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

Enemy&	Enemy::operator=(Enemy const & copy)
{
	if (this != &copy)
	{
		_hp = copy.getHP();
		_x = copy.getX();
		_y = copy.getY();
		_ch = copy.getCh();
		this->type = copy.type;
		for (int i = 0; i < BULLETS_AMOUNT_E; i++){
			this->bullets[i] = copy.bullets[i];
		}
	}

	return (*this);
}
