//����
//�������� �赵 ���� ����� ��ܰ�, ���� ���� ����� ����� �־��� ��, �赵 ���� ���� ����� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 997;

vector<vector<string>> bucket;

//�ؽ��Լ�
int hashFunc(string str) {
	int key = 0;
	for (int i = 0; i < str.size(); i++)
		key += (str[i] - 'a') * i;
	return key % MAX_SIZE;
}

//��Ŷ�� ���� ���
void printHash() {
	for (int i = 0; i < MAX_SIZE; i++) { //��Ŷ�� i �ε���
		cout << "[ " << i << " ] ";
		for (int j = 0; j < bucket[i].size(); j++)
			cout << "-> ( " << bucket[i][j] << " ) ";
		cout << '\n';
	}
}

//��� �̸����� ���� ���� Ȯ��
bool findPerson(string name) {
	int key = hashFunc(name); //key ��
	for (int i = 0; i < bucket[key].size(); i++) { //��Ŷ���� ��ġ�ϴ� ������ ã��
		if (bucket[key][i] == name) return true;
	}
	return false; //��ġ�ϴ� �����Ͱ� ����
}

int main() {
	int N, M, cnt = 0;
	cin >> N >> M;

	//�Է�
	vector<string> heard;
	vector<string> res;

	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		heard.push_back(str);
	}

	bucket.assign(MAX_SIZE, vector<string>(0));

	for (int i = 0; i < heard.size(); i++) {
		//hash function���� key ���ϱ�
		int key = hashFunc(heard[i]);
		bucket[key].push_back(heard[i]);
	}
	//printHash();

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (findPerson(str)) res.push_back(str);
	}

	cout << res.size() << "\n";
	sort(res.begin(), res.end());
	for (auto i : res) cout << i << "\n";

	return 0;
}