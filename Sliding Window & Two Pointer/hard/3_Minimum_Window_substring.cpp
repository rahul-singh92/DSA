#include <iostream>
using namespace std;

string bru_way(string s, string t)
{
    int minLen = INT_MAX;
    int sInd = -1;
    for(int i = 0; i < s.size(); i++)
    {
        vector<int> hash(256, 0);
        int count = 0;
        for(int j = 0; j < t.size(); j++)
        {
            hash[t[j]]++;
        }

        for(int j = i; j < s.size(); j++)
        {
            if(hash[s[j]] > 0) count++;
            hash[s[j]]--;  //Here we will reduce on inserting the elemnet;

            if(count == t.size())
            {
                if((j - i + 1) < minLen)
                {
                    minLen = j - i + 1;
                    sInd = i;
                    break;
                }
            }
        }
    }

    return s.substr(sInd, minLen);
}

string bet_way(string s, string t)
{
    vector<int> hash(256, 0);
    int l = 0, r = 0;
    int minLen = INT_MAX;
    int count = 0;
    int sInd = -1;
    for(int i = 0; i < t.size(); i++) hash[t[i]]++;

    while(r < s.size())
    {
        if(hash[s[r]] > 0) count++;
        hash[s[r]]--;

        while(count == t.size())
        {
            if(r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                sInd = l; 
            }
            hash[s[l]]++;

            if(hash[s[l]] > 0) count--;
            l++;
        }
        r++;
    }
    return sInd == -1 ? "" : s.substr(sInd, minLen);
}

int main()
{
    string s = "ddaaabbca";
    string t = "abc";

    string ans =  bet_way(s, t);
    cout<<ans<<endl;
}