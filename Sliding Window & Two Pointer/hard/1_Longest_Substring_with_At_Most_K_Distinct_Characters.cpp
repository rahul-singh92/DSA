#include <iostream>
using namespace std;

int bru_way(string& s, int k)
{
    int maxLen = 0;

    for(int i = 0; i < s.size(); i++)
    {
        unordered_map<char, int> mpp;
        for(int j = i; j < s.size(); j++)
        {
            mpp[s[j]]++;
            if(mpp.size() > k) break;

            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

int op_way(string s, int k)
{
    if(k == 0 || s.empty()) return 0;

    unordered_map<char, int> freq;

    int l = 0, r = 0;
    int maxLen = 0;

    while(r < s.size())
    {
        freq[s[r]]++;

        // shrink window if exceedes k
        while(freq.size() > k)
        {
            freq[s[l]]--;

            if(freq[s[l]] == 0) freq.erase(s[l]);

            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}

int main()
{
    string s = "aababbcaacc";
    int k = 2;

    int ans = op_way(s, 2);

    cout<<ans<<endl;
}