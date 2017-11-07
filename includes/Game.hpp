/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:45:09 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/11/04 16:45:13 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <ncurses.h>
# include <unistd.h>

# include <cstdint>
# include <cstdlib>
# include <string>
# include <ctime>

# include "Obstacle.hpp"
# include "Player.hpp"
# include "Stars.hpp"
# include "Enemy.hpp"

# define BULLET_P ':'
# define STAR '.'
# define OBSTACLE '*'
# define OBS_AMOUNT 40
# define ENEMY_AMOUNT 6
# define STARS_AMOUNT 100
# define BULLETS_AMOUNT 20
# define BULLETS_AMOUNT_E 200
# define OBS_UPDATE 150
# define OBS_RAND 15
# define STAR_UPDATE 25
# define STAR_RAND 2
# define ENEMY_RAND 15
# define ENEMY_SHOOT_RAND 35

class	Game
{

private:

		Obstacle	_obs[OBS_AMOUNT];
		Stars		_stars[STARS_AMOUNT];
		Enemy		_enemies[ENEMY_AMOUNT];
		Player		_player;
		WINDOW*		_wnd;
		WINDOW*		_info;

		int			_starCount;
		int			_obsCount;
		int			_score;
		int			_maxScore;

		int			_mX;
		int			_mY;
		bool		_collision;

public:

		Game();
		~Game();

		void	createObs();
		void	createStar();

		void	set_player();
		void	set_obstacles();
		void	reset_player();
		void	reset_obstacles();
		void	reset_bg();
		void	update_bg();
		void	winsize();
		void	restart();
		void	run();
		void	again();
		void	reset_screen();
		void	updateStatus(void);
		void	createEnemy();
};

#endif
