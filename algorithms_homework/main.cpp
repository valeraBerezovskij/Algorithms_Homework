#include <iostream>
#include <stack>
//#include "Stack.h"
using namespace std;

bool isPair(char prev, char cur) {
	return (prev == '(' && cur == ')') ||
		(prev == '[' && cur == ']') ||
		(prev == '{' && cur == '}');
}

bool normalBrackets(const string& str) {
	stack<char> st;
	char prev{}, cur{};

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']' || str[i] == '{' || str[i] == '}') {
			if (st.empty()) {
				st.push(str[i]);
				cur = st.top();
				prev = cur;
			}
			else {
				prev = st.top();
				st.push(str[i]);
				cur = st.top();
			}
			cout << st.top();
		}
		if (isPair(prev, cur)) {
			st.pop(); st.pop();
			prev = ' '; cur = ' ';
		}

		if (prev == '(' && cur == ']' || prev == '(' && cur == '}' || prev == '[' && cur == ')' || prev == '[' && cur == '}' ||
			prev == '{' && cur == ')' || prev == '{' && cur == ']') {
			cout << " <- ERROR HERE\n"; break;
		}
	}
	if (st.empty()) return true;
	return false;
}

int main() {
	string str2 = "({x-y-z} * [x + 2y] - (z + 4x))";
	string str1 = "([x-y-z} * [x + 2y) - {z + 4x)]";
	string str0 = "{([jj])fgdh(dhd{hdh}hdh)()(()({}))}";
	if (normalBrackets(str2)) {
		cout << "\nOK" << endl;
	}
	else {
		cout << "\nNOT OK" << endl;
	}


}
