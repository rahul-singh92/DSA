#include <iostream>
#include <string>
using namespace std;

// string wo_ca(string s)
// {
//     vector<string> words;
//     string word = "";
//     for(int i = 0; i < s.size(); i++)
//     {
//         if(s[i] != ' ') word += s[i];
//         else if(!word.empty())
//         {
//             words.push_back(word);
//             word = "";
//         }
//     }
//     if(!word.empty()) words.push_back(word);

//     reverse(words.begin(), words.end());
//     string result = "";
//     for(int i = 0; i < words.size(); i++)
//     {
//         result += words[i];
//         if(i < words.size() - 1) result += " ";
//     }
//     return result;
// }

string op_ca(string s)
{
    string result = "";

    int i = s.size() - 1;
    while(i >= 0)
    {
        while(i >= 0 && s[i] == ' ') i--;
        if(i < 0) break;

        int end = i;

        while(i >= 0 && s[i] != ' ') i--;
        string word = s.substr(i + 1, end - i);

        if(!result.empty()) result += " ";
        
        result += word;
    }
    return result;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = op_ca(s);
    cout<<ans<<endl;
}