#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    queue<pair<int, string>> q;
    vector<int> visited(words.size());
    q.push({ 0, begin });
    while (!q.empty())
    {
        string current = q.front().second;
        int cnt = q.front().first;
        q.pop();

        if (current == target)
            return cnt;

        for (int i = 0; i < words.size(); i++)
        {
            int wrongcnt = 0;
            if (visited[i])
                continue;
            for (int j = 0; j < current.length(); j++)
            {
                if (current[j] != words[i][j])
                    wrongcnt++;
            }
            if (wrongcnt == 1)
            {
                visited[i] = 1;
                q.push({ cnt + 1, words[i] });
            }
        }
    }
    return 0;
}