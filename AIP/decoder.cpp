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
	int key = UserInput(1, 94); // ���� ��� ������ 
	std::cout << "������� ����� ��� ����������: \n";
	std::string res = "";
	std::string textToDeCode = UserInputText();
	for (int i = 0; i < textToDeCode.length(); i++)
	{
		res += (char)(((((int)textToDeCode[i] + (94-key)) - 32) % 94) + 32);
	}
	std::cout << "������������� ������: \n" << res;

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
