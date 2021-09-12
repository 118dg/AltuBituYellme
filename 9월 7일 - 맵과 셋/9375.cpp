// ����
// �غ��̴� �мǿ� �ſ� �ΰ��ؼ� �ѹ� �Ծ��� �ʵ��� ������ ���� �ٽ� ���� �ʴ´�.
// ���� ��� ���� �غ��̰� �Ȱ�, ��Ʈ, ����, �Ź��� �Ծ��ٸ�, �������� ������ �߰��� �԰ų� �Ȱ��� ��� �����ϰų� �ؾ��Ѵ�. 
// �غ��̰� ���� �ǻ���� �־������� ���� �غ��̴� �˸��� �ƴ� ���·� ��ĥ���� �ۿ� ���ƴٴ� �� ������?

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int T, N;
	cin >> T;

	string item, type;

	while (T--) {
		cin >> N;
		map<string, int> m;

		for (int i = 0; i < N; i++) {
			cin >> item >> type;
			m[type]++;
		}

		int res = 1;
		for (auto i : m) res *= i.second + 1; //�� ���� �԰ų� + �ƿ� �� �԰ų�
		cout << res - 1 << "\n"; //��ü - �˸�
	}

	return 0;
}