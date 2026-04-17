#define _CRT_SECURE_NO_WARNINGS
#include <codecvt>
#include <string>
#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
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
	char s[12];
	scanf("%s", s);
	wchar_t *temp = new wchar_t[sizeof(wchar_t) * strlen(s) + 1];
	MultiByteToWideChar(CP_ACP, MB_COMPOSITE, s, strlen(s), temp, strlen(s)+1);
	//wscanf(L"%s", input);
	temp[0] = temp[0] - Hangul::BASE_CODE;

	Hangul hangul = Hangul(temp[0]);
	hangul.print();
}
