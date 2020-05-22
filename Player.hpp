#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "GameEntity.hpp"

class Player : public GameEntity
{
	public:
		Player(GameEntity ***map, int x, int y);
		~Player();

	private:
		Player();
};

 #endif