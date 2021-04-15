/*Мухин Николай
Задание 32
*/
#include<pch.h>
#include <iostream>
#include <string>
#include<ctime>
#include<Windows.h>
using namespace std;

class Cube {
public:
	int Throw() {//бросок кубика 20-грани
		Sleep(1000);
		srand(static_cast<unsigned int>(time(0)));
		int t = rand() % 20 + 1;
		return t;
	}

};

class Monster {
private:
	int Health;
	int Speed;
public:
	Monster() {};// Default construct
	Monster(int health, int speed) {
		if (health >= 0) {
			Health = health;
		}
		else {
			cout << "Health shouldn't has this value. Write new health: ";
			cin >> health;
		}
		if (speed >= 0) {
			Speed = speed;
		}
		else {
			cout << "Speed shouldn't has this value. Write new speed: ";
			cin >> speed;
		}

	}
	void Set_Health(int health) {
		if (health >= 0) {
			Health = health;
		}
		else {
			cout << "M:Health shouldn't has this value. Write new health: ";
			cin >> health;
		}
	}
	int Get_Health() {
		return Health;
	}
	int Get_Speed() {
		return Speed;
	}
};

class Hero {
private:
	int Health;
	int Speed;
public:
	Hero() {};// Default construct
	Hero(int health, int speed) {
		if (health >= 0) {
			Health = health;
		}
		else {
			cout << "Health shouldn't has this value. Write new health: ";
			cin >> health;
		}
		if (speed >= 0) {
			Speed = speed;
		}
		else {
			cout << "Speed shouldn't has this value. Write new speed: ";
			cin >> speed;
		}

	}
	void Set_Health(int health) {
		if (health >= 0) {
			Health = health;
		}
		else {
			cout << "H:Health shouldn't has this value. Write new health: ";
			cin >> health;
		}
	}

	int Get_Health() {
		return Health;
	}
	int Get_Speed() {
		return Speed;
	}
};

class Battle {
public:
	int Start_Battle(Hero* smb, Monster* smt) {
		int score = 0;
		int health;
		Cube* cubik = new Cube;
		int luck = 0;
		while (smt->Get_Health() > 0 && smb->Get_Health() > 0)
		{

			if (smt->Get_Speed() > smb->Get_Speed()) {
				int at = cubik->Throw();// Урон монстра

				if (at % 2 == 0 && smb->Get_Health() > 1) {
					health = smb->Get_Health();
					health = health - 2;
					smb->Set_Health(health);
				}
				else {
					health = smb->Get_Health();
					health = health - 1;
					smb->Set_Health(health);
				}
				cout << "Монстр атакует героя. Здоровье героя: " << smb->Get_Health() << endl;

				int ab = cubik->Throw();
				if (smb->Get_Health() > 0) {
					if (ab % 2 == 0 && smt->Get_Health() > 1) {
						health = smt->Get_Health();
						health = health - 2;
						smt->Set_Health(health);
						score = score + 2;
					}
					else {
						health = smt->Get_Health();
						health = health - 1;
						smt->Set_Health(health);
						score = score + 1;
					}
					cout << "Герой атакует монстра. Здоровье монстра: " << smt->Get_Health() << endl;
				}
			}

			else if (smb->Get_Speed() > smt->Get_Speed()) {
				int ab = cubik->Throw();
				if (ab % 2 == 0 && smt->Get_Health() > 1) {
					health = smt->Get_Health();
					health = health - 2;
					smt->Set_Health(health);
					score = score + 2;
				}
				else {
					health = smt->Get_Health();
					health = health - 1;
					smt->Set_Health(health);
					score = score + 1;
				}
				cout << "Герой атакует монстра. Здоровье монстра: " << smt->Get_Health() << endl;
				int at = cubik->Throw();// Урон монстра
				if (smt->Get_Health() > 0) {
					if (at % 2 == 0 && smb->Get_Health() > 1) {
						health = smb->Get_Health();
						health = health - 2;
						smb->Set_Health(health);
					}
					else {
						health = smb->Get_Health();
						health = health - 1;
						smb->Set_Health(health);
					}
					cout << "Монстр атакует героя. Здоровье героя: " << smb->Get_Health() << endl;
				}
			}

			else if (smb->Get_Speed() == smt->Get_Speed()) {
				luck = cubik->Throw();
				if (luck % 2 != 0) {
					int ab = cubik->Throw();
					if (ab % 2 == 0 && smt->Get_Health() > 1) {
						health = smt->Get_Health();
						health = health - 2;
						smt->Set_Health(health);
						score = score + 2;
					}
					else {
						health = smt->Get_Health();
						health = health - 1;
						smt->Set_Health(health);
						score = score + 1;
					}
					cout << "Герой атакует монстра. Здоровье монстра: " << smt->Get_Health() << endl;
					int at = cubik->Throw();// Урон монстра
					if (smt->Get_Health() > 0) {
						if (at % 2 == 0 && smb->Get_Health() > 1) {
							health = smb->Get_Health();
							health = health - 2;
							smb->Set_Health(health);
						}
						else {
							health = smb->Get_Health();
							health = health - 1;
							smb->Set_Health(health);
						}
						cout << "Монстр атакует героя. Здоровье героя: " << smb->Get_Health() << endl;
					}
				}
				else {
					int at = cubik->Throw();// Урон монстра

					if (at % 2 == 0 && smb->Get_Health() > 1) {
						health = smb->Get_Health();
						health = health - 2;
						smb->Set_Health(health);
					}
					else {
						health = smb->Get_Health();
						health = health - 1;
						smb->Set_Health(health);
					}
					cout << "Монстр атакует героя. Здоровье героя: " << smb->Get_Health() << endl;

					int ab = cubik->Throw();
					if (smb->Get_Health() > 0) {
						if (ab % 2 == 0 && smt->Get_Health() > 1) {
							health = smt->Get_Health();
							health = health - 2;
							smt->Set_Health(health);
							score = score + 2;
						}
						else {
							health = smt->Get_Health();
							health = health - 1;
							smt->Set_Health(health);
							score = score + 1;
						}
						cout << "Герой атакует монстра. Здоровье монстра: " << smt->Get_Health() << endl;
					}
				}
			}

		}
		return score;
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Cube* cubik = new Cube;
	Hero* somebody = new Hero(cubik->Throw(), cubik->Throw());


	bool t = true;
	int score = 0;// счёт героя определяется общим колличеством нанесённого врагам урона
	while (t) {
		string h1 = "", h2 = "", s1 = "", s2 = "";
		for (int i = 0; i < somebody->Get_Health(); i++) {
			h1 += "-";
		}
		for (int i = 0; i < somebody->Get_Speed(); i++) {
			s1 += "|";
		}
		cout << "Показатели героя:\n" << "Health: " << h1 << "(" << somebody->Get_Health() << ")\n" << "Speed: " << s1 << "(" << somebody->Get_Speed() << ")\n";

		Monster* something = new Monster(cubik->Throw(), cubik->Throw());
		for (int i = 0; i < something->Get_Health(); i++) {
			h2 += "-";
		}
		for (int i = 0; i < something->Get_Speed(); i++) {
			s2 += "|";
		}
		cout << "\nПоказатели монстра:\n" << "Health: " << h2 << "(" << something->Get_Health() << ")\n" << "Speed: " << s2 << "(" << something->Get_Speed() << ")\n";
		cout << "\nЧто сделать?\n1 - Вступить в бой с монстром \n2 - Убежать\n";
		int attack;
		cin >> attack;
		if (attack == 1) {
			Battle* mahach = new Battle;
			score = score + mahach->Start_Battle(somebody, something);
		}
		else
		{
			cout << "Побежали...\n\n";
		}



		if (somebody->Get_Health() <= 0) {
			cout << "   GAME OVER\n\n";
			cout << "SCORE: " << score << endl;
			t = false;
		}
		else if (somebody->Get_Health() > 0) {
			int end;
			cout << "SCORE: " << score << endl;
			cout << "Хотите закончить игру?\n1 - Да\n2 - Нет\n";
			cin >> end;
			if (end == 1) {
				t = false;
			}
			else {
				t = true;
			}
			
		}
		cout << "\n\n-------------------------------------------------\n\n";
	}
}
