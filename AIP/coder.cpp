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
/*														���� ������
*
*�������� �������, ������� ������� ����� �� ������� �� ������� �������� 
������� ����� �� k , ��� k ��� ���� ����������, �� ������� ���������� ��������
���� ���� ����� 3 , �� ���������� ��������� , ABC ���������� �� DEF
	  A B C......Z
	  | | |.......\
A B C D E F....A B C
������ ��������� ������ , ����������� ���� � ������� ������������� ������
���� ����� ������ � ��������� �� 1 �� 25 , ��� ��� ����� 26 ���� � ��������� �������� , ���� ���� ����� ����� 0 ��� 
����� �������� , �� � ����� ����������� � � 
*/
void Caesar() {
	std::cout << "������� ���� ��� ���������� �� 1 �� 25: \n";
	int key = UserInput(1, 25); // ���� ��� ������ 
	std::string s;
	std::cout << "������� �����\n";
	std::cin >> s;

	std::string res = "";
	for (int i = 0; i < s.length(); i++)
	{
		if ((int)s[i] > 125 || (int)s[i] < 32)
		{
			std::cout << "������� ���������� �����\n";
			break;
		}
		res += (char)(((int)s[i] + key) % 255);

	}
	//������� �������� ����������� ��������� , ��� ������ � ����� ��������� , ����� �� ������������ ��� ������ �� ASCII
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
	std::cout << "������������� �����: \n" << res;
	system("pause>null");
}


void Vernam() {
	std::string s;
	std::cout << "������� �����: \n";
	std::cin >> s;
	int len = s.length(); // ���������� ����� ������ 
	std::vector<int> key(len); //������ ������ � ������ ������ 
	for (int i = 0; i < len; i++)
	{
		key[i]=rand() % 255;
	}
	std::string resultString=""; //�������������� ������ , ���������� ������
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)s[i] ^ key[i]);
	}
	std::cout << "������������� ������: \n" << resultString << "\n";
	std::string keyString = "";
	for (int i = 0; i < len; i++)
	{
		keyString += (char)key[i];
		
	}
	std::cout <<"���� ����������: \n" << keyString << "\n";
	system("pause>null");
}
