/*В данном файле реализовываем функцию для принятия данных пользователя

*/
#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include <vector>


int UserInput(int min, int max) {

	// Флаг для выхода из цикла
	bool flag = false;

	//ввод пользовтеля
	std::string input;

	// Считываем то, что ввел пользователь, пока он не введет корректные данные
	while (!flag) {
		getline(std::cin, input);
		/*реализовываем try catch, с помощью которого проверяем корректный ввод пользовтеля
		если удаётся привести строку к целому числу, программа работает как и подразумевалось, иначе ,
		просим пользователя заново ввести корректные данные
		*/
		try
		{
			int correctInput = std::stoi(input); // пробуем приветси строку к инту с помощью stoi

			// Проверяем Введенное пользователем число на принадлежность нужному нам интервалу
			if (correctInput < min || correctInput > max) {
				throw std::exception();
			}
			return correctInput;
		}
		catch (const std::exception&) // ловим exception 
		{
			std::cout << "Enter the correct data: \n"; // просим заново ввести данные
		}
	}
}


std::string UserInputText() {

	// Флаг для выхода из цикла
	bool flag = false;

	//ввод пользовтеля
	std::string input;

	// Считываем то, что ввел пользователь, пока он не введет корректные данные
	while (!flag) {

		// Считываем что ввел пользователь
		getline(std::cin, input);

		/*реализовываем try catch, с помощью которого проверяем корректный ввод пользовтеля
		если строка содержит символы только из нужного диапазона, программа работает как и подразумевалось, иначе ,
		просим пользователя заново ввести корректные данные
		*/
		try
		{
			// Проходим циклом по строке и проверяем каждый символ приводя его к коду аски 
			for (int i = 0; i < input.length(); i++)
			{
				if ((int)input[i] > 125 || (int)input[i] < 32)
				{
					throw std::exception();
				}
			}
			return input;
		}
		catch (const std::exception&) // ловим exception 
		{
			std::cout << "Enter the correct text: \n"; // просим заново ввести данные
		}
	}
}
