#include <iostream>
#include <string>
#include <stack>
#include <iomanip>

using namespace std;

int var[26];

int main(void)
{
    int N;
    cin >> N;

    string str;
    cin >> str;

    for (int i = 0; i < N; i++)
        cin >> var[i];

    stack<double> s;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();

            switch (str[i])
            {
            case '+':
                s.push(b + a);
                break;
            case '-':
                s.push(b - a);
                break;
            case '*':
                s.push(b * a);
                break;
            case '/':
                s.push(b / a);
                break;
            }
        }
        else
            s.push(var[str[i] - 'A']);
    }

    double res = s.top();
    cout << fixed;
    cout.precision(2);
    cout << res << "\n";

    return 0;
}