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
void DeCaesar() {
	std::cout << "Введите ключ для дешифрования от 1 до 25: \n";
	int key = UserInput(1, 94); // ключ для сдвига 
	std::cout << "Введите текст для дешифровки: \n";
	std::string res = "";
	std::string textToDeCode = UserInputText();
	for (int i = 0; i < textToDeCode.length(); i++)
	{
		res += (char)(((((int)textToDeCode[i] + (94-key)) - 32) % 94) + 32);
	}
	std::cout << "Зашифрованная строка: \n" << res;

	system("pause>null");
}
void DeVernam(){
	std::string key;
	std::cout << "Введите ключ для дешифрования: \n";
	std::cin >> key;
	std::string s;
	std::cout << "Введите текст для дешифрования: \n";
	std::cin >> s;
	int len = key.length(); // запоминаем длину строки 
	//std::vector<int> key(len); //вектор длиной с длиной строки 
	/*for (int i = 0; i < len; i++)
	{
		key[i] = rand() % 255;
	}*/
	std::string resultString = ""; //расшифрованная  строка , изначально пустая
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)s[i] ^ (int)key[i]);
	}
	std::cout << "Зашифрованная строка: \n" << resultString << "\n";
	
	system("pause>null");
}
