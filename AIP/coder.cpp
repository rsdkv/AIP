#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>

/*														���� ������
*�������� �������, ������� ������� ����� �� ������� �� ������� ��������
������� ����� �� k , ��� k ��� ���� ����������, �� ������� ���������� ��������
���� ���� ����� 3 , �� ���������� ��������� , ABC ���������� �� DEF
	  A B C......Z
	  | | |.......\
A B C D E F....A B C
������ ��������� ������ , ����������� ���� � ������� ������������� ������
���� ����� ������ � ��������� �� 1 �� 94 , ��� ��� ����� 26 ���� � ��������� �������� (��������� � ��������) + ����� � ��������� �������, ���� ���� ����� ����� 0 ���
����� �������� , �� � ����� ����������� � �
*/

/// <summary>
/// ������� ���������� ������ � ������� ����� ������
/// </summary>
/// <param name="key"> ���� </param>
/// <param name="message"> ������ ��� ���������� </param>
/// <returns> ���������� ������������� ������ </returns>
std::string CaesarCoder(int key, std::string message) {
	// ������������� ������, ���������� ������
	std::string res = "";

	// �������� ������ �� ������ � ������� �� ������� �� ���� ������� �� ����
	for (int i = 0; i < message.length(); i++)
	{
		/*�������� ������ ������ � ����� (��� ����) ���������� ���� ����� ����� �� ����� �� ������� ��������� �������� 
		������� ����������� �������� ����� ������� �� ������� �� ������ �������� � ���������� ����������� ��������*/
		res += (char)(((((int)message[i] + key) - 32) % 94) + 32);
	}
	return res;
}

/// <summary>
/// �������, ������� ���������� �������������� � ������������� (����� ��������� � ���� ������)
/// </summary>
void Caesar() {

	std::cout << "������� ���� ��� ���������� �� 1 �� 94: \n";
	int key = UserInput(1, 94); // ���� ��� ������ 
	
	std::cout << "������� ����� ��� ����������: \n";
	std::string textToCode = UserInputText(); // ����� ��� ��������

	// ������� �����
	std::string res = CaesarCoder(key, textToCode);

	std::cout << "������������� ������: \n" << res;

	system("pause>null");
}
/*														���� �������
* XOR-���� , ������� �������� �� �������� ��������������� ������ �� ������� ��������� 
*/

/// <summary>
/// ��������������� ������� ��� ������������� ���������� ����� � �������� �����
/// </summary>
/// <param name="symbol"> ���� ��� ������� �� ������ ������� ���� ����������� </param>
/// <returns> ���������� ��������� ���� </returns>
int GenRandomKey(int symbol) {

	// ���������� ��������� ���� � ��������� �� 32 �� 124
	int correctKeyVernam = (rand() % 125) + 32;

	// ��������� XOR ��� ������� � ����� (�������� �����������)
	int message = symbol ^ correctKeyVernam;

	// ���� ������������� ������ ������� �� ������� - ���������� ���� ������
	while (message < 32 || message >125) {
		correctKeyVernam = (rand() % 125) + 32;
		message = symbol ^ correctKeyVernam;
	}

	return correctKeyVernam;
}

/// <summary>
/// ������� ���������� ������ � ������� ����� �������
/// </summary>
/// <param name="message"> ������ ��� ���������� </param>
/// <returns> ���������� ������������� ������ ����������� � ������ </returns>
std::string VernamCode(std::string message) {
	int len = message.length(); // ���������� ����� ������ 
	std::vector<int> key(len); //������ ������ � ����� ������ 

	// �������� ������ �� ������ � ������� ��������� ���� ��� ������� �������
	for (int i = 0; i < len; i++)
	{
		key[i] = GenRandomKey(message[i]);
	}

	//�������������� ������ , ���������� ������
	std::string resultString = ""; 

	// �������� ������ �� ������ � ������� ������ ������ ��������� ������
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)message[i] ^ key[i]);
	}

	// ��� ��� ���� ������������ �������� - ��� ���� ��������� � ������
	std::string keyString = "";
	for (int i = 0; i < len; i++)
	{
		keyString += (char)key[i];

	}

	// ������ ����� ����� ������ ������, ���������� ������ � ������
	return resultString + keyString;
}

/// <summary>
/// �������, ������� ���������� �������������� � ������������� (����� ��������� � ���� ������)
/// </summary>
void Vernam() {
	
	std::cout << "������� ����� ��� ����������: \n";

	// ��������� ������ ��� ��������
	std::string s = UserInputText();

	// �������� ��
	std::string messageKey = VernamCode(s);

	// ��������� ���������� ��� ���������� ����� � ������������� ������
	std::string message;
	std::string key;

	// �������� ������ �� ������, ������� ������� ������� VernamCode �� �������� - ��� ����� ������������� ������
	for (int i = 0; i < messageKey.length() / 2; i++)
	{
		message += messageKey[i]; 
	}
	std::cout << "������������� ������: \n" << message << "\n";

	// �������� ������ �� ������, ������� ������� ������� VernamCode � �������� �� ����� - ��� ����� ����
	for (int i = messageKey.length() / 2; i < messageKey.length(); i++)
	{
		key += messageKey[i];
	}
	std::cout << "���� ����������: \n" << key << "\n";
	system("pause>null");
}
/*													���� ��������
* ������ �������� ���������� ����� ����� ASCII-����. ���� �������� �� 32 �� 125, �� ���� �������� ����� �� ���������,
��� ������ ��������� char'��� �� ����� ���������. ������ �������� ����� � ���������� �����, �������� ����� ������, ������ �����
�������, ��� ��� ����� ����� �������� �� ���������� char'�� , � �� �� ������ 
*/
/// <summary>
/// ������� ����������� ����������� ������ � ������� ����� ��������
/// </summary>
/// <param name="message"> ������ ��� �������� </param>
/// <param name="key"> ���� ���������� </param>
/// <returns> ���������� ������������� ������ </returns>
std::string VizhnerCode(std::string message, std::string key) {
	std::string resultString="";
	for (int i = 0; i < message.length(); i++)
	{
		resultString += ((((int)message[i] - 32 + (int)key[i % key.length()] - 32) % 94 ) + 32 );
	}
	return resultString;
}

/// <summary>
/// �������, ������� ���������� �������������� � ������������� (����� ��������� � ���� ������)
/// </summary>
void Vizhner() {

	std::cout << "������� ���� (����� �����) ��� ����������: \n";

	// ������ ���� ��� ����������
	std::string key = UserInputText(); 

	std::cout << "������� ����� ��� ����������: \n";

	// ������ ������ ��� ����������
	std::string message = UserInputText();

	// ������� � ������� ���������
	std::cout << "������������� ������: \n" << VizhnerCode(message, key) << "\n";
	system("pause>null");
}