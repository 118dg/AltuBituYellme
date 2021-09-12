#include <iostream>
#include <map>

using namespace std;

map<string, double> m;
int n;

int main() {

    string str;
    while (getline(cin, str)) {
        m[str]++;
        n++;
    }

    //소숫점 넷째 자리까지 출력 고정
    cout << fixed;
    cout.precision(4);

    for (auto i:m) cout << i.first << " " << (i.second / n) * 100 << "\n";

    return 0;
}