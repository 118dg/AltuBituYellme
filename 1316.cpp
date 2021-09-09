//문제
//그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다.
//예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, 
//aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
//단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

//아이디어
//알파벳은 26개니까 string 글자 순서대로 확인하면서 연속이면 패스, 연속 아닌 경우 처음보는 거면 체크, 이미 있는 거면 그룹 단어X!

#include <iostream>
#include <vector>

using namespace std;

int N, cnt;
string str;

void checkGroupWord(string str);

int main() {
	cin >> N;

	for (int t = 0; t < N; t++) {
		cin >> str;
		checkGroupWord(str);
	}

	cout << cnt << "\n";
	return 0;
}

void checkGroupWord(string str) {
	vector<bool> check(26, 0);
	cnt++;
	check[str[0] - 'a'] = true;
	for (int i = 1; i < str.size(); i++) {
		if (str[i - 1] == str[i]) continue;
		if (check[str[i] - 'a']) {
			cnt--;
			break;
		}
		check[str[i] - 'a'] = true;
	}
}
