/**
 * We declare a package-level function main which returns Unit and takes
 * an Array of strings as a parameter. Note that semicolons are optional.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <wchar.h>
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
	wchar_t input[2];
	setlocale(LC_ALL, "Korean");

	wscanf(L"%s", input);
	input[0] = input[0] - Hangul::BASE_CODE;

	Hangul hangul = Hangul(input[0]);
	hangul.print();
}

