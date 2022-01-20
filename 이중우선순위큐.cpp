#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    map<int, int> arr;
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minpq;
    priority_queue<int> maxpq;
    for (int i = 0; i < operations.size(); i++)
    {
        string command = operations[i];
        if (command[0] == 'I')
        {
            int num = stoi(command.substr(2, command.length() - 2));
            minpq.push(num);
            maxpq.push(num);
            arr[num]++;
        }
        else
        {
            if (command[2] == '1')
            {
                while (!maxpq.empty() && !arr[maxpq.top()])
                    maxpq.pop();
                if (!maxpq.empty())
                {
                    arr[maxpq.top()]--;
                    maxpq.pop();
                }
            }
            else if (command[2] == '-' && !minpq.empty())
            {
                while (!minpq.empty() && !arr[minpq.top()])
                    minpq.pop();
                if (!minpq.empty())
                {
                    arr[minpq.top()]--;
                    minpq.pop();
                }
            }
        }
    }
    while (!maxpq.empty() && !arr[maxpq.top()])
        maxpq.pop();
    while (!minpq.empty() && !arr[minpq.top()])
        minpq.pop();
    if (maxpq.empty() && minpq.empty())
        answer = { 0, 0 };
    else
        answer = { maxpq.top(), minpq.top() };
    return answer;
}