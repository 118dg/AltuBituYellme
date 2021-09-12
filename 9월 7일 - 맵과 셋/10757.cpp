// 문제
// 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

#include <iostream>
#include <cmath>

using namespace std;

int last1, last2, up = 0;

void sum(string& str1, string& str2, string& res);
void print(string& str);

int main() {

	string n1, n2, res = "";
	cin >> n1 >> n2;

	sum(n1, n2, res);
	print(res);

	return 0;
}

void sum(string &str1, string &str2, string &res) {
	int len1 = str1.size(), len2 = str2.size(), ch1, ch2;
	while (len1 > 0 || len2 > 0)
	{
		ch1 = 0; ch2 = 0;
		if (len1 > 0)
		{
			ch1 = str1[--len1] - '0';
		}
		if (len2 > 0)
		{
			ch2 = str2[--len2] - '0';
		}
		int sum = ch1 + ch2 + up;
		up = sum / 10;
		sum %= 10;
		res += sum + '0';
	}
}

void print(string& str) {
	if (up > 0) str += up + '0';
	for (int i = str.length() - 1; i >= 0; i--) cout << str[i];
}