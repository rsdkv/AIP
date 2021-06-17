/// <summary>
/// ������� �������������� ����� ���� ��������� � �������������� ���� ������������
/// </summary>
void CoderMenu();

/// <summary>
/// ������� �������������� ����� ���� ��������� � �������������� ���� ������������
/// </summary>
void DecoderMenu();

/// <summary>
/// ������� �������������� ����� ���� ��������� � �������������� ���� ������������
/// </summary>
void AllCoders();

/// <summary>
/// ������� ������������ ���� � �������� ������ ������� � ����������� �� ���������
/// </summary>
/// <param name="userChoice"> ����� �������� ����, ������� ������ ������������ </param>
/// <returns> True ���� ������������ ����� "�����"</returns>
bool MainMenuNavigator(int userChoice);

/// <summary>
/// ������� ������������ ���� � �������� ������ ������� � ����������� �� ���������
/// </summary>
/// <param name="userChoice"> ����� �������� ����, ������� ������ ������������ </param>
/// <returns> True ���� ������������ ����� "�����"</returns>
bool CoderMenuNavigator(int userChoice);

/// <summary>
/// ������� ������������ ���� � �������� ������ ������� � ����������� �� ���������
/// </summary>
/// <param name="userChoice"> ����� �������� ����, ������� ������ ������������ </param>
/// <returns> True ���� ������������ ����� "�����"</returns>
bool DecoderMenuNavigator(int userChoice);

/// <summary>
/// ������� ������������ ���� � �������� ������ ������� � ����������� �� ���������
/// </summary>
/// <param name="userChoice"> ����� �������� ����, ������� ������ ������������ </param>
/// <returns> True ���� ������������ ����� "�����"</returns>
bool CipherMenuNavigator(int userChoice);