//����
//�ټ��̴� ��Ÿ�� ���� ������ �ִ�.�׸��� ������ ��Ÿ�� ��� �ٸ� �ø��� ��ȣ�� ������ �ִ�.�ټ��̴� ��Ÿ�� ���� ã�Ƽ� ���� ����鿡�� �������ֱ� ���ؼ� ��Ÿ�� �ø��� ��ȣ ������� �����ϰ��� �Ѵ�.
//��� �ø��� ��ȣ�� ���ĺ� �빮��(A - Z)�� ����(0 - 9)�� �̷���� �ִ�.
//�ø����ȣ A�� �ø����ȣ B�� �տ� ���� ���� ������ ����.

//A�� B�� ���̰� �ٸ���, ª�� ���� ���� �´�.
//���� ���� ���̰� ���ٸ�, A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ� ���� ���� ������ ���� �����´�. (������ �͸� ���Ѵ�)
//���� 1, 2�� �� �������ε� ���� �� ������, ���������� ���Ѵ�.���ڰ� ���ĺ����� ���������� �۴�.
//�ø����� �־����� ��, �����ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetSum(string str);
bool cmp(string a, string b);

int main() {
	int N;
	vector<string> A;

	//input
	cin >> N;
	for (int i = 0; i < N; i++) {
		string val;
		cin >> val;
		A.push_back(val);
	}

	sort(A.begin(), A.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << A[i] << "\n";
	}

	return 0;
}

int GetSum(string str) {
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i])) sum += str[i] - '0';
	}
	return sum;
}

bool cmp(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();

	int sum_a = GetSum(a);
	int sum_b = GetSum(b);
	if (sum_a != sum_b) return sum_a < sum_b;

	return a < b;
}

