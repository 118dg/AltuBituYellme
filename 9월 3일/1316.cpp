//����
//�׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�.
//���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����, kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������, 
//aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.
//�ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

//���̵��
//���ĺ��� 26���ϱ� string ���� ������� Ȯ���ϸ鼭 �����̸� �н�, ���� �ƴ� ��� ó������ �Ÿ� üũ, �̹� �ִ� �Ÿ� �׷� �ܾ�X!

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
	check[str.at(0) - 'a'] = true;
	for (int i = 1; i < str.size(); i++) {
		if (str.at(i - 1) == str.at(i)) continue;
		if (check[str.at(i) - 'a']) {
			cnt--;
			break;
		}
		check[str.at(i) - 'a'] = true;
	}
}
