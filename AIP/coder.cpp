#include <iostream>
#include <string>
#include "input.h"
#include "submenuNavigator.h"
#include "coder.h"
#include <vector>

/*														ШИФР ЦЕЗАРЯ
*войдовая функция, которая шифрует текст со сдвигом по массиву алфавита
Смещает букву на k , где k это ключ шифрования, на который происходит смещение
Если ключ равен 3 , то происходит следующее , ABC заменяется на DEF
	  A B C......Z
	  | | |.......\
A B C D E F....A B C
функия принимает строку , запрашивает ключ и выводит зашифрованную строку
ключ может лежать в диапазоне от 1 до 94 , так как всего 26 букв в латинском алфавите (прописных и строчных) + цифры и некоторые символы, если ключ будет равен 0 или
длине алфавита , то А будет шифроваться в А
*/

/// <summary>
/// Функция шифрования строки с помощью шифра цезаря
/// </summary>
/// <param name="key"> Ключ </param>
/// <param name="message"> Строка для шифрования </param>
/// <returns> Возвращает зашифрованную строку </returns>
std::string CaesarCoder(int key, std::string message) {
	// Зашифрованная строка, изначально пустая
	std::string res = "";

	// Проходим циклом по строке и шифруем ее сдвигом по аски таблице на ключ
	for (int i = 0; i < message.length(); i++)
	{
		/*приводим каждый символ к числу (код аски) прибавляем ключ затем чтобы не выйти за границы интервала символов 
		вычитам минимальное значение берем остаток от деления на длинну алфавита и прибавляем минимальное значение*/
		res += (char)(((((int)message[i] + key) - 32) % 94) + 32);
	}
	return res;
}

/// <summary>
/// Функция, которая производит взаимодействия с пользователем (вывод сообщений и ввод данных)
/// </summary>
void Caesar() {

	std::cout << "Введите ключ для шифрования от 1 до 94: \n";
	int key = UserInput(1, 94); // ключ для сдвига 
	
	std::cout << "Введите текст для шифрования: \n";
	std::string textToCode = UserInputText(); // Текст для шифровки

	// шифруем текст
	std::string res = CaesarCoder(key, textToCode);

	std::cout << "Зашифрованная строка: \n" << res;

	system("pause>null");
}
/*														ШИФР ВЕРНАМА
* XOR-шифр , который работает со случайно сгенерированным ключом из нужного диапазона 
*/

/// <summary>
/// Вспомогательная функция для генерирования случайного числа в качестве ключа
/// </summary>
/// <param name="symbol"> аски код символа из строки который надо зашифровать </param>
/// <returns> Подходящий случайный ключ </returns>
int GenRandomKey(int symbol) {

	// Генерируем случайный ключ в диапазоне от 32 до 124
	int correctKeyVernam = (rand() % 125) + 32;

	// Применяем XOR для символа и ключа (пытаемся зашифровать)
	int message = symbol ^ correctKeyVernam;

	// если зашифрованный символ выходит за пределы - генерируем ключ заново
	while (message < 32 || message >125) {
		correctKeyVernam = (rand() % 125) + 32;
		message = symbol ^ correctKeyVernam;
	}

	return correctKeyVernam;
}

/// <summary>
/// Функция шифрования строки с помощью шифра Вернама
/// </summary>
/// <param name="message"> Строка для шифрования </param>
/// <returns> Возвращает зашифрованную строку соединенную с ключом </returns>
std::string VernamCode(std::string message) {
	int len = message.length(); // запоминаем длину строки 
	std::vector<int> key(len); //вектор длиной с длину строки 

	// Проходим циклом по строке и создаем случайный ключ для каждого символа
	for (int i = 0; i < len; i++)
	{
		key[i] = GenRandomKey(message[i]);
	}

	//закодированная строка , изначально пустая
	std::string resultString = ""; 

	// Проходим циклом по строке и шифруем каждый символ случайным ключом
	for (int i = 0; i < len; i++)
	{
		resultString += (char)((int)message[i] ^ key[i]);
	}

	// Так как ключ генерируется случайно - его тоже переводим в строку
	std::string keyString = "";
	for (int i = 0; i < len; i++)
	{
		keyString += (char)key[i];

	}

	// длинна ключа равна длинне строки, возвращаем строку с ключом
	return resultString + keyString;
}

/// <summary>
/// Функция, которая производит взаимодействия с пользователем (вывод сообщений и ввод данных)
/// </summary>
void Vernam() {
	
	std::cout << "Введите текст для шифрования: \n";

	// Считываем строку для шифровки
	std::string s = UserInputText();

	// Кодируем ее
	std::string messageKey = VernamCode(s);

	// Объявляем переменные для извлечения ключа и зашифрованной строки
	std::string message;
	std::string key;

	// проходим циклом по строке, которую вернула функция VernamCode до середины - это будет зашифрованная строка
	for (int i = 0; i < messageKey.length() / 2; i++)
	{
		message += messageKey[i]; 
	}
	std::cout << "Зашифрованная строка: \n" << message << "\n";

	// проходим циклом по строке, которую вернула функция VernamCode с середины до конца - это будет ключ
	for (int i = messageKey.length() / 2; i < messageKey.length(); i++)
	{
		key += messageKey[i];
	}
	std::cout << "Ключ шифрования: \n" << key << "\n";
	system("pause>null");
}
/*													ШИФР ВИЖЕНЕРА
* данный алгоритм реализован через часть ASCII-кода. Взял диапазон от 32 до 125, за этот диапазон выйти не получится,
все данные шифруются char'ами из этого диапазона. Ключом является слово и происходит сдвиг, подобный шифру Цезаря, только более
надёжный, так как слово может состоять из нескольких char'ов , а не из одного 
*/
/// <summary>
/// Функция позволяющая зашифровать строку с помощью шифра Виженера
/// </summary>
/// <param name="message"> Строка для шифровки </param>
/// <param name="key"> Ключ шифрования </param>
/// <returns> возвращает зашифрованную строку </returns>
std::string VizhnerCode(std::string message, std::string key) {
	std::string resultString="";
	for (int i = 0; i < message.length(); i++)
	{
		resultString += ((((int)message[i] - 32 + (int)key[i % key.length()] - 32) % 94 ) + 32 );
	}
	return resultString;
}

/// <summary>
/// Функция, которая производит взаимодействия с пользователем (вывод сообщений и ввод данных)
/// </summary>
void Vizhner() {

	std::cout << "Введите ключ (любое слово) для шифрования: \n";

	// Вводим ключ для шифрования
	std::string key = UserInputText(); 

	std::cout << "Введите текст для шифрования: \n";

	// Вводим строку для шифрования
	std::string message = UserInputText();

	// Шифруем и выводим результат
	std::cout << "Зашифрованная строка: \n" << VizhnerCode(message, key) << "\n";
	system("pause>null");
}