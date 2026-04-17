#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;


class firstsecond {
public:
	int first;
	int second;
	bool flag;
	firstsecond(int first, int second, bool flag){
		this->first = first;
		this->second = second;
		this->flag = flag;
		
	}
};

firstsecond getFirstSecond(stack <int> &s) {

	if (s.size() < 2)
		return firstsecond(-1, -1, false);
	int first = s.top();
	s.pop();
	int second = s.top();
	s.pop();
	return firstsecond(first, second, true);
}

pair <bool, int> goStack(vector <pair <string, int>>& v, int input) {
	stack <int> s;
	s.push(input);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == "NUM") {
			s.push(v[i].second);
		}
		else if (v[i].first == "POP") {
			if (s.size() == 0)
				return { false,-1 };
			s.pop();
		}
		else if (v[i].first == "INV") {
			if (s.size() == 0)
				return { false,-1 };
			int top = s.top();
			top = top * -1;
			s.pop();
			s.push(top);
		}
		else if (v[i].first == "DUP") {
			if (s.size() == 0)
				return{ false,-1 };
			int top = s.top();
			s.push(top);
		}
		else  {
			firstsecond values= getFirstSecond(s);
			if (values.flag == false)
				return{ false, -1 };
			
			if (v[i].first == "SWP") {
				s.push(values.first);
				s.push(values.second);
				continue;
			}
			long long result;
			if (v[i].first == "ADD") 
				result = (values.first + values.second);
			else if (v[i].first == "SUB") 
				result = (values.second - values.first);
			else if (v[i].first == "MUL") {
				if (log10(values.first) + log10(values.second) > 9.0)
					return{ false, -1 };
				result = (values.second * values.first);
			}
			else   {
				if (values.first == 0)
					return{ false, -1 };
				if (v[i].first == "DIV")
					result = (values.second / values.first);
				else if (v[i].first == "MOD") 
					result = (values.second % values.first);
			}
			
			if (abs(result) > pow(10, 9) )
				return{ false, -1 };
			s.push(result);
		}
	}
	if (s.size() == 1) {
		return{ true, s.top() };
	}
	else
		return{ false, -1 };
}

int main() {
	char tmpcommand[5];
	string command;
	while (1) {
		vector <pair <string, int>> commands;
		int num;
		while (1) {
			scanf("%s", tmpcommand);
			command = tmpcommand;
			if (command == "QUIT")
				return 0;
			if (command == "END")
				break;
			else if (command == "NUM") {
				scanf("%d", &num);
				commands.push_back({ command, num });
			}
			else
				commands.push_back({ command, -1 });
		}
		scanf("%d", &num);
		int inputnumber;
		for (int i = 0; i < num; i++) {
			scanf("%d", &inputnumber);
			pair <bool, int> result =goStack(commands, inputnumber);
			if (result.first == false)
				printf("ERROR\n");
			else
				printf("%d\n", result.second);
		}
		printf("\n");
	}
	//system("Pause");
}