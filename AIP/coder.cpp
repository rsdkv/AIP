#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>



std::string CaesarCoder(int key, std::string message) {
	// Зашифрованная строка, изначально пустая
	std::string res = "";

	// Проходим циклом по строке и шифруем ее сдвигом по аски таблице на ключ
	for (int i = 0; i < message.length(); i++)
	{
		/*приводим каждый символ к числу (код аски) прибавляем ключ затем чтобы не выйти за границы интервала символов 
		вычитам минимальное значение берем остаток от деления на длинну алфавита и прибавляем минимальное значение*/
		res += (char)(((((int)message[i] + key) - 32) % 94) + 32);
	}
	return res;
}


void Caesar() {

	std::cout << "Введите ключ для шифрования от 1 до 94: \n";
	int key = UserInput(1, 94); // ключ для сдвига 
	
	std::cout << "Введите текст для шифрования: \n";
	std::string textToCode = UserInputText(); // Текст для шифровки

	// шифруем текст
	std::string res = CaesarCoder(key, textToCode);

	std::cout << "Зашифрованная строка: \n" << res;

	system("pause>null");
}


int GenRandomKey(int symbol) {

	// Генерируем случайный ключ в диапазоне от 32 до 124
	int correctKeyVernam = (rand() % 125) + 32;

	// Применяем XOR для символа и ключа (пытаемся зашифровать)
	int message = symbol ^ correctKeyVernam;

	// если зашифрованный символ выходит за пределы - генерируем ключ заново
	while (message < 32 || message >125) {
		correctKeyVernam = (rand() % 125) + 32;
		message = symbol ^ correctKeyVernam;
	}

	return correctKeyVernam;
}


std::string VernamCode(std::string message) {
	int len = message.length(); // запоминаем длину строки 
	std::vector<int> key(len); //вектор длиной с длину строки 

	// Проходим циклом по строке и создаем случайный ключ для каждого символа
	for (int i = 0; i < len; i++)
	{
		key[i] = GenRandomKey(message[i]);
	}

	//закодированная строка , изначально пустая
	std::string resultString = ""; 

	// Проходим циклом по строке и шифруем каждый символ случайным ключом
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)message[i] ^ key[i]);
	}

	// Так как ключ генерируется случайно - его тоже переводим в строку
	std::string keyString = "";
	for (int i = 0; i < len; i++)
	{
		keyString += (char)key[i];

	}

	// длинна ключа равна длинне строки, возвращаем строку с ключом
	return resultString + keyString;
}

/// <summary>
/// Функция, которая производит взаимодействия с пользователем (вывод сообщений и ввод данных)
/// </summary>
void Vernam() {
	
	std::cout << "Введите текст для шифрования: \n";

	// Считываем строку для шифровки
	std::string s = UserInputText();

	// Кодируем ее
	std::string messageKey = VernamCode(s);

	// Объявляем переменные для извлечения ключа и зашифрованной строки
	std::string message;
	std::string key;

	// проходим циклом по строке, которую вернула функция VernamCode до середины - это будет зашифрованная строка
	for (int i = 0; i < messageKey.length() / 2; i++)
	{
		message += messageKey[i]; 
	}
	std::cout << "Зашифрованная строка: \n" << message << "\n";

	// проходим циклом по строке, которую вернула функция VernamCode с середины до конца - это будет ключ
	for (int i = messageKey.length() / 2; i < messageKey.length(); i++)
	{
		key += messageKey[i];
	}
	std::cout << "Ключ шифрования: \n" << key << "\n";
	system("pause>null");
}

std::string VizhnerCode(std::string message, std::string key) {
	std::string resultString="";
	for (int i = 0; i < message.length(); i++)
	{
		resultString += ((((int)message[i] - 32 + (int)key[i % key.length()] - 32) % 94 ) + 32 );
	}
	return resultString;
}


void Vizhner() {

	std::cout << "Введите ключ (любое слово) для шифрования: \n";

	// Вводим ключ для шифрования
	std::string key = UserInputText(); 

	std::cout << "Введите текст для шифрования: \n";

	// Вводим строку для шифрования
	std::string message = UserInputText();

	// Шифруем и выводим результат
	std::cout << "Зашифрованная строка: \n" << VizhnerCode(message, key) << "\n";
	system("pause>null");
}