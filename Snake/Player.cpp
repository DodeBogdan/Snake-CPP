#include "Player.h"

Player::Player(int x, int y, std::string pos) : m_x(x), m_y(y), m_pos(pos)
{
}

Player Player::operator=(Player player)
{
	m_x = player.m_x;
	m_y = player.m_y;
	m_pos = player.m_pos;
	return player;
}

Player operator+(Player player, std::string pos)
{
	if (pos[0] == 'w' && player.m_pos[0] != 's')
	{
			player.m_x--;
		player.m_pos[0] = 'n';
	}else
	if (pos[0] == 's' && player.m_pos[0] != 'n')
	{
			player.m_x++;
		player.m_pos[0] = 's';
	}else
	if (pos[0] == 'd' && player.m_pos[0] != 'w')
	{
			player.m_y++;
		player.m_pos[0] = 'e';
	}else
	if (pos[0] == 'a' && player.m_pos[0] != 'e')
	{
			player.m_y--;
		player.m_pos[0] = 'w';
	}
	else
	{
		if (player.getPos() == "e")
		{
				player.m_y++;
		}else
		if (player.getPos() == "w")
		{
				player.m_y--;
		}else
		if (player.getPos() == "s")
		{
			player.m_x++;
		}else
		if (player.getPos() == "n")
		{
			player.m_x--;
		}
	}
	
	return player;
}
