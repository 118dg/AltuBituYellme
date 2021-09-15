// 문제
// 중위표기식 -> 후위표기식

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <char> st;

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			cout << str[i];
		}
		else if (str[i] == '(')
			st.push(str[i]);
		else if (str[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else if (str[i] == '*' || str[i] == '/') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else {
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}