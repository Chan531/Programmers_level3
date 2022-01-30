#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long start = 0;
    long long end = 1000000000000000000;
    long long mcnt = end;
    while (start <= end)
    {
        long long cnt = 0;
        long long mid = (start + end) / 2;
        for (int i = 0; i < times.size(); i++)
            cnt += mid / times[i];
        if (cnt >= n)
        {
            mcnt = min(mid, mcnt);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return mcnt;
}