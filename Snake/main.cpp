#include <iostream>
#include <conio.h>
#include "Player.h"
#include <atomic>
#include <chrono>
#include <thread>
#include <vector>
#include "Fruits.h"
#include <Windows.h>
/*De facut:
1.Nivele(optional).*/
int lineDim = 13;
int columnDim = 13;
int mat[13][13] = { 0 };
int points = 1;
int speedGame = 100;
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
		std::cout << "\n\n\n\t GAME OVER!!!/Sfarsit de joc!!!\n   You have done:/Ai facut: " << points << " points./puncte.\n\n";
		return 0;
	}else
	if (player[0].getY() == -1 || player[0].getY() == 13)
	{
		std::cout << "\n\n\n\t GAME OVER!!!/Sfarsit de joc!!!\n   You have done:/Ai facut: " << points << " points./puncte.\n\n";
		return 0;
	}else
		for(int i = 1; i < player.size(); i++)
			if(player[0].getX() == player[i].getX() && player[0].getY() == player[i].getY())
			{
				std::cout << "\n\n\n\t GAME OVER!!!/Sfarsit de joc!!!\n   You have done:/Ai facut: "<<points<<" points./puncte.\n\n";
				return 0;
			}
	return 1;
}
void singleMovement(std::vector<Player>& player)
{

	std::string pos;
	std::vector<Player> temp = player;
	player[0] = player[0] + pos;
	repos(player, pos, temp);

}
void keyborad(std::vector<Player> player,Fruits fructe)
{
	std::cout << "\nPress any key to start.../Apasa orice tasta pentru a incepe...";
	_getch();
	std::string pos;
	pos.push_back('x');
	char ch = 'g';
	//Fruits fructe;
	std::vector<Player> temp = player;
	do {
	input:
		std::vector<Player> temp = player;
		if (_kbhit()) {
			pos.pop_back();
			ch = _getch();
			pos.push_back(ch);
			if (pos[0] != 'p') {
				player[0] = player[0] + pos;
				repos(player, pos, temp);
				system("cls");
				afisMat(player, fructe);
				if (fructe.getX() == player[0].getX() && fructe.getY() == player[0].getY()) {
					for (int i = 0; i < player.size(); i++)
						while (fructe.getX() == player[i].getX() && fructe.getY() == player[i].getY())
							fructe.~Fruits();
					Player p(player[player.size() - 1].getX() - 1, player[player.size() - 1].getY(), "f");
					player.push_back(p);
					points++;
				}

			}
		} 
		if (_kbhit()) 
			goto input;
		Sleep(speedGame);
		singleMovement(player);
		system("cls");
		afisMat(player, fructe);
		if (fructe.getX() == player[0].getX() && fructe.getY() == player[0].getY()) {
			for (int i = 0; i < player.size(); i++)
				while (fructe.getX() == player[i].getX() && fructe.getY() == player[i].getY())
					fructe.~Fruits();
			Player p(player[player.size() - 1].getX() - 1, player[player.size() - 1].getY(), "f");
			player.push_back(p);
			points++;
		}
	} while (ch != 'p' && gameOver(player) == 1);
	return;
}
void Start()
{
	std::vector<Player> player;
	Fruits fructe;
	Player pl(6, 6, "n");
	player.push_back(pl);
	afisMat(player, fructe);
	keyborad(player, fructe);
}
void startGame()
{
startG:
	system("cls");
	std::cout << "1.Start Game!/Incepe joc!\n2.Exit./Iesi.\n";
	char op;
	op = _getch();
	if (op == '1') {
		system("cls");
	difficulty:
		system("cls");
		std::cout << "Choose difficulty:/Alege dificultatea.\n1.Easy./Usor.\n2.Medium./Mediu.\n3.Hard./Greu.\n";
		op = _getch();
		if (op == '1')
			speedGame = 500;
		else if (op == '2')
			speedGame = 250;
		else if (op == '3')
			speedGame = 100;
		else { std::cout << "You have introduce wrong input./Ai introdus un input gresit."; Sleep(150); goto difficulty; }
		system("cls");
		Start();
		retry:
		//system("cls");
		std::cout << "\n\nRetry???/Reincerci???\n1.Yes./Da.\n2.No./Nu.\n";
		op = _getch();
		if (op == '1')
			goto startG;
		else if (op == '2')
			return;
		else goto retry;

	}
	else if (op == '2')
		return;
	else { std::cout << "You have introduce wrong input./Ai introdus un input gresit."; Sleep(150); goto startG; }
	return;
}
int main()
{
	startGame();
	return 0;
}