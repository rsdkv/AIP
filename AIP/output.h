#include <string>
#include <vector>


/// <summary>
/// Функция хранящая в себе все меню в виде массива строк, где на 0 месте стоит заголовок, а на 1..n элементы меню
/// </summary>
/// <param name="xMenu"> Номер меню, которое мы хотим получить </param>
/// <returns> массив строк меню </returns>
std::vector<std::string> GetMenu(int xMenu);


/// <summary>
/// Функция печатающая меню в консоли
/// </summary>
/// <param name="xMenu"> Номер меню, которое мы хотим вывести </param>
void PrintMenu(int xMenu);