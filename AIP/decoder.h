#include <string>

std::string CaesarDecoder(int key, std::string message);
std::string VernamDecode(std::string message, std::string key);
std::string VizhnerDecode(std::string message, std::string key);

void DeCaesar();
void DeVernam();
void DeVizhener();