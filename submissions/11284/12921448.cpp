#define _CRT_SECURE_NO_WARNINGS
#include <codecvt>
#include <string>
#include <iostream>
#include <locale>
#include <vector>
using namespace std;
class Hangul {


	static const int INITIAL_CONSONANT_COUNT = 19;
	static const int VOWEL_COUNT = 21;
	static const int FINAL_CONSONANT_COUNT = 28;
	static const int LBase = 0x1100;
	static const int VBase = 0x1161;
	static const int TBase = 0x11A7;

	wchar_t resultcho = 0;
	wchar_t resultjung = 0;
	wchar_t resultjong = 0;
public:
	static const wchar_t BASE_CODE = 0xac00; // '\\uac00'
	Hangul(int input) {
		resultcho = LBase + (input) / (VOWEL_COUNT * FINAL_CONSONANT_COUNT);
		resultjung = VBase + ((input) % (VOWEL_COUNT * FINAL_CONSONANT_COUNT)) / 28;
		resultjong = TBase + ((input) % (VOWEL_COUNT * FINAL_CONSONANT_COUNT)) % 28;
	}



	void print() {
		std::locale::global(std::locale("kor"));
		wcout << resultcho << endl;
		wcout << resultjung << endl;
		if (resultjong == 4519) {
			cout << endl;
		}
		else
			wcout << resultjong << endl;
	}
};

int main() {

	char s[4];
	scanf("%s", s);
	
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> con;
	std::wstring wstr = con.from_bytes(s);
	std::locale::global(std::locale("kor"));
	//wcout << wstr;
	//wscanf(L"%s", input);
	wstr[0] = wstr[0] - Hangul::BASE_CODE;

	Hangul hangul = Hangul(wstr[0]);
	hangul.print();
}
