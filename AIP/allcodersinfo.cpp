#include <iostream>

void InfoAboutCaesar() {
	std::cout << "In this submenu, you can see how the Caesar cipher works \n";
	std::cout << "In this encryption algorithm, the text is shifted to a specific key,\n";
	std::cout < < " which is entered by the user. The key must be in the range from 1 to 94, \n";
	std::cout < < " because only the necessary part of the ASCII code is implemented. All algorithms work \n";
	std::cout << "only with the Latin alphabet. Decryption requires the encoded text and the key. \n";
	system("pause>null");
}
void InfoAboutVernam() {
	std::cout << "In this submenu, you can see how the Vernam cipher works \n";
	std::cout << " In this encryption algorithm, a random key is generated that \n";
	std::cout < < " is equal in length to the encrypted and encrypted message. Each character of the entered \ n";
	std::cout << "message is encrypted with an individual key. All algorithms work \n";
	std::cout << "only with the Latin alphabet. Decryption requires the encoded text and the key. \n";
	system("pause>null");
}
void InfoAboutVizhner() {
	std::cout << "In this submenu, you can see how the Vigener cipher works \n";
	std::cout << " This encryption algorithm generates a random key that \n";
	std::cout < < " is equal in length to the encrypted and encrypted message. Each character of the entered \ n";
	std::cout << "message is encrypted with an individual key. All algorithms work \n";
	std::cout << "only with the Latin alphabet. Decryption requires the encoded text and the key. \n";
	system("pause>null");
}