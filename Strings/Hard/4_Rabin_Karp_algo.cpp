#include <iostream>
using namespace std;

#define d 256

void rabinKarp(string pattern, string text, int q)
{
    int m = pattern.length();
    int n = text.length();
    int i, j;
    int p = 0; // hash value for the pattern
    int t = 0; // hash value for the text window
    int h = 1;

    // h will be pow(d, m - 1) % q
    for(i = 0; i < m - 1; i++)
        h = (h * d) % q;
    
    for(i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for(i = 0; i <= n - m; i++)
    {
        if(p == t)
        {
            bool match = true;
            for(j = 0; j < m; j++)
            {
                if(text[i+j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if(match)
            {
                cout<<i<<endl;
            }
        }

        if(i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if(t < 0)
                t = t + q;
        }
    }
}

int main()
{
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    
    int q = 101;
    rabinKarp(pattern, text, q);
}