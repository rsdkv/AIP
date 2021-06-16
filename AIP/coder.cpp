#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>
/*														���� ������
*
������� ����� �� k , ��� k ��� ���� ����������, �� ������� ���������� ��������
���� ���� ����� 3 , �� ���������� ��������� , ABC ���������� �� DEF
	  A B C......Z
	  | | |.......\
A B C D E F....A B C
������ ��������� ������ , ����������� ���� � ������� ������������� ������
���� ����� ������ � ��������� �� 1 �� 25 , ��� ��� ����� 26 ���� � ��������� ��������
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
	std::cout << "������� ���� ��� ����������\n";
	int key = UserInput(1, 25); // ���� ��� ������ 
	std::string s;
	std::cout << "������� �����\n";
	std::cin >> s;
	//������� �������� ����������� ��������� , ��� ������ � ����� ��������� , ����� �� �������� ������� �� ASCII
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
	std::cout << "������������� �����: \n" << s;
	system("pause>null");

}