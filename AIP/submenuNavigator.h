/// <summary>
/// Функция осуществляющая вывод меню кодировок и обрабатывающая ввод пользователя
/// </summary>
void CoderMenu();

/// <summary>
/// Функция осуществляющая вывод меню кодировок и обрабатывающая ввод пользователя
/// </summary>
void DecoderMenu();

/// <summary>
/// Функция осуществляющая вывод меню кодировок и обрабатывающая ввод пользователя
/// </summary>
void AllCoders();

/// <summary>
/// Функция обрабатывает ввод и вызывает нужную функцию в зависимости от аргумента
/// </summary>
/// <param name="userChoice"> Номер элемента меню, который выбрал пользователь </param>
/// <returns> True если пользователь нажал "Выход"</returns>
bool MainMenuNavigator(int userChoice);

/// <summary>
/// Функция обрабатывает ввод и вызывает нужную функцию в зависимости от аргумента
/// </summary>
/// <param name="userChoice"> Номер элемента меню, который выбрал пользователь </param>
/// <returns> True если пользователь нажал "Выход"</returns>
bool CoderMenuNavigator(int userChoice);

/// <summary>
/// Функция обрабатывает ввод и вызывает нужную функцию в зависимости от аргумента
/// </summary>
/// <param name="userChoice"> Номер элемента меню, который выбрал пользователь </param>
/// <returns> True если пользователь нажал "Выход"</returns>
bool DecoderMenuNavigator(int userChoice);

/// <summary>
/// Функция обрабатывает ввод и вызывает нужную функцию в зависимости от аргумента
/// </summary>
/// <param name="userChoice"> Номер элемента меню, который выбрал пользователь </param>
/// <returns> True если пользователь нажал "Выход"</returns>
bool CipherMenuNavigator(int userChoice);