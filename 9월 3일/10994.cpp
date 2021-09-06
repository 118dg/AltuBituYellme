//문제
//예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

#include <iostream>
#include <vector>

using namespace std;

string LeftBlank(int num);
string RightBlank(int num);
string CoutStar(int num);
string CoutBlank(int num);

int main() {
	int N, T, cnt;
	bool blank = false;

	//input
	cin >> N;

	T = cnt = 4 * (N - 1) + 1;

	//up
	for (int i = 0; i < T / 2; i++) {
		int num = (T - cnt) / 2;
		cout << LeftBlank(num);
		if (!blank) {
			blank = !blank;
			cout << CoutStar(cnt);
			cout << RightBlank(num);
		}
		else {
			blank = !blank;
			cout << CoutBlank(cnt);
			cout << RightBlank(num);
		}
		cout << "\n";
		cnt -= 2;
	}

	//down
	for (int i = 0; i < T / 2; i++) {
		int num = (T - cnt) / 2;
		cout << LeftBlank(num);
		if (!blank) {
			blank = !blank;
			cout << CoutStar(cnt);
			cout << RightBlank(num);
		}
		else {
			blank = !blank;
			cout << CoutBlank(cnt);
			cout << RightBlank(num);
		}
		cout << "\n";
		cnt += 2;
	}

	//mid
	cout << CoutStar(T);

	return 0;
}

string LeftBlank(int num) {
	string val;
	for (int i = 0; i < num; i++) {
		if (i % 2 == 0) {
			val += '*';
		}
		else {
			val += ' ';
		}
	}
	return val;
}

string RightBlank(int num) {
	string val;
	for (int i = 0; i < num; i++) {
		if (num % 2 == 0) {
			if (i % 2 == 0) {
				val += ' ';
			}
			else {
				val += '*';
			}
		}
		else {
			if (i % 2 == 0) {
				val += '*';
			}
			else {
				val += ' ';
			}
		}
	}
	return val;
}

string CoutStar(int num) {
	string val;
	for (int j = 0; j < num; j++) {
		val += '*';
	}
	return val;
}

string CoutBlank(int num) {
	string val;
	for (int j = 0; j < num; j++) {
		val += ' ';
	}
	return val;
}