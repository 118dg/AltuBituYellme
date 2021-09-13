//����
//���� ������ ������ �׻� ū ��ĩ�Ÿ����� ���� �־���.�� ������ ���� �������� ������ ���� ������ ���� ū ����� �ɾ���.
//���̰� N�� ���� �迭 A�� B�� �ִ�.������ ���� �Լ� S�� ��������.
//S = A[0]��B[0] + ... + A[N - 1]��B[N - 1]
//S�� ���� ���� �۰� ����� ���� A�� ���� ��迭����.��, B�� �ִ� ���� ��迭�ϸ� �� �ȴ�.
//S�� �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

//���̵��
//���� ���� �� * ���� ū �� ...

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, min = 0;
	vector<int> A, B;

	//input
	cin >> N;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		A.push_back(val);
	}
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		B.push_back(val);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	for (int i = 0; i < N; i++) {
		min += A[i] * B[i];
	}

	cout << min << "\n";

	return 0;
}
