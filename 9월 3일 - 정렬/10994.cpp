//문제
//예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

//아이디어
//정사각형 별 반복

#include <iostream>
#include <algorithm>

using namespace std;
char map[500][500];

void ReculsiveStar(int row, int col, int n);

int main() {
    int N;
    cin >> N;

    //map reset
    fill(&map[0][0], &map[499][499], ' ');

    ReculsiveStar(0, 0, N);

    //result
    for (int i = 0; i < 1 + 4 * (N - 1); i++) {
        for (int j = 0; j < 1 + 4 * (N - 1); j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}

void ReculsiveStar(int row, int col, int n) {
    if (n == 0) return;
    for (int i = 0; i < 4 * (n - 1) + 1; i++) {
        map[row + 0][col + i] = '*';
        map[row + 4 * (n - 1)][col + i] = '*';
        map[row + i][col + 0] = '*';
        map[row + i][col + 4 * (n - 1)] = '*';
    }

    ReculsiveStar(row + 2, col + 2, n - 1);
}
