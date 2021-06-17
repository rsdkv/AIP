#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>
/*функция , с помощью которой получаем индекс для декода 
принимает на вход 2 параметра , букву и проверку символа на регистр 
в функции созданы 2 массива : нижний и верхний регистр латинского алфавита, чтобы не обрабатывать вс таблицу ASCII 
возвращаем индекс значения
*/
int GetIndexForDecod(char symbol, bool isLower) {
	// создаём 2 массива , нижний и верхний регистр латинского алфавита
	std::vector<char> alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	std::vector<char> ALPHABET = { 'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	if (isLower)
	{
		for (int i = 0; i < size(alphabet); i++)
		{
			if (symbol == alphabet[i])
			{
				return i;
			}
		}
	}
	else
	{
		for (int i = 0; i < size(ALPHABET); i++)
		{
			if (symbol == ALPHABET[i])
			{
				return i;
			}
		}
	}
}

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
std::string CaesarDecoder(int key, std::string message) {
	std::string res = "";
	
	for (int i = 0; i < message.length(); i++)
	{
		res += (char)(((((int)message[i] + (94 - key)) - 32) % 94) + 32);
	}
	return res;
}
void DeCaesar() {
	std::cout << "Введите ключ для дешифрования от 1 до 94: \n";
	int key = UserInput(1, 94); // ключ для сдвига 
	std::cout << "Введите текст для дешифровки: \n";
	std::string textToDeCode = UserInputText();
	std::cout << "Зашифрованная строка: \n" << CaesarDecoder(key , textToDeCode);

	system("pause>null");
}
std::string VernamDecode(std::string message , std::string key) {
	int len = key.length(); // запоминаем длину строки 
	std::string resultString = ""; //расшифрованная  строка , изначально пустая
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)message[i] ^ (int)key[i]);
	}
	return resultString;
}

void DeVernam(){
	std::cout << "Введите ключ для дешифрования: \n";
	std::string key = UserInputText();
	std::cout << "Введите текст для дешифрования: \n";
	std::string s = UserInputText();
	std::cout << "Зашифрованная строка: \n" << VernamDecode(s, key) << "\n";
	system("pause>null");
}
