#include "Fruits.h"

int rands()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rrandom(0, 12);
	return rrandom(rng);
}
Fruits::Fruits()
{
	m_x = rands();
	m_y = rands();
}

Fruits::~Fruits()
{
	m_x = rands();
	m_y = rands();
}
