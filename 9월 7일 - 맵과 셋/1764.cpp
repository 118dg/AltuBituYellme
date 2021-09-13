//����
//�������� �赵 ���� ����� ��ܰ�, ���� ���� ����� ����� �־��� ��, �赵 ���� ���� ����� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	string s;
	map<string, int> heard;
	set<string> seen;

	cin >> n >> m;

	for (int i = 0; i < n + m; ++i) {
		string val;
		cin >> val;
		heard[val]++;
		if (heard[val] > 1) seen.insert(val);
	}

	cout << seen.size() << "\n";
	for (auto i : seen) cout << i << "\n";

	return 0;
}