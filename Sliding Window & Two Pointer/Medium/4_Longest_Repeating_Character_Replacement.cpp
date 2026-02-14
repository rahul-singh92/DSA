#include <iostream>
using namespace std;

int bru_way(string s, int k)
{
    int maxLen = 0;

    for(int i = 0; i < s.size(); i++)
    {
        vector<int> freq(26, 0);
        
        int maxFreq = 0;
        for(int j = i; j < s.size(); j++)
        {
            freq[s[j] - 'A']++;

            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            int windowLength = j - i + 1;

            int replace = windowLength - maxFreq;

            if(replace <= k) maxLen = max(maxLen, windowLength);
        }
    }
    return maxLen;
}

int bet_way(string s, int k)
{
    unordered_map<char, int> freq;

    int l = 0, r = 0;
    int maxFreq = 0, maxLen = 0;

    while(r < s.size())
    {
        freq[s[r]]++;

        maxFreq = max(maxFreq, freq[s[r]]);

        while((r - l + 1) - maxFreq > k)
        {
            freq[s[l]]--;
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

int op_way(string s, int k)
{
    int l = 0, r = 0;
    int maxLen = 0, maxFreq = 0;

    unordered_map<char, int> freq;

    while(r < s.size())
    {
        freq[s[r]]++;

        maxFreq = max(maxFreq, freq[s[r]]);

        while((r - l + 1) - maxFreq > k)
        {
            freq[s[l]]--;
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

int main()
{
    string s = "BAABAABBBAAA";
    int ans = bet_way(s, 2);

    cout<<ans<<endl;
}