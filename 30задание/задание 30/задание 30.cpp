/*Мухин Николай
219\5
Задание 30
Написать программу, в которой будут описаны следующие классы:
•	1 родительский абстрактный класс(напр. Animal) с 2 виртуальными методами, переопределенными в 2 дочерних(напр. Методы makeASound в класах cat, dog)
•	1 ненаследуемый класс
Продемонстрировать работу программы. Не использовать классы, указанные в кач. примера.

*/
#include "pch.h"
#include <iostream>
#include<string>
#include <ctime>
#include<Windows.h>

using namespace std;

/*class animal {
public:
	virtual void makesound() {
		cout << "";
	}
};*/

class Character {
public: // Задаю основные поля и функции для класса
	int Energy;
	int MaxDammage;
	int Health;
	virtual int attack(int dammage) {
		bool t = true;
		while (t) {
			if (dammage <= MaxDammage && dammage <= Energy && dammage >= 0) {
				Energy = Energy - dammage;
				t = false;
			}

			else {
				cout << "C: You can\'t attack with this dammage. Write new dammage:";
				int d;
				cin >> d;
				dammage = d;
				t = true;
			}
		}
		return Energy;

	}
	virtual int Hurt(int dammage) {

		Health = Health - dammage;
		if (Health < 0) {
			Health = 0;
		}


		return Health;
	}

};

class Ork : public Character {
public:
	int attack(int dammage) override {// Перезаписываю метод родительского класса
		bool t = true;
		while (t) {
			if (dammage - 2 <= MaxDammage && dammage - 2 <= Energy && dammage >= 0) {
				if (dammage <= 2) {
					Energy = Energy - 1;// Если урон меньше колличества энергии "разности", то отнимается 1 ед энергии
				}
				else {
					Energy = Energy - dammage + 2;// Орки тратят на 2 меньше энергии, чем обычный показатель
				}

				t = false;

			}
			else {
				cout << "O: You can\'t attack with this dammage. Write new dammage:";
				cin >> dammage;
				t = true;
			}
		}
		return Energy;
	}
	int Hurt(int dammage) override {// Перезаписываю метод родительского класса
		if (dammage != 0) {
			Health = Health - dammage + 1;// Орки получают урон на 1 меньше чем обычный показатель
		}
		else {
			Health = Health - dammage;
		}
		if (Health < 0) {
			Health = 0;
		}


		return Health;

	}
};
class Human : public Character {
public:
	int attack(int dammage) override {// Перезаписываю метод родительского класса
		bool t = true;
		while (t) {
			if (dammage - 1 <= MaxDammage && dammage - 1 <= Energy && dammage >= 0) {
				if (dammage <= 1) {
					Energy = Energy - 1;// Если урон меньше колличества энергии "разности", то отнимается 1 ед энергии
				}
				else {
					Energy = Energy - dammage + 1;// Люди тратят на 1 меньше енергии, чем обычный показатель
				}
				t = false;
			}
			else {
				cout << "H: You can\'t attack with this dammage. Write new dammage:";
				cin >> dammage;
				t = true;
			}
		}
		return Energy;
	}
	// Метод Health остаётся таким же как и в родительском

};

class Fish final {// Ненаследуемый класс
	float weight;
	float length;
	string name;
	string area;// Зона обитания
public:
	void Set_Weight(float Weight) {
		bool t = true;
		while (t) {
			if (Weight > 0) {
				weight = Weight;
				t = false;
			}
			else {
				t = true;
				cout << "Weight should be more then 0. Write lenght yet: ";
				cin >> Weight;
			}

		}
	};
	void Set_Lenght(float Length) {
		bool t = true;
		while (t) {
			if (Length > 0) {
				length = Length;
				t = false;
			}
			else {
				t = true;
				cout << "Length should be more then 0. Write lenght yet: ";
				cin >> Length;

			}

		}
	};
	void Set_Name(string Name) {
		name = Name;
	};
	void Set_Area(string Area) {
		area = Area;
	};

	float Get_Weight() {
		return weight;
	};
	float Get_Lenght() {
		return length;
	};
	string Get_Name() {
		return name;
	};
	string Get_Area() {
		return area;
	};

};

//class Shark : public Fish {


//};
/*class cat:public animal {
public:
	 void makesound()  override {
		cout << "";
	}
};*/

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	Character Main_Hero;
	Main_Hero.Health = 10;
	Main_Hero.Energy = 10;
	Main_Hero.MaxDammage = 10;

	Ork Orks[5];
	Human Humans[6];
	for (int i = 0; i < 5; i++) {
		Orks[i].Health = 7;
		Orks[i].Energy = 6;
		Orks[i].MaxDammage = 8;


	}
	for (int i = 0; i < 6; i++) {
		Humans[i].Health = 5;
		Humans[i].Energy = 5;
		Humans[i].MaxDammage = 6;
	}
	srand(static_cast<unsigned int>(time(0)));
	bool t = true;
	while (t) {
		cout << "================================================\n";
		cout << "| Показатели Орков| "; cout << "Максимальный урон: " << Orks[1].MaxDammage << "       |" << endl;
		cout << "================================================\n|                                              |\n";

		for (int i = 0; i < 5; i++) {
			cout << "|  Орк №" << i + 1 << " ~ ";
			string health = "";
			for (int j = 0; j < Orks[i].Health; j++) {
				health += "-";
			}
			if (Orks[i].Health < 7) {
				for (int p = 0; p < (7 - Orks[i].Health); p++) {
					health += " ";
				}
			}
			cout << "Health:" << health << "   ";
			string energy = "";
			for (int k = 0; k < Orks[i].Energy; k++) {
				energy += "|";
			}

			for (int o = 0; o < (6 - Orks[i].Energy); o++) {
				energy += " ";
			}

			cout << "Energy: " << energy << "    |";
			cout << endl;


		}
		cout << "================================================";
		cout << endl << endl;
		cout << "=================================================\n";
		cout << "| Показатели людей| "; cout << "Максимальный урон: " << Humans[0].MaxDammage << "        |\n";
		cout << "=================================================\n|                                               |\n";
		for (int i = 0; i < 6; i++) {
			cout << "|  Солдат №" << i + 1 << " ~ ";
			string health = "";
			for (int j = 0; j < Humans[i].Health; j++) {
				health += "-";
			}
			if (Humans[i].Health < 5) {
				for (int p = 0; p < (5 - Humans[i].Health); p++) {
					health += " ";
				}
			}
			cout << "Health:" << health << "   ";
			string energy = "";
			for (int k = 0; k < Humans[i].Energy; k++) {
				energy += "|";
			}
			if (Humans[i].Energy < 5) {
				for (int o = 0; o < (5 - Humans[i].Energy); o++) {
					energy += " ";
				}
			}
			cout << "Energy: " << energy << "     |";
			cout << endl;
		}
		cout << "=================================================";
		cout << endl << endl;
		cout << "===================================================================\n";
		cout << "| Главный герой " << " Health: " << Main_Hero.Health << "   Energy: " << Main_Hero.Energy << "   Максимальный урон: " << Main_Hero.MaxDammage << endl;
		cout << "===================================================================\n\n";
		int RH = rand() % 6;
		int RO = rand() % 5;
		if (Main_Hero.Health != 0) {
			cout << "Введите номер врага, которого вы атакуете: ";
			bool y = true;
			cin >> RO;
			while (y) {
				if (RO <= 5 && RO >= 1) {
					y = false;

				}
				else {
					cout << "Врага с таким номером нет. Введите номер повторно: ";
					cin >> RO;
					y = true;
				}
				if (Orks[RO - 1].Health == 0) {
					cout << "Враг уже мёртв. Введите номер повторно: ";
					cin >> RO;
					y = true;
				}

			}

			RO = RO - 1;
			cout << "Ваша атака: ";
			int Attack_G;
			cin >> Attack_G;
			Main_Hero.attack(Attack_G);
			Orks[RO].Hurt(Attack_G);
		}
		else {
			cout << "Главный герой мёртв.\n";
			system("pause");
		}
		if (Humans[RH].Health == 0) {// Проверка состояния здоровья человека для выбора
			if ((Humans[0].Health == 0) && (Humans[1].Health == 0) && (Humans[2].Health == 0) && (Humans[3].Health == 0) && (Humans[4].Health == 0) && (Humans[5].Health == 0)) {

			}
			else {
				while (Humans[RH].Health == 0) {
					RH = rand() % 6;
				}
			}
		}

		int Attack_H = rand() % 6 + 1;
		int Attack_O = rand() % 8 + 1;

		bool b = true;
		while (b) {// Генерирование атаки человека
			if (Attack_H <= 6 && Attack_H <= Humans[RH].Energy + 1) {
				b = false;
			}
			else {

				Attack_H = rand() % 6 + 1;
				b = true;
			}
		}
		RO = rand() % 5;

		if (Orks[RO].Health == 0) {// Проверка состояния здоровья орка для выбора
			if (Orks[0].Health == 0 && Orks[1].Health == 0 && Orks[2].Health == 0 && Orks[3].Health == 0 && Orks[4].Health == 0) {

			}
			else {
				while (Orks[RO].Health == 0) {
					RO = rand() % 5;
				}
			}
		}

		int E = Humans[RH].Energy;
		Humans[RH].attack(Attack_H);//Атака человека

		Orks[RO].Hurt(Attack_H);//Повреждение орка

		cout << "\n- Солдат №" << RH + 1 << " нанёс урон " << Attack_H << " орку №" << RO + 1 << endl;
		cout << "\n- Солдат №" << RH + 1 << " потерял енергии " << E - Humans[RH].Energy << endl;
		cout << "\n- Орк №" << RO + 1 << " получил урон " << Attack_H - 1 << endl;

		RO = rand() % 5;

		if (Orks[RO].Health == 0) {// Проверка состояния здоровья орка для выбора
			if (Orks[0].Health == 0 && Orks[1].Health == 0 && Orks[2].Health == 0 && Orks[3].Health == 0 && Orks[4].Health == 0) {

			}
			else {
				while (Orks[RO].Health == 0) {
					RO = rand() % 5;
				}
			}

		}
		b = true;


		while (b) {// Генерирование атаки орка
			if (Attack_O <= 8 && Attack_O <= Orks[RO].Energy + 2) {

				b = false;
			}
			else {
				Attack_O = rand() % 8 + 1;

				b = true;
			}
		}
		int EA = Orks[RO].Energy;
		Orks[RO].attack(Attack_O);// Атака орка

		RH = rand() % 6;


		if (Humans[RH].Health == 0) {// Проверка состояния здоровья человека для выбора
			if ((Humans[0].Health == 0) && (Humans[1].Health == 0) && (Humans[2].Health == 0) && (Humans[3].Health == 0) && (Humans[4].Health == 0) && (Humans[5].Health == 0)) {

			}
			else {
				while (Humans[RH].Health == 0) {
					RH = rand() % 6;
				}
			}
		}


		int RG = rand() % 7;
		if (RG < 3 && Main_Hero.Health != 0) {
			Main_Hero.Hurt(Attack_O);
			cout << "\n- Орк №" << RO + 1 << " нанёс урон " << Attack_O << " Главному герою\n";
			if (Attack_O <= 2) {
				Attack_O = 1;
			}
			cout << "\n- Орк №" << RO + 1 << " потерял енергии " << EA - Orks[RO].Energy << endl << endl;
		}
		else {
			Humans[RH].Hurt(Attack_O);//Повреждение человека
			cout << "\n- Орк №" << RO + 1 << " нанёс урон " << Attack_O << " солдату №" << RH + 1 << endl;
			if (Attack_O <= 2) {
				Attack_O = 1;
			}
			cout << "\n- Орк №" << RO + 1 << " потерял енергии " << EA - Orks[RO].Energy << endl << endl;
		}

		for (int i = 0; i < 5; i++) {// Обнуление енергии присмерти
			if (Orks[i].Health == 0) {
				Orks[i].Energy = 0;
			}
			if (Orks[i].Energy < 0) {
				Orks[i].Energy = 0;
			}
		}

		if (Main_Hero.Health == 0) {// Обнуление енергии при смерти
			Main_Hero.Energy = 0;
		}

		for (int i = 0; i < 6; i++) {// Обнуление енергии при смерти
			if (Humans[i].Health == 0) {
				Humans[i].Energy = 0;
			}
			if (Humans[i].Energy < 0) {
				Humans[i].Energy = 0;

			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Второй вывод
		cout << "================================================\n";
		cout << "| Показатели Орков| "; cout << "Максимальный урон: " << Orks[1].MaxDammage << "       |" << endl;
		cout << "================================================\n|                                              |\n";

		for (int i = 0; i < 5; i++) {
			cout << "|  Орк №" << i + 1 << " ~ ";
			string health = "";
			for (int j = 0; j < Orks[i].Health; j++) {
				health += "-";
			}
			if (Orks[i].Health < 7) {
				for (int p = 0; p < (7 - Orks[i].Health); p++) {
					health += " ";
				}
			}
			cout << "Health:" << health << "   ";
			string energy = "";
			for (int k = 0; k < Orks[i].Energy; k++) {
				energy += "|";
			}

			for (int o = 0; o < (6 - Orks[i].Energy); o++) {
				energy += " ";
			}

			cout << "Energy: " << energy << "    |";
			cout << endl;


		}
		cout << "================================================";
		cout << endl << endl;
		cout << "=================================================\n";
		cout << "| Показатели людей| "; cout << "Максимальный урон: " << Humans[0].MaxDammage << "        |\n";
		cout << "=================================================\n|                                               |\n";
		for (int i = 0; i < 6; i++) {
			cout << "|  Солдат №" << i + 1 << " ~ ";
			string health = "";
			for (int j = 0; j < Humans[i].Health; j++) {
				health += "-";
			}
			if (Humans[i].Health < 5) {
				for (int p = 0; p < (5 - Humans[i].Health); p++) {
					health += " ";
				}
			}
			cout << "Health:" << health << "   ";
			string energy = "";
			for (int k = 0; k < Humans[i].Energy; k++) {
				energy += "|";
			}
			if (Humans[i].Energy < 5) {
				for (int o = 0; o < (5 - Humans[i].Energy); o++) {
					energy += " ";
				}
			}
			cout << "Energy: " << energy << "     |";
			cout << endl;
		}
		cout << "=================================================";
		cout << endl << endl;
		cout << "===================================================================\n";
		cout << "| Главный герой " << " Health: " << Main_Hero.Health << "   Energy: " << Main_Hero.Energy << "   Максимальный урон: " << Main_Hero.MaxDammage << endl;
		cout << "===================================================================\n\n";

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Второй вывод



		system("pause");

		if (Main_Hero.Energy < 10 && Main_Hero.Health != 0) {
			Main_Hero.Energy = Main_Hero.Energy + 1;
		}

		for (int i = 0; i < 5; i++) {
			if (Orks[i].Energy < 5 && Orks[i].Health != 0) {
				Orks[i].Energy = Orks[i].Energy + 1;
			}
		}

		for (int i = 0; i < 6; i++) {
			if (Humans[i].Energy < 5) {
				Humans[i].Energy = Humans[i].Energy + 1;

			}
			if (Humans[i].Health == 0) {
				Humans[i].Energy = 0;
			}
			if (Humans[i].Energy < 0) {
				Humans[i].Energy = 0;

			}
		}

		system("cls");
		if (Orks[0].Health == 0 && Orks[1].Health == 0 && Orks[2].Health == 0 && Orks[3].Health == 0 && Orks[4].Health == 0) {
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n                                 You Won!";
			cout << "\n\n\n\n\n\n\n\n\n\n\n";
			system("pause");
			t = false;

		}
		else {
			t = true;
		}

		if ((Humans[0].Health == 0) && (Humans[1].Health == 0) && (Humans[2].Health == 0) && (Humans[3].Health == 0) && (Humans[4].Health == 0) && (Humans[5].Health == 0) && Main_Hero.Health == 0) {
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n                                 You Lose!";
			cout << "\n\n\n\n\n\n\n\n\n\n\n";
			system("pause");
			t = false;

		}
		else {
			t = true;
		}
	};






	return 0;
}
