#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>
/*														ШИФР ЦЕЗАРЯ
*
Смещает букву на k , где k это ключ шифрования, на который происходит смещение
Если ключ равен 3 , то происходит следующее , ABC заменяется на DEF
	  A B C......Z
	  | | |.......\
A B C D E F....A B C
функия принимает строку , запрашивает ключ и выводит зашифрованную строку
ключ может лежать в диапазоне от 1 до 25 , так как всего 26 букв в латинском алфавите
*/

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

void Caesar() {
	std::cout << "Введите ключ для шифрования\n";
	int key = UserInput(1, 25); // ключ для сдвига 
	std::string s;
	std::cout << "введите текст\n";
	std::cin >> s;
	//массивы символов английского алфаваита , для работы с самим алфавитом , чтобы не вылезали символы из ASCII
	std::vector<char> alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	std::vector<char> ALPHABET = { 'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	

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
	}
	std::cout << "Зашифрованный текст: \n" << s;
	system("pause>null");

}