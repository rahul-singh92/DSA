#include <iostream>
using namespace std;

// string wo_ca(string s)
// {
//     int n = s.size();
//     vector<string> words;

//     int start , end;
//     int i = 0;
//     while(i < n)
//     {
//         while(i < n && s[i] == ' ') i++;

//         if(i >= n) break;

//         start = i;

//         while(i < n && s[i] != ' ') i++;
//         end = i - 1;

//         words.push_back(s.substr(start, end - start + 1));
//     }

//     string ans = "";

//     for(int i = words.size() - 1; i >= 0; i--)
//     {
//         ans += words[i];
//         if(i != 0) ans.push_back(' ');
//     }
//     return ans;
// }

void reverseString(string &s, int start, int end) 
{
    while (start < end) swap(s[start++], s[end--]);
}
string op_wa(string s)
{
    int n = s.size();

    reverseString(s, 0, n - 1);

    int i = 0, j = 0, start = 0, end = 0;
    while(j < n)
    {
        while(j < n && s[j] == ' ') j++;
        if(j == n) break;

        start = i;

        while(j < n && s[j] != ' ') s[i++] = s[j++];

        end = i - 1;

        reverseString(s, start, end);

        if(j < n) s[i++] = ' ';
    }
    if(i > 0 && s[i - 1] == ' ') i--;

    return s.substr(0, i);
}

int main()
{
    string s;
    getline(cin, s);
    string ans = op_wa(s);
    cout<<ans;
}