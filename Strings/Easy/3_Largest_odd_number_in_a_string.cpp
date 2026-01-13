#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//This is using "stoi()"
// int us_string_to_int(string s)
// {
//     int lar = INT_MIN;
//     for(int i = 0; i < s.size(); i++)
//     {
//         string num = "";
//         for(int j = i; j < s.size(); j++)
//         {
//             num += s[j];
//             if(stoi(num) % 2 != 0)
//             lar = max(lar, stoi(num));
//         }
//     }
//     return lar;
// }

string tuf_way(string s)
{
    int index = -1;

    //Find the last odd digit in the string
    int i;
    for(i = s.size() - 1; i >= 0 ;i--)
    {
        if((s[i] - '0') % 2 == 1)
        {
            index = i;
            break;
        }
    }

    i = 0;
    while(i <= index && s[i] == '0') i++;
    
    return s.substr(i, index - i + 1);
}

int main()
{
    string s;
    getline(cin, s);
    string ans = tuf_way(s);
    cout<<ans<<endl;
}