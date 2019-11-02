#pragma once
#include <string>
class Player
{
public:
	Player(int x, int y, std::string pos);
	int getX() { return m_x; }
	int getY() { return m_y; }
	std::string getPos() { return m_pos; }
	friend Player operator+(Player player, std::string pos);
	Player operator=(Player player);
	void setX(int x) { m_x = x; }
	void setY(int y) { m_y = y; }
	void setPos(std::string pos) { m_pos = pos; }
private:
	int m_x;
	int m_y;
	std::string m_pos;
};

