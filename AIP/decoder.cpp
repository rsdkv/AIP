#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>
/*������� , � ������� ������� �������� ������ ��� ������ 
��������� �� ���� 2 ��������� , ����� � �������� ������� �� ������� 
� ������� ������� 2 ������� : ������ � ������� ������� ���������� ��������, ����� �� ������������ �� ������� ASCII 
���������� ������ ��������
*/
int GetIndexForDecod(char symbol, bool isLower) {
	// ������ 2 ������� , ������ � ������� ������� ���������� ��������
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

/*														������ ������
*
������� ����� �� k , ��� k ��� ���� ����������, �� ������� ���������� ��������
���� ���� ����� 3 , �� ���������� ��������� , ABC ���������� �� DEF
	  A B C
	  | | |
A B C D E F
������ ��������� ������ , ����������� ���� � ������� ������������� ������
���� ����� ������ � ��������� �� 1 �� 25 , ��� ��� ����� 26 ���� � ��������� ��������
*/
void DeCaesar() {
	std::cout << "������� ���� ��� ������������ �� 1 �� 25: \n";
	int key = UserInput(1, 25); // ���� ��� ������
	std::string s;
	std::cout << "������� �����\n"; 
	std::cin >> s;
	std::vector<char> alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	std::vector<char> ALPHABET = { 'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < key; ++j) {
			if (s[i] == 'a') s[i] = 'z';
			else if (s[i] == 'A') s[i] = 'Z';
			else {
				bool low = std::islower(s[i]);
				int point = GetIndexForDecod(s[i], low);

				if (low)
				{
					s[i] = alphabet[point - 1];
				}
				else
				{
					s[i] = ALPHABET[point - 1];
				}
			}
		}
	}
	std::cout << "������������� �����: \n" << s;
	system("pause>null");

}
void DeVernam(){
	std::string key;
	std::cout << "������� ���� ��� ������������: \n";
	std::cin >> key;
	std::string s;
	std::cout << "������� ����� ��� ������������: \n";
	std::cin >> s;
	int len = key.length(); // ���������� ����� ������ 
	//std::vector<int> key(len); //������ ������ � ������ ������ 
	/*for (int i = 0; i < len; i++)
	{
		key[i] = rand() % 255;
	}*/
	std::string resultString = ""; //��������������  ������ , ���������� ������
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)s[i] ^ (int)key[i]);
	}
	std::cout << "������������� ������: \n" << resultString << "\n";
	
	system("pause>null");
}
