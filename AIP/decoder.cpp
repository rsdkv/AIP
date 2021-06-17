#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>

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

/// <summary>
/// ������� ������� �������������� ������ ������������� ������ ������ �� �����
/// </summary>
/// <param name="key"> ���� ��� ���������� </param>
/// <param name="message"> ������������� ��������� </param>
/// <returns> �������������� ��������� </returns>
std::string CaesarDecoder(int key, std::string message) {
	// �������������� ������
	std::string res = "";
	
	// �������� ������ �� ������ � ���������� � �������������� ������� ������ �������� - ���� 
	// � - 32) % 94) + 32 ����� �������� � ��������� ������� ��� ���� ����
	for (int i = 0; i < message.length(); i++)
	{
		res += (char)(((((int)message[i] + (94 - key)) - 32) % 94) + 32);
	}
	return res;
}

/// <summary>
/// ������� �������������� �������������� � �������������
/// </summary>
void DeCaesar() {

	std::cout << "������� ���� ��� ������������ �� 1 �� 94: \n";

	// ���� ��� ������ (�� 1 �� 94)
	int key = UserInput(1, 94); 

	std::cout << "������� ����� ��� ����������: \n";

	// ������������� �����
	std::string textToDeCode = UserInputText();

	// �����������
	std::cout << "������������� ������: \n" << CaesarDecoder(key , textToDeCode);

	system("pause>null");
}

/// <summary>
/// ������� ������� �������������� ������ ������������� ������ ������� �� �����
/// </summary>
/// <param name="key"> ���� ��� ���������� </param>
/// <param name="message"> ������������� ��������� </param>
/// <returns> �������������� ��������� </returns>
std::string VernamDecode(std::string message , std::string key) {

	// ���������� ����� ������ 
	int len = key.length(); 

	//��������������  ������ , ���������� ������
	std::string resultString = ""; 

	// �������� ������ �� ������ � �����, ��������� ������ ������ � ���� ���, ��������� XOR, 
	// ��������� ��������� � ������ � ��������� � �������������� ������
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)message[i] ^ (int)key[i]);
	}
	return resultString;
}

/// <summary>
/// ������� �������������� �������������� � �������������
/// </summary>
void DeVernam(){

	std::cout << "������� ���� ��� ������������: \n";

	// ���� �����
	std::string key = UserInputText();

	std::cout << "������� ����� ��� ������������: \n";

	// ���� ������������� ������
	std::string s = UserInputText();

	// �����������
	std::cout << "������������� ������: \n" << VernamDecode(s, key) << "\n";

	system("pause>null");
}

/// <summary>
/// ������� ������� �������������� ������ ������������� ������ �������� �� �����
/// </summary>
/// <param name="key"> ���� ��� ���������� </param>
/// <param name="message"> ������������� ��������� </param>
/// <returns> �������������� ��������� </returns>
std::string VizhnerDecode(std::string message, std::string key) {

	// �������������� ������, ���������� ������
	std::string resultString = "";
	
	// �������� ������ �� ������ � 
	// ������ ������ ������ �������� � ���� ����,
	// �������� ����������� ��� (32)
	// ���������� ������ �������� - ���� ��� ����� ������� - 32
	// ������ ����� ��� ����������� ������� �� ����� ��� ������� �� ������� ������� ������� �� ����� �����
	//  % 94 + 32 ����� �������� � ��������� ����� ���� �������
	for (int i = 0; i < message.length(); i++)
	{
		resultString += ((((int)message[i] - 32 + (94 - ((int)key[i % key.length()] - 32))) % 94) + 32);
	}
	return resultString;
}

/// <summary>
/// ������� �������������� �������������� � �������������
/// </summary>
void DeVizhener() {

	std::cout << "������� ���� (����� �����) ��� ������������: \n";

	// ��������� ����
	std::string key = UserInputText();

	std::cout << "������� ����� ��� ����������: \n";

	// ��������� ������������� ���������
	std::string message = UserInputText();

	// �������������
	std::cout << "������������� ������: \n" << VizhnerDecode(message, key) << "\n";
	system("pause>null");
}