#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include "decoder.h"
#include "allcodersinfo.h"

/// <summary>
/// Функция осуществляющая вывод меню кодировок и обрабатывающая ввод пользователя
/// </summary>
void CoderMenu() {

	// Пока пользователь не нажал кнопку "выход"
	bool flag = false;
	while (flag == false) {

		// Печатаем меню
		PrintMenu(2);

		// Считывем ввод пользователя
		int userChoice = UserInput(1, 4);

		// Переходим туда, куда выбрал пользователь
		if (CoderMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}
}

/// <summary>
/// Функция осуществляющая вывод меню кодировок и обрабатывающая ввод пользователя
/// </summary>
void DecoderMenu() {

	// Пока пользователь не нажал кнопку "выход"
	bool flag = false;
	while (flag == false) {

		// Печатаем меню
		PrintMenu(3);

		// Считывем ввод пользователя
		int userChoice = UserInput(1, 4);

		// Переходим туда, куда выбрал пользователь
		if (DecoderMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}
}

/// <summary>
/// Функция осуществляющая вывод меню кодировок и обрабатывающая ввод пользователя
/// </summary>
void AllCoders() {

	// Пока пользователь не нажал кнопку "выход"
	bool flag = false;
	while (flag == false) {

		// Печатаем меню
		PrintMenu(4);

		// Считывем ввод пользователя
		int userChoice = UserInput(1, 4);

		// Переходим туда, куда выбрал пользователь
		if (CipherMenuNavigator(userChoice) == true) {
			flag = true;
		}
	}
}

/// <summary>
/// Функция обрабатывает ввод и вызывает нужную функцию в зависимости от аргумента
/// </summary>
/// <param name="userChoice"> Номер элемента меню, который выбрал пользователь </param>
/// <returns> True если пользователь нажал "Выход"</returns>
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
		system("cls"); // очищаем меню
		AllCoders(); //меню шифров 
		return false;
	case 4:
		//выход
		return true;
	default:
		return false;
	}
}

/// <summary>
/// Функция обрабатывает ввод и вызывает нужную функцию в зависимости от аргумента
/// </summary>
/// <param name="userChoice"> Номер элемента меню, который выбрал пользователь </param>
/// <returns> True если пользователь нажал "Выход"</returns>
bool CoderMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		//шифр цезаря
		system("cls"); // очищаем меню
		Caesar(); // вызываем шифр Цезаря 
		return false;
	case 2:
		// Шифр Вернама
		system("cls"); // очищаем меню
		Vernam();
		return false;
	case 3:
		// Шифр Виженера
		system("cls"); // очищаем меню
		Vizhner();
		return false;;
	case 4:
		system("cls"); // очищаем меню
		//выход
		return true;
	default:
		return false;;
	}
}

/// <summary>
/// Функция обрабатывает ввод и вызывает нужную функцию в зависимости от аргумента
/// </summary>
/// <param name="userChoice"> Номер элемента меню, который выбрал пользователь </param>
/// <returns> True если пользователь нажал "Выход"</returns>

bool DecoderMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		system("cls"); // очищаем меню
		DeCaesar(); //шифр цезаря 
		return false;
	case 2:
		system("cls"); // очищаем меню
		DeVernam(); // Шифр вернама
		return false;
	case 3:
		system("cls"); // очищаем меню
		DeVizhener(); // Шифр виженера
		return false;
	case 4:
		system("cls"); // очищаем меню
		//выход
		return true;
	default:
		return false;
	}
}

/// <summary>
/// Функция обрабатывает ввод и вызывает нужную функцию в зависимости от аргумента
/// </summary>
/// <param name="userChoice"> Номер элемента меню, который выбрал пользователь </param>
/// <returns> True если пользователь нажал "Выход"</returns>
bool CipherMenuNavigator(int userChoice) {
	switch (userChoice)
	{
	case 1:
		system("cls"); // очищаем меню
		//шифр цезаря 
		InfoAboutCaesar();
		return false;
	case 2:
		system("cls"); // очищаем меню
		//шифр Вернама 
		InfoAboutVernam();
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
