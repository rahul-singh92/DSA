#include <iostream>
#include <string>
using namespace std;

int expandFromCenter(string s, int left, int right)
{
    while(left >= 0 && right < s.size() && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}
string op_way(string s)
{
    int start = 0, end = 0;

    for(int center = 0; center < s.size(); center++)
    {
        //Expand around odd length
        int lenOdd = expandFromCenter(s, center, center);

        //Expand around even length
        int lenEven = expandFromCenter(s, center, center + 1);

        int maxLen = max(lenOdd, lenEven);

        if(maxLen > end - start)
        {
            start = center - (maxLen - 1) / 2;
            end = center + maxLen / 2;
        }
    }

    return s.substr(start, end - start + 1);
}


int main()
{
    string s;
    getline(cin, s);
    string ans = op_way(s);
    cout<<ans<<endl;
}