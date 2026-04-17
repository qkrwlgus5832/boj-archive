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

void utf8toWStr(wstring& dest, const string& src) {
	dest.clear();
	wchar_t w = 0;
	int bytes = 0;
	wchar_t err = L'�';
	for (size_t i = 0; i < src.size(); i++) {
		unsigned char c = (unsigned char)src[i];
		if (c <= 0x7f) {//first byte
			if (bytes) {
				dest.push_back(err);
				bytes = 0;
			}
			dest.push_back((wchar_t)c);
		}
		else if (c <= 0xbf) {//second/third/etc byte
			if (bytes) {
				w = ((w << 6) | (c & 0x3f));
				bytes--;
				if (bytes == 0)
					dest.push_back(w);
			}
			else
				dest.push_back(err);
		}
		else if (c <= 0xdf) {//2byte sequence start
			bytes = 1;
			w = c & 0x1f;
		}
		else if (c <= 0xef) {//3byte sequence start
			bytes = 2;
			w = c & 0x0f;
		}
		else if (c <= 0xf7) {//3byte sequence start
			bytes = 3;
			w = c & 0x07;
		}
		else {
			dest.push_back(err);
			bytes = 0;
		}
	}
	if (bytes)
		dest.push_back(err);
}

int main() {

	string s;
	cin >> s;
	wstring dd;
	utf8toWStr(dd, s);
	/*std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> con;
	std::wstring wstr = con.from_bytes(s);
	std::locale::global(std::locale("kor"));*/
	//wcout << wstr;
	//wscanf(L"%s", input);
	dd[0] = dd[0] - Hangul::BASE_CODE;

	Hangul hangul = Hangul(dd[0]);
	hangul.print();
}
