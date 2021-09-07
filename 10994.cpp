//문제
//예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

#include <iostream>

using namespace std;
char map[500][500];

void ReculsiveStar(int row, int col, int n);

int main() {
    int N;
    cin >> N;

    ReculsiveStar(0, 0, N);

    for (int i = 0; i < 1 + 4 * (N - 1); i++) {
        for (int j = 0; j < 1 + 4 * (N - 1); j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}

void ReculsiveStar(int row, int col, int n) {
    if (n == 0) return;
    for (int i = 0; i < 4 * (n - 1) + 1; i++) { //row
        for (int j = 0; j < 4 * (n - 1) + 1; j++) { //column
            if (i == 0 || i == 4 * (n - 1)) {
                map[row + i][col + j] = '*';
                continue;
            }
            if (j == 0 || j == 4 * (n - 1)) {
                map[row + i][col + j] = '*';
                continue;
            }
            map[row + i][col + j] = ' ';
        };
    }
    ReculsiveStar(row + 2, col + 2, n - 1);
}
