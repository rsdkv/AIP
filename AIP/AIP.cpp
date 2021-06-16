/*Консольное приложение , которое умеет шифровать и дешифровать текст по выбранному алгоритму с выбранными ключами
Есть меню по которому можно перемещаться 
все функции вынесены в отдельные файлы, по названию файла понятно, что реализовано в файле 
в файлах *.h объявлена функция , в файлах *.cpp реализована, 
если нужна функция из *.сpp , то подключаем файл *.h 

*/
#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	/* печатаем меню , которое получаем из функции GetMenu
	*/
	bool flag = false;
	while (flag == false) {
		PrintMenu(1);
		int userChoice = UserInput(1, 4);
		if (MainMenuNavigator(userChoice) == true) {
			flag = true; 
		}
	}
	system("pause");// не позв
	return 0;
}
