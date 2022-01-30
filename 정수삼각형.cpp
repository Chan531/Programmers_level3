#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int tsize = triangle.size();
    for (int i = 1; i < tsize; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                triangle[i][j] += triangle[i - 1][j];
            else if (j == i)
                triangle[i][j] += triangle[i - 1][j - 1];
            else
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
    }
    return *max_element(triangle[tsize - 1].begin(), triangle[tsize - 1].end());
}