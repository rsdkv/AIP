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
	REQUIRE(CaesarCoder(90, "Republic of Tatarstan") == "Nalq^he_zkbzP]p]nop]j");
	REQUIRE(CaesarCoder(68, "BIB203") == "(/(vtw");
	REQUIRE(CaesarCoder(77, "Sadykov Robert") == "BPShZ^emA^QTac");
}
//TEST_CASE("test caesar") {
//	CHECK(CaesarCoder(3, "abc") == "def");
//	CHECK(CaesarCoder(1, "abc") == "bcd");
//	CHECK(CaesarCoder(5, "qwe") == "v|j");
//	CHECK(CaesarCoder(7, "hello , world") == "olssv'3' vysk'");
//	CHECK(CaesarCoder(10, "kickflip") == "usmupvsz");
//	CHECK(CaesarCoder(21, "oooooo") == "&&&&&&");
//	CHECK(CaesarCoder(29, "YouTube.com") == "v.4q4!$K"., ");
//		CHECK(CaesarCoder(76, "Google.com") == "5]]UZSzQ][");
//	CHECK(CaesarCoder(56, "slovo") == "MFIPI");
//	CHECK(CaesarCoder(33, "Higher School of Economics") == "i,*+(5At&+22/A2)Af&2120,&6");
//	CHECK(CaesarCoder(90, "Republic of Tatarstan") == "Nalq^he_zkbzP]p]nop]j");
//	CHECK(CaesarCoder(68, "BIB203") == "(/(vtw");
//	CHECK(CaesarCoder(77, "Sadykov Robert") == "BPShZ^emA^QTac");
//}