#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L;
int C;
vector <string> sv;
string  v[15];
//vector<int>::iterator it;

//it = v.begin();

void print() {
	for (int i = 0; i < L; i++) {
		cout << v[i];
 }
	cout << "\n";
}


int isalpha() {
    int count1=0;
    int count2=0;
    for(int i=0; i<L; i++){
        if (v[i]== "a" || v[i] == "e" || v[i] == "i" || v[i] == "o" || v[i] == "u")
            count1 = count1+1;
        else 
            count2=count2+1;
    }
    
    if (count1 >= 1 && count2>=2)
        return 1;
}



void recursion(int a, int b) {
	if (a == L) {
        if(isalpha() == 1){
        print();
        }
		return;
	}

	for (int i = b; i < C; i++) {
		v[a] = sv[i];
		recursion(a + 1, i + 1);
	}
}


int main() {
	cin >> L >> C;

	string name;

	for (int i = 0; i < C; i++) {
		cin >> name;
		sv.push_back(name);
	}

	sort(sv.begin(), sv.end());

	/*for (int i = 0; i < C; i++) {
		cout << sv[i] << " ";
	}
	*/



	recursion(0, 0);

}