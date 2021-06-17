#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>

/*														���� ������
*
*�������� �������, ������� ������� ����� �� ������� �� ������� ��������
������� ����� �� k , ��� k ��� ���� ����������, �� ������� ���������� ��������
���� ���� ����� 3 , �� ���������� ��������� , ABC ���������� �� DEF
	  A B C......Z
	  | | |.......\
A B C D E F....A B C
������ ��������� ������ , ����������� ���� � ������� ������������� ������
���� ����� ������ � ��������� �� 1 �� 94 , ��� ��� ����� 26 ���� � ��������� �������� , ���� ���� ����� ����� 0 ���
����� �������� , �� � ����� ����������� � �
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
	std::cout << "������� ���� ��� ���������� �� 1 �� 94: \n";
	int key = UserInput(1, 94); // ���� ��� ������ 
	std::cout << "������� ����� ��� ��������: \n";

	std::string textToCode = UserInputText();

	std::string res = CaesarCoder(key, textToCode);

	std::cout << "������������� ������: \n" << res;

	system("pause>null");
}
int GenRandomKey(int symbol){

	int correctKeyVernam = (rand() % 125) + 32;
	int message = symbol ^ correctKeyVernam;

	while(message < 32 || message >125) {
		correctKeyVernam = (rand() % 125) + 32;
		message = symbol ^ correctKeyVernam;
	}

	return correctKeyVernam;
}
std::string VernamCode(std::string message) {
	int len = message.length(); // ���������� ����� ������ 
	std::vector<int> key(len); //������ ������ � ����� ������ 
	for (int i = 0; i < len; i++)
	{
		key[i] = GenRandomKey(message[i]);
	}
	std::string resultString = ""; //�������������� ������ , ���������� ������
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
	std::cout << "������� �����: \n";
	std::string s = UserInputText();
	std::string messageKey = VernamCode(s);
	std::string message;
	std::string key;
	for (int i = 0; i < messageKey.length() / 2; i++)
	{
		message += messageKey[i];
	}
	std::cout << "������������� ������: \n" << message << "\n";
	for (int i = messageKey.length() / 2; i < messageKey.length(); i++)
	{
		key += messageKey[i];
	}
	std::cout << "���� ����������: \n" << key << "\n";
	system("pause>null");
}



void Vizhener() {
	std::cout << "������� ������ ��� ����������  \n";
	std::string key = UserInputText(); // ���� ��� ������ 
	std::string s;
	std::cout << "������� �����\n";
	std::cin >> s;
}