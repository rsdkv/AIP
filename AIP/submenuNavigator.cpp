#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include "decoder.h"

void CoderMenu() {
	bool flag = false;
	while (flag == false) {
		PrintMenu(2);
		int userChoice = UserInput(1, 4);
		if (CoderMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}
}

void DecoderMenu() {
	bool flag = false;
	while (flag == false) {
		PrintMenu(3);
		int userChoice = UserInput(1, 4);
		if (DecoderMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}
}
void AllCoders() {
	bool flag = false;
	while (flag == false) {
		PrintMenu(4);
		int userChoice = UserInput(1, 4);
		if (DecoderMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}



bool MainMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		//меню шифрования текста 
		system("cls"); // очищаем меню
		CoderMenu();
		return false;
	case 2:
		system("cls"); // очищаем меню
		DecoderMenu();//меню дешифрования текста 
		return false;
	case 3:
		//меню шифров 
		return false;
	case 4:
		//выход
		return true;
	default:
		return false;
	}
}
bool CoderMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		//шифр цезаря 
		std::cout<< "Шифр Цезаря\n";
		system("cls"); // очищаем меню
		Caesar(); // вызываем шифр Цезаря 
		return false;
	case 2:
		system("cls"); // очищаем меню
		Vernam();
		return false;
	case 3:
		system("cls"); // очищаем меню
		//третий шифр 
		return false;;
	case 4:
		system("cls"); // очищаем меню
		//выход
		return true;
	default:
		return false;;
	}
}

bool DecoderMenuNavigator(int userChoice){
	switch (userChoice)
	{
	case 1:
		system("cls"); // очищаем меню
		DeCaesar(); //шифр цезаря 
		std::cout << "Шифр Цезаря\n";
		return false;
	case 2:
		system("cls"); // очищаем меню
		DeVernam();
		return false;
	case 3:
		system("cls"); // очищаем меню
		//третий шифр 
		return false;
	case 4:
		system("cls"); // очищаем меню
		//выход
		return true;
	default:
		return false;
	}
}
bool CipherMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		system("cls"); // очищаем меню
		//шифр цезаря 
		std::cout << "Шифр Цезаря\n";
		return false;
	case 2:
		system("cls"); // очищаем меню
		//второй шифр 
		return false;
	case 3:
		system("cls"); // очищаем меню
		//третий шифр 
		return false;
	case 4:
		system("cls"); // очищаем меню
		//выход
		return true;
	default:
		return false;
	}
}
