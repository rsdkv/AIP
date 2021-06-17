﻿#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>


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


void DeCaesar() {

	std::cout << "Enter the decryption key from 1 to 94: \n";

	// ключ для сдвига (от 1 до 94)
	int key = UserInput(1, 94); 

	std::cout << "Enter the decryption text: \n";

	// Зашифрованный текст
	std::string textToDeCode = UserInputText();

	// Рашсифровка
	std::cout << "The encrypted string: \n" << CaesarDecoder(key , textToDeCode);

	system("pause>null");
}


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


void DeVernam(){

	std::cout << "Enter the decryption key: \n";

	// Ввод ключа
	std::string key = UserInputText();

	std::cout << "Enter the decryption text: \n";

	// Ввод зашифрованной строки
	std::string s = UserInputText();

	// Расшифровка
	std::cout << "The encrypted string: \n" << VernamDecode(s, key) << "\n";

	system("pause>null");
}

std::string VizhnerDecode(std::string message, std::string key) {

	// Расшифрованная строка, изначально пустая
	std::string resultString = "";
	
	/**
	*Проходим циклом по строке и 
	*Каждый символ строки приводим к аски коду,
	*вычитаем минимальный код (32)
	*прибавляем длинна алфавита - ключ для этого символа - 32
	*индекс ключа для конкретного символа мы берем как остаток от деления индекса символа на длину ключа
	*% 94 + 32 чтобы остаться в интервале нашей аски таблицы
	*/
	for (int i = 0; i < message.length(); i++)
	{
		resultString += ((((int)message[i] - 32 + (94 - ((int)key[i % key.length()] - 32))) % 94) + 32);
	}
	return resultString;
}


void DeVizhener() {

	std::cout << "Enter the decryption key (word) : \n";

	// Считываем ключ
	std::string key = UserInputText();

	std::cout << "Enter the decryption text: \n";

	// Считываем зашифрованное сообщение
	std::string message = UserInputText();

	// Рашифровываем
	std::cout << "The decrypted string: \n" << VizhnerDecode(message, key) << "\n";
	system("pause>null");
}