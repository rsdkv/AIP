#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include <vector>


std::vector<std::string> GetMenu(int xMenu) {

	// Главное меню
	std::vector<std::string> mainMenu = { " What do you want to do?\n"  , "Encrypt Text \n" , "Decrypt the text\n" ,
						"View all encryption algorithms \n" , " \n" };

	// Меню выбора метода шифрования
	std::vector<std::string> coderMenu = { "Select the encryption option \n"  , "Caesar's Cipher \n" , "Vernam Cipher \n" ,
						"Vigener Cipher\n" , "Exit \n" };

	// Меню выбора метода дешифровки
	std::vector<std::string> decoderMenu = { "Select the decryption option \n"  , " Caesar's Cipher \n" ,"Vernam Cipher \n",
						"Vigener Cipher\n" , "Exit \n" };

	// Меню выбора метода шифрования для показа информации о них
	std::vector<std::string> AllCodersMenu = { "Select the encryption you want to read about \n"  , "Caesar's Cipher \n" ,"Vernam Cipher \n",
						"Vigener Cipher\n" , "Exit \n" };

	// Возвращаем нужное нам меню
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

	// Массив строк меню
	std::vector<std::string> menuOutput = GetMenu(xMenu);

	// вывод заголовка меню
	std::cout << menuOutput[0];

	// Проходим циклом по каждому элементу меню и печатаем его номер и текст
	for (int i = 1; i < menuOutput.size(); i++)
	{
		std::cout << i << ") " << menuOutput[i];
	}
}

