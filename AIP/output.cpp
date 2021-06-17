#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include <vector>

std::vector<std::string> GetMenu(int xMenu) {
	std::vector<std::string> mainMenu = { "Что вы хотите сделать?\n"  , "Зашифровать текст\n" , "Расшифровать текст\n" ,
						"Посмотреть все варианты шифровок\n" , "Выход\n" };
	std::vector<std::string> coderMenu = { "Выберите вариант шифрования \n"  , "Шифр Цезаря \n" , "Шифр Вернама \n" ,
						"Шифр Вижнера\n" , "Выход\n" };
	std::vector<std::string> decoderMenu = { "Выберите вариант дешифрования \n"  , "Шифр Цезаря \n" ,"Шифр Вернама \n",
						"Шифр Вижнера\n" , "Выход\n" };
	std::vector<std::string> AllCodersMenu = { "Выберите шифрование о котором хотите прочитать \n"  , "Шифр Цезаря \n" ,"Шифр Вернама \n",
						"Шифр Вижнера\n" , "Выход\n" };
	switch (xMenu)
	{
	case 1:
		system("cls"); // очищаем меню
		return mainMenu;
	case 2:
		system("cls"); // очищаем меню
		return coderMenu;
	case 3:
		system("cls"); // очищаем меню
		return decoderMenu;
	case 4:
		system("cls"); // очищаем меню
		return AllCodersMenu;
	default:
		system("cls"); // очищаем меню
		return mainMenu;
	}

}

void PrintMenu(int xMenu) {

	std::vector<std::string> menuOutput = GetMenu(xMenu);

	std::cout << menuOutput[0];
	for (int i = 1; i < menuOutput.size(); i++)
	{
		std::cout << i << ") " << menuOutput[i];
	}
}
/*Возвращает массив меню по числу , передаём число 
* 
*/
