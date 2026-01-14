#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int op_ca(string s)
{
    unordered_map<char, int> mpp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int sum = 0;
    char last = 'a';
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if((last == 'V' && s[i] == 'I') || (last == 'X' && s[i] == 'I') ||
           (last == 'L' && s[i] == 'X') || (last == 'C' && s[i] == 'X') ||
           (last == 'D' && s[i] == 'C') || (last == 'M' && s[i] == 'C')) sum -= mpp[s[i]];
        else sum += mpp[s[i]];
        last = s[i];
    }
    return sum;
}

int main()
{
    string s;
    getline(cin, s);
    int ans = op_ca(s);
    cout<<ans<<endl;
}