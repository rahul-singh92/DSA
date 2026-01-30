#include <iostream>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
    int n = s.length();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(n + 1, false);
    dp[0] = true;  //Empty string always segmented
    int maxLen = 0;

    //Find the maximum length of the word in the dictionary
    for(auto word: wordDict)
    {
        maxLen = max(maxLen, (int)word.size());
    }

    //DP to check if the string can be segmented
    for(int i = 1; i <=n; i++)
    {
        for(int j = max(0, i - maxLen); j < i; j++)
        {
            if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main()
{
    string s = "leetcode";
    vector<string> dict = {"leet", "code"};

    if(wordBreak(s, dict))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False";
    }
}