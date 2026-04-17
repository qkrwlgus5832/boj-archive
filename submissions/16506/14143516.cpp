#define _CRT_SECURE_NO_WARNINSG
#include <iostream>
#include <string>
#include <map>

using namespace std;

int N;

string assembly;

map <std::string, std::string> m;

void plustomachinestring(string r_, string& machine, int digitvalue) {
	int tmprD = atoi(r_.c_str());
	int digit = 1 << (digitvalue - 1);

	for (int i = 0; i < digitvalue; i++) {
		if ((tmprD & digit) >= 1) {
			machine += "1";
		}
		else {
			machine += "0";
		}
		digit = digit >> 1;
	}
}


void CPU(string opcode, string rD, string rA, string rB) {
	string machine;
	if (opcode.at(opcode.size() - 1) == 'C') {
		auto s = m.find(opcode.substr(0, opcode.size() - 1));
		machine += (*s).second;
		machine += "10";
	}
	else {
		auto s = m.find(opcode);
		machine += (*s).second;
		machine += "00";
	}
	
	plustomachinestring(rD,machine, 3);
	plustomachinestring(rA, machine,3);
	if (machine[4] == '0') {
		plustomachinestring(rB, machine, 3);
		machine += "0";
	}
	else {
		plustomachinestring(rB, machine, 4);
	}
	cout << machine << endl;
}
int main() {
	cin >> N;
	cin.tie(NULL);
	m.insert(make_pair("ADD", "0000"));
	m.insert(make_pair("SUB", "0001"));
	m.insert(make_pair("MOV", "0010"));
	m.insert(make_pair( "AND", "0011"));
	m.insert(make_pair("OR", "0100"));
	m.insert(make_pair("NOT", "0101"));
	m.insert(make_pair("MULT", "0110"));
	m.insert(make_pair("LSFTL", "0111"));
	m.insert(make_pair("LSFTR", "1000"));
	m.insert(make_pair("ASFTR", "1001"));
	m.insert(make_pair("RL", "1010"));
	m.insert(make_pair("RR", "1011"));

	getline(cin, assembly);
	for (int i = 0; i < N; i++) {
		
		getline(cin, assembly);
		//cin.getline(assembly, 15);
		string dd[4];
		string tmp;
		int index = 0;
		for (int i = 0; i < assembly.size(); i++) {
			if (assembly[i] == ' ') {
				dd[index++] = tmp;
				tmp = "";
				continue;
			}
			tmp += assembly[i];
		}
		dd[3] = tmp;
		CPU(dd[0], dd[1], dd[2], dd[3]);
	}
	//system("Pause");
}