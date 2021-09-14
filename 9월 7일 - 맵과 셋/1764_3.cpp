//문제
//김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 997;

vector<vector<string>> bucket;

//해시함수
int hashFunc(string str) {
	int key = 0;
	for (int i = 0; i < str.size(); i++)
		key += (str[i] - 'a') * i;
	return key % MAX_SIZE;
}

//버킷의 상태 출력
void printHash() {
	for (int i = 0; i < MAX_SIZE; i++) { //버킷의 i 인덱스
		cout << "[ " << i << " ] ";
		for (int j = 0; j < bucket[i].size(); j++)
			cout << "-> ( " << bucket[i][j] << " ) ";
		cout << '\n';
	}
}

//사람 이름으로 존재 여부 확인
bool findPerson(string name) {
	int key = hashFunc(name); //key 값
	for (int i = 0; i < bucket[key].size(); i++) { //버킷에서 일치하는 데이터 찾기
		if (bucket[key][i] == name) return true;
	}
	return false; //일치하는 데이터가 없음
}

int main() {
	int N, M, cnt = 0;
	cin >> N >> M;

	//입력
	vector<string> heard;
	vector<string> res;

	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		heard.push_back(str);
	}

	bucket.assign(MAX_SIZE, vector<string>(0));

	for (int i = 0; i < heard.size(); i++) {
		//hash function으로 key 구하기
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