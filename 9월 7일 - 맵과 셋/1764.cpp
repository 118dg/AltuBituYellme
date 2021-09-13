//문제
//김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

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