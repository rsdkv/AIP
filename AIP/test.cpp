#include "coder.h"
#include "decoder.h"
#include "doctest.h"

TEST_CASE("test caesar") {
	REQUIRE(CaesarCoder(3, "abc") == "def");
	REQUIRE(CaesarCoder(1, "abc") == "bcd");
	REQUIRE(CaesarCoder(5, "qwe") == "v|j");
	REQUIRE(CaesarCoder(10, "kickflip") == "usmupvsz");
	REQUIRE(CaesarCoder(21, "oooooo") == "&&&&&&");
	REQUIRE(CaesarCoder(49, "YouTube") == ",BH'H58");
	REQUIRE(CaesarCoder(76, "Google.com") == "5]]UZSzQ][");
	REQUIRE(CaesarCoder(56, "slovo") == "MFIPI");
	REQUIRE(CaesarCoder(33, "Higher School of Economics") == "i,*+(5At&+22/A2)Af&2120,&6");
	REQUIRE(CaesarCoder(70, "who are you") == "_PWfIZMfaW]");
}

TEST_CASE("test Vizhner") {
	REQUIRE(VizhnerCode("helloworld", "haha") == "RHVOYZYUVG");
	REQUIRE(VizhnerCode("never sleep", "qwerty") == "a^]YhyfeLYf");
	REQUIRE(VizhnerCode("qwertyuiop", "abc") == "T[JUX^XMTS");
	REQUIRE(VizhnerCode("helloworld", "hi") == "RPVWYbY]VO");
	REQUIRE(VizhnerCode("helloworld", "HI") == "20679B9=6/");
	REQUIRE(VizhnerCode("message", "TEST") == "C,HI7.:");
	REQUIRE(VizhnerCode("message", "text") == "cLmiWN_");
	REQUIRE(VizhnerCode("basketball", "football") == "JRdaIWPOT]");
	REQUIRE(VizhnerCode("How are you?", "hand") == "2RgdKUUdcRe%");
}
TEST_CASE("test DeCaesar") {
	REQUIRE(CaesarDecoder(3, "def") == "abc");
	REQUIRE(CaesarDecoder(1, "bcd") == "abc");
	REQUIRE(CaesarDecoder(5, "v|j") == "qwe");
	REQUIRE(CaesarDecoder(10, "usmupvsz") == "kickflip");
	REQUIRE(CaesarDecoder(49, ",BH'H58") == "YouTube");
	REQUIRE(CaesarDecoder(56, "MFIPI") == "slovo");
	REQUIRE(CaesarDecoder(70, "_PWfIZMfaW]") == "who are you");
}
TEST_CASE("test DeVizhner") {
	REQUIRE(VizhnerDecode("RPVWYbY]VO", "hi") == "helloworld");
	REQUIRE(VizhnerDecode("20679B9=6/", "HI") == "helloworld");
	REQUIRE(VizhnerDecode("C,HI7.:", "TEST") == "message");
	REQUIRE(VizhnerDecode("cLmiWN_", "text") == "message");
	REQUIRE(VizhnerDecode("JRdaIWPOT]", "football") == "basketball");
	REQUIRE(VizhnerDecode("RHVOYZYUVG", "haha") == "helloworld");
	REQUIRE(VizhnerDecode("a^]YhyfeLYf", "qwerty") == "never sleep");
	REQUIRE(VizhnerDecode("T[JUX^XMTS", "abc") == "qwertyuiop");
	
}