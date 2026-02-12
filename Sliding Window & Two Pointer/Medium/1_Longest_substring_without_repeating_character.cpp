#include <iostream>
using namespace std;

int bru_way(string input)
{
    int max_count = 0;
    int n = input.size();

    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> m;
        int count = 0;
        for (int j = i; j < n; j++)
        {
            char cur = input[j];
            if (m.find(cur) != m.end())
                break;

            m[cur] = 1;
            count++;
            max_count = max(max_count, count);
        }
    }
    return max_count;
}

int op_way(string s)
{
    int HashLen = 256;
    int mpp[HashLen];
    for (int i = 0; i < HashLen; ++i)
    {
        mpp[i] = -1;
    }
    int max_count = 0;
    int n = s.size();

    int l = 0, r = 0;
    int len = 0;
    while (r < n)
    {
        if (mpp[s[r]] != -1)
        {
            if (mpp[s[r]] >= l)
            {
                l = mpp[s[r]] + 1;
            }
        }
        len = r - l + 1;
        max_count = max(max_count, len);
        mpp[s[r]] = r;
        r++;
    }
    return max_count;
}

int main()
{
    string input = "abcddabac";
    int ans = op_way(input);

    cout << ans << endl;
}