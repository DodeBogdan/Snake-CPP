#include <iostream>
#include <conio.h>
#include "Player.h"
#include <atomic>
#include <chrono>
#include <thread>
#include <vector>
#include "Fruits.h"
/*De facut:
1.Nivele(optional).*/
int lineDim = 13;
int columnDim = 13;
int mat[13][13] = { 0 };
int points = 1;

void afisMat(std::vector<Player> player, Fruits fructe)
{
	std::cout << " ";
	for (int i = 0; i < 26; i++)
		std::cout << "_";
	std::cout << std::endl;
	for (int i = 0; i < lineDim; i++) {
		std::cout << "|";
		for (int j = 0; j < columnDim; j++) {
			int ok = 0;
			for (int k = 0; k < player.size(); k++)
				if (player[k].getX() == i && player[k].getY() == j)
					if (k == 0)
						ok = 1;
					else 
						ok = 2;
			if (ok == 1)
				std::cout << "@ ";
			else if (ok == 2)
				std::cout << "* ";
			else if (fructe.getX() == i && fructe.getY() == j)
				std::cout << "& ";
			else std::cout << "  ";
		}
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << " ";
	for (int i = 0; i < 26; i++)
		std::cout << "-";
}
void repos(std::vector<Player>& player, std::string pos, std::vector<Player> temp)
{
	for (int index = 1; index < player.size(); index++) {
		player[index] = temp[index - 1];
	}
}
bool gameOver(std::vector<Player> player)
{
	if (player[0].getX() == -1 || player[0].getX() == 13)
	{
		std::cout << "\n\n\n\t GAME OVER!!!\n   You have done: " << points << " points.\n\n";
		return 0;
	}else
	if (player[0].getY() == -1 || player[0].getY() == 13)
	{
		std::cout << "\n\n\n\t GAME OVER!!!\n   You have done: " << points << " points.\n\n";
		return 0;
	}else
		for(int i = 1; i < player.size(); i++)
			if(player[0].getX() == player[i].getX() && player[0].getY() == player[i].getY())
			{
				std::cout << "\n\n\n\t GAME OVER!!!\n   You have done: "<<points<<" points.\n\n";
				return 0;
			}
	return 1;
}
void keyborad(std::vector<Player> player,Fruits fructe)
{
	std::string pos;
	pos.push_back('x');
	char ch;
	//Fruits fructe;
	std::vector<Player> temp = player;
	do {
		std::vector<Player> temp = player;
		pos.pop_back();
		ch = _getch();
		pos.push_back(ch);
		if (pos[0] != 'p') {
			player[0] = player[0] + pos;
			repos(player,pos,temp);
			system("cls");
			afisMat(player,fructe);
			if (fructe.getX() == player[0].getX() && fructe.getY() == player[0].getY()) {
				for(int i = 0; i < player.size(); i++)
					while(fructe.getX() == player[i].getX() && fructe.getY() == player[i].getY())
						fructe.~Fruits();
				Player p(player[player.size()-1].getX()-1, player[player.size() - 1].getY(), "E");
				player.push_back(p);
				points++;
			}

		}
	} while (ch != 'p' && gameOver(player) == 1);
	return;
}

void startGame()
{
	std::vector<Player> player;
	Fruits fructe;
	Player pl(6,6," ");
	player.push_back(pl);
	afisMat(player,fructe);
	keyborad(player,fructe);
}
int main()
{
	startGame();
	return 0;
}