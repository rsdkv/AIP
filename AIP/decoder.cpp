#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>

/*														ДЕШИФР ЦЕЗАРЯ
*
Смещает букву на k , где k это ключ шифрования, на который происходит смещение
Если ключ равен 3 , то происходит следующее , ABC заменяется на DEF
	  A B C
	  | | |
A B C D E F
функия принимает строку , запрашивает ключ и выводит зашифрованную строку
ключ может лежать в диапазоне от 1 до 25 , так как всего 26 букв в латинском алфавите
*/

/// <summary>
/// Функция которая расшифровывает строку зашифрованную шифром цезаря по ключу
/// </summary>
/// <param name="key"> ключ для дешифровки </param>
/// <param name="message"> зашифрованное сообщение </param>
/// <returns> Расшифрованное сообшение </returns>
std::string CaesarDecoder(int key, std::string message) {
	// расшифрованная строка
	std::string res = "";
	
	// проходим циклом по строке и прибавляем к зашифрованному символу длинну алфавита - ключ 
	// и - 32) % 94) + 32 чтобы остаться в интервале нужного нам аски кода
	for (int i = 0; i < message.length(); i++)
	{
		res += (char)(((((int)message[i] + (94 - key)) - 32) % 94) + 32);
	}
	return res;
}

/// <summary>
/// Функция осуществляющая взаимолействия с пользователем
/// </summary>
void DeCaesar() {

	std::cout << "Введите ключ для дешифрования от 1 до 94: \n";

	// ключ для сдвига (от 1 до 94)
	int key = UserInput(1, 94); 

	std::cout << "Введите текст для дешифровки: \n";

	// Зашифрованный текст
	std::string textToDeCode = UserInputText();

	// Рашсифровка
	std::cout << "Зашифрованная строка: \n" << CaesarDecoder(key , textToDeCode);

	system("pause>null");
}

/// <summary>
/// Функция которая расшифровывает строку зашифрованную шифром Вернама по ключу
/// </summary>
/// <param name="key"> ключ для дешифровки </param>
/// <param name="message"> зашифрованное сообщение </param>
/// <returns> Расшифрованное сообшение </returns>
std::string VernamDecode(std::string message , std::string key) {

	// запоминаем длину строки 
	int len = key.length(); 

	//расшифрованная  строка , изначально пустая
	std::string resultString = ""; 

	// Проходим циклом по строке и ключу, переводим каждый символ в аски код, применяем XOR, 
	// результат переводим в символ и добавляем в расшифрованную строку
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)message[i] ^ (int)key[i]);
	}
	return resultString;
}

/// <summary>
/// Функция осуществляющая взаимолействия с пользователем
/// </summary>
void DeVernam(){

	std::cout << "Введите ключ для дешифрования: \n";

	// Ввод ключа
	std::string key = UserInputText();

	std::cout << "Введите текст для дешифрования: \n";

	// Ввод зашифрованной строки
	std::string s = UserInputText();

	// Расшифровка
	std::cout << "Зашифрованная строка: \n" << VernamDecode(s, key) << "\n";

	system("pause>null");
}

/// <summary>
/// Функция которая расшифровывает строку зашифрованную шифром Виженера по ключу
/// </summary>
/// <param name="key"> ключ для дешифровки </param>
/// <param name="message"> зашифрованное сообщение </param>
/// <returns> Расшифрованное сообшение </returns>
std::string VizhnerDecode(std::string message, std::string key) {

	// Расшифрованная строка, изначально пустая
	std::string resultString = "";
	
	// Проходим циклом по строке и 
	// Каждый символ строки приводим к аски коду,
	// вычитаем минимальный код (32)
	// прибавляем длинна алфавита - ключ для этого символа - 32
	// индекс ключа для конкретного символа мы берем как остаток от деления индекса символа на длину ключа
	//  % 94 + 32 чтобы остаться в интервале нашей аски таблицы
	for (int i = 0; i < message.length(); i++)
	{
		resultString += ((((int)message[i] - 32 + (94 - ((int)key[i % key.length()] - 32))) % 94) + 32);
	}
	return resultString;
}

/// <summary>
/// Функция осуществляющая взаимолействия с пользователем
/// </summary>
void DeVizhener() {

	std::cout << "Введите ключ (любое слово) для дешифрования: \n";

	// Считываем ключ
	std::string key = UserInputText();

	std::cout << "Введите текст для дешифровки: \n";

	// Считываем зашифрованное сообщение
	std::string message = UserInputText();

	// Рашифровываем
	std::cout << "Дешифрованная строка: \n" << VizhnerDecode(message, key) << "\n";
	system("pause>null");
}