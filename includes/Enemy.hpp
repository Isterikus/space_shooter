#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <cstdint>
# include <cstdlib>
# include <string>
# include <ctime>

# include "Object.hpp"

# define BULLET_E '|'
# define BULLETS_AMOUNT_E 200

class	Enemy : public Object
{

public:
		int		type;
		bool	exist;
		Object*	bullets[BULLETS_AMOUNT_E];
		Enemy();
		Enemy(Enemy const & copy);
		~Enemy();
		int		getType();

		void	refresh(int x, int y);
		void	shoot();
		void	update();
		void	reset();

		Enemy&		operator=(Enemy const & copy);
};

#endif
