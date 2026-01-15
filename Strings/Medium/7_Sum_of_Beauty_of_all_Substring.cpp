#include <iostream>
using namespace std;

int op_wa(string s)
{
    int sum = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        unordered_map<char, int> freq;
        for(int j = i; j < s.size(); j++)
        {
            freq[s[j]]++;

            int maxi = INT_MIN;
            int mini = INT_MAX;

            for(auto i: freq)
            {
                mini = min(mini, i.second);
                maxi = max(maxi, i.second);
            }

            sum += (maxi - mini);
        }
    }
    return sum;
}

int main()
{
    string s;
    getline(cin, s);
    int ans = op_wa(s);
    cout<<ans<<endl;
}