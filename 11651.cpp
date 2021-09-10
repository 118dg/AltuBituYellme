//문제
//2차원 평면 위의 점 N개가 주어진다.
//좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b);

int main() {
	int N, x, y;
	cin >> N;
	vector<pair<int, int>> coordinate;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		coordinate.emplace_back(x, y);
	}

	sort(coordinate.begin(), coordinate.end(), cmp);

	for (auto i:coordinate) cout << i.first << " " << i.second << "\n";

	return 0;
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}