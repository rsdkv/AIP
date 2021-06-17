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
std::string CaesarDecoder(int key, std::string message) {
	std::string res = "";
	
	for (int i = 0; i < message.length(); i++)
	{
		res += (char)(((((int)message[i] + (94 - key)) - 32) % 94) + 32);
	}
	return res;
}
void DeCaesar() {
	std::cout << "������� ���� ��� ������������ �� 1 �� 94: \n";
	int key = UserInput(1, 94); // ���� ��� ������ 
	std::cout << "������� ����� ��� ����������: \n";
	std::string textToDeCode = UserInputText();
	std::cout << "������������� ������: \n" << CaesarDecoder(key , textToDeCode);

	system("pause>null");
}
std::string VernamDecode(std::string message , std::string key) {
	int len = key.length(); // ���������� ����� ������ 
	std::string resultString = ""; //��������������  ������ , ���������� ������
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)message[i] ^ (int)key[i]);
	}
	return resultString;
}

void DeVernam(){
	std::cout << "������� ���� ��� ������������: \n";
	std::string key = UserInputText();
	std::cout << "������� ����� ��� ������������: \n";
	std::string s = UserInputText();
	std::cout << "������������� ������: \n" << VernamDecode(s, key) << "\n";
	system("pause>null");
}
