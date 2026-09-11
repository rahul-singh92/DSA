#include <iostream>
#include <set>
using namespace std;

int bruteCount(string& s)
{
    set<string> st;

    for(int i = 0; i < s.length(); i++)
    {
        string a = "";
        for(int j = i; j < s.length(); j++)
        {
            a += s[j];
            st.insert(a);
        }
    }
    return st.size() + 1;
}

struct Node
{
    Node* links[26] = {NULL};

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void add(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    Node* go(char ch)
    {
        return links[ch - 'a'];
    }
};

int countDistinctSubstring(string& s)
{
    int cnt = 0;
    Node* root = new Node();

    for(int i = 0; i < s.size(); i++)
    {
        Node* node = root;
        for(int j = i; j < s.size(); j++)
        {
            if(!node -> containsKey(s[j]))
            {
                cnt++;
                node -> add(s[j], new Node());
            }
            node = node -> go(s[j]);
        }
    }
    return cnt + 1;
}

int main()
{
    string s = "rahul";
    cout<<bruteCount(s)<<endl;
    // cout<<countDistinctSubstring(s)<<endl;
}