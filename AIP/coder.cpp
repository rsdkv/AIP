#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>

int GetIndex(char symbol, bool isLower) {
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
/*														ШИФР ЦЕЗАРЯ
*
*войдовая функция, которая шифрует текст со сдвигом по массиву алфавита 
Смещает букву на k , где k это ключ шифрования, на который происходит смещение
Если ключ равен 3 , то происходит следующее , ABC заменяется на DEF
	  A B C......Z
	  | | |.......\
A B C D E F....A B C
функия принимает строку , запрашивает ключ и выводит зашифрованную строку
ключ может лежать в диапазоне от 1 до 25 , так как всего 26 букв в латинском алфавите , если ключ будет равен 0 или 
длине алфавита , то А будет шифроваться в А 
*/
void Caesar() {
	std::cout << "Введите ключ для шифрования от 1 до 25: \n";
	int key = UserInput(1, 25); // ключ для сдвига 
	std::string s;
	std::cout << "введите текст\n";
	std::cin >> s;

	std::string res = "";
	for (int i = 0; i < s.length(); i++)
	{
		if ((int)s[i] > 125 || (int)s[i] < 32)
		{
			std::cout << "введите корректный текст\n";
			break;
		}
		res += (char)(((int)s[i] + key) % 255);

	}
	//массивы символов английского алфаваита , для работы с самим алфавитом , чтобы не обрабытывать все сиволы из ASCII
	/*std::vector<char> alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	std::vector<char> ALPHABET = { 'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	std::vector<char> cipher
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < key; ++j) {
			if (s[i] == 'z') {
				s[i] = 'a';
			}
			else if (s[i] == 'Z') {
				s[i] = 'A';
			}
			else { 
				bool low = std::islower(s[i]);
				int point = GetIndex(s[i], low);
				
				if (low)
				{
					s[i] = alphabet[point + 1];
				}
				else
				{
					s[i] = ALPHABET[point + 1];
				}
			}
		}
	}*/
	std::cout << "Зашифрованный текст: \n" << res;
	system("pause>null");
}


void Vernam() {
	std::string s;
	std::cout << "Введите текст: \n";
	std::cin >> s;
	int len = s.length(); // запоминаем длину строки 
	std::vector<int> key(len); //вектор длиной с длиной строки 
	for (int i = 0; i < len; i++)
	{
		key[i]=rand() % 255;
	}
	std::string resultString=""; //закодированная строка , изначально пустая
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)s[i] ^ key[i]);
	}
	std::cout << "Зашифрованная строка: \n" << resultString << "\n";
	std::string keyString = "";
	for (int i = 0; i < len; i++)
	{
		keyString += (char)key[i];
		
	}
	std::cout <<"Ключ шифрования: \n" << keyString << "\n";
	system("pause>null");
}
