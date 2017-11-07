/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:46:45 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/11/04 16:46:46 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Game.hpp"

Game::Game(void)
{
	_wnd = initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	keypad(_wnd, true);
	nodelay(_wnd, true);
	curs_set(0);
	if(!has_colors()) {
		endwin();
		printf("ERROR: Terminal does not support color.\n");
		exit(1);
	}
	start_color();
	winsize();
	srand(time(NULL));
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	erase();
	_collision = false;
	_starCount = 0;
	_obsCount = 0;
	_score = 1;
	_mY -= 2;
	_maxScore = 0;
}

Game::~Game(void)
{
	endwin();
}

void	Game::restart()
{
	_player.setX(_mX / 2);
	_player.setY(_mY - 3);
	_player.setHP(5);

	int i = -1;
	while (++i < BULLETS_AMOUNT)
	{
		if (_player.bullets[i])
		{
			delete(_player.bullets[i]);
			_player.bullets[i] = 0;
		}
	}
	i = -1;
	int j;
	while (++i < ENEMY_AMOUNT)
	{
		if (_enemies[i].exist)
		{
			j = 0;
			while (j < BULLETS_AMOUNT_E)
			{
				if (_enemies[i].bullets[j])
				{
					delete(_enemies[i].bullets[j]);
					_enemies[i].bullets[j] = 0;
				}
				j++;
			}
			_enemies[i].exist = false;
		}
	}
	i = -1;
	while (++i < OBS_AMOUNT)
		_obs[i].setCh('1');
	i = -1;
	while (++i < STARS_AMOUNT)
		_stars[i].setCh('2');
	erase();
	_collision = false;
	_starCount = 0;
	_obsCount = 0;
	_score = 1;
	run();
}

void	Game::winsize(void)
{
	getmaxyx(_wnd, _mY, _mX);
} 

void	Game::reset_screen(void)
{
	clear();
	refresh();
	winsize();
	_mY -= 2;
	if (_player.getY() > _mY)
		_player.setY(_mY - 2);
	if (_player.getX() > _mX)
		_player.setX(_mX - 2);
}

int		abs(int a) {
	return ((a < 0) ? -a : a);
}

void	Game::update_bg()
{
	int i = 0;
	int	z;

	while (i < STARS_AMOUNT)
	{
		if (_stars[i].getCh() == STAR)
			_stars[i].update();
		i++;
	}
	_player.update();
	i = 0;
	attron(COLOR_PAIR(3));
	while (i < BULLETS_AMOUNT)
	{
		if (_player.bullets[i])
		{
			_player.bullets[i]->setY(_player.bullets[i]->getY() - 1);
			if (_player.bullets[i]->getY() <= 0)
			{
				delete(_player.bullets[i]);
				_player.bullets[i] = 0;
			}
			else
				mvaddch(_player.bullets[i]->getY(), _player.bullets[i]->getX(), BULLET_P);
		}
		i++;
	}
	attroff(COLOR_PAIR(3));
	i = 0;
	attron(COLOR_PAIR(2));
	z = 0;
	while (i < ENEMY_AMOUNT) {
		if (_enemies[i].exist) {
			if (_enemies[i].getY() >= _mY) {
				_enemies[i].exist = false;
				continue;
			}
			if (abs(_player.getX() - _enemies[i].getX()) + abs(_player.getY() - _enemies[i].getY()) < 3) {
				_enemies[i].exist = false;
				_player.setHP(_player.getHP() - 2);
				if (_player.getHP() <= 0)
				{
					_collision = true;
					attroff(COLOR_PAIR(2));
					return ;
				}
			}
			if (i + 1 != ENEMY_AMOUNT) {
				for (int j = i + 1; j < ENEMY_AMOUNT; j++) {
					if (_enemies[j].exist) {
						if (abs(_enemies[i].getX() - _enemies[j].getX()) < 3) {
							if (_enemies[i].getX() > _enemies[j].getX())
								_enemies[j].setX(_enemies[j].getX() - 2);
							else
								_enemies[j].setX(_enemies[j].getX() + 2);
						}
					}
				}
			}
			for (int j = 0; j < BULLETS_AMOUNT; j++) {
				if (_player.bullets[j])
				{
					if (_enemies[i].exist && _enemies[i].Collision(_player.bullets[j]->getX(), _player.bullets[j]->getY(), 1))
					{
						// _enemies[i].exist = false;
						_enemies[i].setHP(_enemies[i].getHP() - 1);
						if (_enemies[i].getHP() <= 0)
							_enemies[i].exist = false;
						delete(_player.bullets[j]);
						_player.bullets[j] = 0;
						if (_enemies[i].type == 3)
							_score += 200;
						else
							_score += 50;
						break;
					}
				}
			}
		}
		i++;
	}
	i = 0;
	while (i < ENEMY_AMOUNT)
	{
		if (_enemies[i].exist)
		{
			if (rand() % ENEMY_SHOOT_RAND == 0 || (_enemies[i].type == 3 && rand() % 15 == 0))
				_enemies[i].shoot();
			for (int j = 0; j < BULLETS_AMOUNT_E; j++)
			{
				if (_enemies[i].bullets[j] &&
					_player.Collision(_enemies[i].bullets[j]->getX(), _enemies[i].bullets[j]->getY(), 1))
				{
					delete(_enemies[i].bullets[j]);
					_enemies[i].bullets[j] = 0;
					if (_player.getHP() == 0) 
					{
						_collision = true;
						attroff(COLOR_PAIR(2));
						return ;
					}
				}
			}
			_enemies[i].refresh(_player.getX(), _player.getY());
			_enemies[i].update();
		}
		i++;
	}
	i = 0;
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(3));
	while (i < OBS_AMOUNT)
	{
		if (_obs[i].getCh() == OBSTACLE)
		{
			if (_player.Collision(_obs[i].getX(), _obs[i].getY(), _obs[i].getRadius()))
			{
				_obs[i].setHP(_obs[i].getHP() - 1);
				_obs[i].setRadius(_obs[i].getRadius() - 1);
				if (_player.getHP() <= 0)
				{
					_collision = true;
					attroff(COLOR_PAIR(3));
					return ;
				}
			}
			z = 0;
			while (z < BULLETS_AMOUNT)
			{
				if (_player.bullets[z] &&
					_obs[i].Collision(_player.bullets[z]->getX(), _player.bullets[z]->getY(), _obs[i].getRadius()))
				{
					_score += 10;
					_obs[i].setRadius(_obs[i].getRadius() - 1);
					if (_obs[i].getHP() == 0)
						_obs[i].setCh('-');
					else
						_obs[i].update();
					_player.bullets[z] = 0;
					break ;
				}
				z++;
			}
			_obs[i].update();
		}
		i++;
	}
	attroff(COLOR_PAIR(3));
}

void	Game::reset_bg()
{
	int i = 0;

	_player.reset();
	while (i < STARS_AMOUNT)
	{
		if (_stars[i].getCh() == STAR)
			_stars[i].reset();
		i++;
	}
	i = 0;
	while (i < OBS_AMOUNT)
	{
		if (_obs[i].getCh() == OBSTACLE)
		{
			if (_obs[i].getY() >= _mY)
				_obs[i].setCh('-');
			_obs[i].reset();
		}
		i++;
	}
}

void	Game::again(void)
{
	int	in_char;
	int	status = -1;

	_player.reset();
	if (_score > _maxScore)
		_maxScore = _score;
	move(_mY / 2 - 2, _mX / 2 - 24);
	printw("YOUR SCORE: %d   |   MAX SCORE: %d", _score, _maxScore);
	move(_mY / 2, _mX / 2 - 30);
	printw("IF YOU WANT PLAY AGAIN, PRESS `Y`, ELSE PRESS `N`");
	while (1)
	{
		in_char = wgetch(_wnd);
		switch(in_char){
			case 'n':
				status = 0;
				break;
			case 'y':
				status = 1;
				break;
			default:
				break;
		}
		if (status != -1)
			break ;
	}
	if (status == 1)
		restart();
	else
		return ;
}

void	Game::createStar()
{
	if (_starCount == STARS_AMOUNT)
		_starCount = 0;
	_stars[_starCount].setCh(STAR);
	_stars[_starCount].setX(rand() % _mX);
	_stars[_starCount].setY(0);
	_starCount++;
}

void	Game::createObs()
{
	if (_obsCount == OBS_AMOUNT)
		_obsCount = 0;
	int r = rand() % _mX;
	if (r <= _obs[_obsCount].getRadius())
		r = _obs[_obsCount].getRadius();
	else if (r >= _mX - _obs[_obsCount].getRadius())
		r = _mX - _obs[_obsCount].getRadius();
	_obs[_obsCount].setCh(OBSTACLE);
	_obs[_obsCount].setX(r);
	_obs[_obsCount].setY(0);
	_obs[_obsCount].setRadius(r % 3 + 1);
	_obsCount++;
}

void	Game::createEnemy()
{
	// if (_score % 1000 >= 900)
	// {
	if (_enemies[0].exist == false) {
		_enemies[0].exist = true;
		_enemies[0].setX(_mX / 2);
		_enemies[0].setY(3);
		_enemies[0].type = 3;
		_enemies[0].setHP(7);
	}
	// } else {
		int r = 1 + rand() % (_mX - 1);
		for (int i = 1; i < ENEMY_AMOUNT; i++) {
			if (!_enemies[i].exist) {
				_enemies[i].setX(r);
				_enemies[i].setY(1);
				_enemies[i].exist = true;
				_enemies[i].type = 1 + rand() % 2;
				break;
			}
		}
	// }
}

void	Game::updateStatus(void)
{
	move(_mY + 1, 0);
	printw("HP: %d    |    Score: %d", _player.getHP(), _score);
}

void    Game::run(void)
{
	bool    exit_req = false;
	int     in_char;
	int		reload;

	reload = 0;
	while (1)
	{
		in_char = wgetch(_wnd);
		werase(_wnd);

		if (rand() % STAR_RAND == 0)
			createStar();

		if (rand() % OBS_RAND == 0)
			createObs();

		if (rand() % ENEMY_RAND == 0)
			createEnemy();
		
		switch(in_char) {
			case 'q':
				exit_req = true;
				break;
			case KEY_UP:
			case 'w':
				if (_player.getY() != 1)
					_player.setY(_player.getY() - 1);
				break;
			case KEY_RESIZE:
				reset_screen();
			case KEY_DOWN:
			case 's':
				if (_player.getY() != _mY - 2)
					_player.setY(_player.getY() + 1);
				break;
			case KEY_LEFT:
			case 'a':
				if (_player.getX() > 2)
					_player.setX(_player.getX() - 2);
				break;
			case KEY_RIGHT:
			case 'd':
				if (_player.getX() < _mX - 3)
					_player.setX(_player.getX() + 2);
				break;
			case ' ':
				if (reload == 5)
				{
					_player.shoot();
					reload = 0;
				}
				break;
			default:
				break;
		}

		update_bg();

		updateStatus();

		if (_collision)
			break ;

		if (exit_req)
			break;

		usleep(CLOCKS_PER_SEC / 30);
	
		if (reload >= 0 && reload != 5)
			reload++;

	}
	again();
}
