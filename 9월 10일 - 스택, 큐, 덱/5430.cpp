// ����
// �����̴� �ָ��� �� ���� ��� ���ο� ��� AC�� �������.
// AC�� ���� �迭�� ������ �ϱ� ���� ���� ����̴�.�� ���� �� ���� �Լ� R(������)�� D(������)�� �ִ�.
//
// �Լ� R�� �迭�� �ִ� ������ ������ ������ �Լ��̰�, D�� ù ��° ���ڸ� ������ �Լ��̴�.
// �迭�� ����ִµ� D�� ����� ��쿡�� ������ �߻��Ѵ�.
//
// �Լ��� �����ؼ� �� ���� ����� �� �ִ�.
// ���� ���, "AB"�� A�� ������ ������ �ٷ� �̾ B�� �����ϴ� �Լ��̴�.
// ���� ���, "RDD"�� �迭�� ������ ���� ó�� �� ���ڸ� ������ �Լ��̴�.
// 
// �迭�� �ʱⰪ�� ������ �Լ��� �־����� ��, ���� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while(T--)
    {
        string cmd, arr, temp;
        int N;
        cin >> cmd >> N >> arr;

        deque<int> dq;

        for (int i = 0; i < arr.length(); i++) {
            if (arr[i] == '[')
                continue;

            else if ('0' <= arr[i] && arr[i] <= '9')
                temp += arr[i];

            else if (arr[i] == ',' || arr[i] == ']')
            {
                if (!temp.empty())
                {
                    dq.push_back(stoi(temp));
                    temp.clear();
                }
            }
        }

        bool error = false, reverse = true;

        for (int i = 0; i < cmd.length(); i++) {
            if (cmd[i] == 'R')
                reverse = !reverse;
            else
            {
                if (dq.empty())
                {
                    error = true;
                    cout << "error\n";
                    break;
                }
                else
                    if (reverse)
                        dq.pop_front();
                    else
                        dq.pop_back();
            }
        }

        if (!error)
        {
            if (reverse)
            {
                cout << "[";

                while (!dq.empty())
                {
                    cout << dq.front();
                    dq.pop_front();

                    if (!dq.empty())
                        cout << ",";
                }

                cout << "]\n";
            }

            else
            {
                cout << "[";

                while (!dq.empty())
                {
                    cout << dq.back();
                    dq.pop_back();

                    if (!dq.empty())
                        cout << ",";
                }

                cout << "]\n";
            }
        }
    }

    return 0;
}