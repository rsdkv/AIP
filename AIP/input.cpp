/*В данном файле реализовываем функцию для принятия данных пользователя

*/
#include <iostream>
#include <string>
#include "output.h"
#include "input.h"
#include "submenuNavigator.h"
#include <vector>
/*Так как ключ должен быть числом в определённом диапазоне, то функция принимает на вход 2 параметра: min max значение для ключа

*/
int UserInput(int min, int max) {
	bool flag = false;
	std::string input; //ввод пользовтеля  
	while (!flag) {
		std::cin >> input;
		/*реализовываем try catch, с помощью которого проверяем корректный ввод пользовтеля
		если удаётся привести строку к инту, программа работает как и подразумевалось, иначе ,
		просим пользователя заново ввести корректные данные
		*/
		try
		{
			int correctInput = std::stoi(input); // пробуем приветси строку к инту с помощью 
			if (correctInput < min || correctInput > max) {
				throw std::exception();
			}
			return correctInput;
		}
		catch (const std::exception&) // ловим exception 
		{
			std::cout << "Введите корректные данные\n"; // просим заново ввести данные
		}
	}
}
/*Проверяем текст , который ввёл пользователь
* Введённый текст должен быть латиницей, так как от кирилицы я отказался, так как с ней не удобно работать в ASCII
 */
std::string UserInputText() {
	bool flag = false;
	std::string input; //ввод пользовтеля  
	getline(std::cin, input);
	while (!flag) {
		getline(std::cin, input);
		
		try
		{
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
			std::cout << "Введите корректный текст \n"; // просим заново ввести данные
		}
	}
}