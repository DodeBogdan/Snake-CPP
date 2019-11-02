#pragma once
#include <random>
#include <iostream>
#include <vector>
class Fruits
{
public:
	Fruits();
	~Fruits();
	int getX() { return m_x; }
	int getY() { return m_y; }
private:
	int m_x;
	int m_y;
	std::vector<int>m_vecX;
	std::vector<int>m_vecY;
};

