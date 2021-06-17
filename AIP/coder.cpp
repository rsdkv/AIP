#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>

/*														ШИФР ЦЕЗАРЯ
*
*войдовая функция, которая шифрует текст со сдвигом по массиву алфавита
Смещает букву на k , где k это ключ шифрования, на который происходит смещение
Если ключ равен 3 , то происходит следующее , ABC заменяется на DEF
	  A B C......Z
	  | | |.......\
A B C D E F....A B C
функия принимает строку , запрашивает ключ и выводит зашифрованную строку
ключ может лежать в диапазоне от 1 до 94 , так как всего 26 букв в латинском алфавите , если ключ будет равен 0 или
длине алфавита , то А будет шифроваться в А
*/
std::string CaesarCoder(int key, std::string message) {
	std::string res = "";

	for (int i = 0; i < message.length(); i++)
	{
		res += (char)(((((int)message[i] + key) - 32) % 94) + 32);
	}
	return res;
}
void Caesar() {
	std::cout << "Введите ключ для шифрования от 1 до 94: \n";
	int key = UserInput(1, 94); // ключ для сдвига 
	std::cout << "Введите текст для шифровки: \n";

	std::string textToCode = UserInputText();

	std::string res = CaesarCoder(key, textToCode);

	std::cout << "Зашифрованная строка: \n" << res;

	system("pause>null");
}
int GenRandomKey(int symbol) {

	int correctKeyVernam = (rand() % 125) + 32;
	int message = symbol ^ correctKeyVernam;

	while (message < 32 || message >125) {
		correctKeyVernam = (rand() % 125) + 32;
		message = symbol ^ correctKeyVernam;
	}

	return correctKeyVernam;
}
std::string VernamCode(std::string message) {
	int len = message.length(); // запоминаем длину строки 
	std::vector<int> key(len); //вектор длиной с длину строки 
	for (int i = 0; i < len; i++)
	{
		key[i] = GenRandomKey(message[i]);
	}
	std::string resultString = ""; //закодированная строка , изначально пустая
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)message[i] ^ key[i]);
	}
	std::string keyString = "";
	for (int i = 0; i < len; i++)
	{
		keyString += (char)key[i];

	}
	return resultString + keyString;
}

void Vernam() {
	std::cout << "Введите текст: \n";
	std::string s = UserInputText();
	std::string messageKey = VernamCode(s);
	std::string message;
	std::string key;
	for (int i = 0; i < messageKey.length() / 2; i++)
	{
		message += messageKey[i];
	}
	std::cout << "Зашифрованная строка: \n" << message << "\n";
	for (int i = messageKey.length() / 2; i < messageKey.length(); i++)
	{
		key += messageKey[i];
	}
	std::cout << "Ключ шифрования: \n" << key << "\n";
	system("pause>null");
}


std::string VizhnerCode(std::string message, std::string key) {
	int lenAlphabet = 94;
	std::string resultString="";
	for (int i = 0; i < message.length(); i++)
	{
		resultString += (lenAlphabet + ((((message[i] + key[i % key.length()])-32)%94)+32) % lenAlphabet);
	}
	return resultString;
}
void Vizhner() {
	std::cout << "Введите ключ (любое слово) для шифрования: \n";
	std::string key = UserInputText();
	std::cout << "Введите текст для шифровки: \n";
	std::string message = UserInputText();
	std::cout << "Зашифрованная строка: \n" << VizhnerCode(message, key) << "\n";
	system("pause>null");
}