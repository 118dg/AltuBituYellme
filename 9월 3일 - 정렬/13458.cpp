//문제
//총 N개의 시험장이 있고, 각각의 시험장마다 응시자들이 있다.i번 시험장에 있는 응시자의 수는 Ai명이다.
//감독관은 총감독관과 부감독관으로 두 종류가 있다.총감독관은 한 시험장에서 감시할 수 있는 응시자의 수가 B명이고,
//부감독관은 한 시험장에서 감시할 수 있는 응시자의 수가 C명이다.
//각각의 시험장에 총감독관은 오직 1명만 있어야 하고, 부감독관은 여러 명 있어도 된다.
//각 시험장마다 응시생들을 모두 감시해야 한다.이때, 필요한 감독관 수의 최솟값을 구하는 프로그램을 작성하시오.

//아이디어
//각 방마다 일단 감독 넣기. 남은 인원 부감독 몇 명으로 감당가능한지 나눠보기. 나머지 있으면 ++

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, B, C;
	long long cnt = 0;
	vector<int> A;

	//input
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}
	cin >> B >> C;

	//result
	for (int i = 0; i < N; i++) {
		if (B >= A[i]) cnt++;
		else {
			int cnum = (A[i] - B) / C;
			if ((A[i] - B) % C > 0) cnum++;
			cnt = cnt + 1 + cnum;
		}
	}

	cout << cnt << "\n";
	return 0;
}
