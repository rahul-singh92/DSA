#include <iostream>
#include <string>
using namespace std;

int op_ca(string s, int n)
{
    int left = 0, res = 0;
    unordered_map<char, int> freq;

    for(int right = 0; right < s.size(); right++)
    {
        freq[s[right]]++;

        while(freq.size() > n)
        {
            freq[s[left]]--;
            if(freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }

        res += (right - left + 1);
    }
    return res;
}

int count_substring(string s, int n)
{
    //Exactly k = atMost(s, k) - atMost(s, k-1)
    return op_ca(s, n) - op_ca(s, n - 1);
}

int main()
{
    string s;
    int n;
    cin>>n;
    cin.ignore();
    getline(cin, s);
    int ans = count_substring(s, n);
    cout<<ans<<endl;
}