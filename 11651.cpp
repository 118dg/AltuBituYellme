//����
//2���� ��� ���� �� N���� �־�����.
//��ǥ�� y��ǥ�� �����ϴ� ������, y��ǥ�� ������ x��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

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