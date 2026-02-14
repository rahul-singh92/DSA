#include <iostream>
using namespace std;

int bru_way(string s)
{
    int count = 0;

    int n = s.length();

    for(int i = 0; i < n; i++)
    {
        vector<int> freq(3, 0);

        for(int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;

            if(freq[0] > 0 && freq[1] > 0 && freq[2] > 0) count++;
        }
    }
    return count;
}

int op_way(string s)
{
    vector<int> freq(3,0);

    int res = 0;

    int l = 0, r = 0;

    while(r < s.size())
    {
        freq[s[r] - 'a']++;

        while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
        {
            res += (s.length() - r);

            freq[s[l] - 'a']--;
            l++;
        }
        r++;
    }
    return res;
}

int main()
{
    string s = "abcba";
    int ans = op_way(s);

    cout<<ans<<endl;
}