#include <iostream>
using namespace std;

struct Node
{
    Node* links[26] = {NULL};
    bool flag = false;

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

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    private:
        Node* root;
    public:
        Trie()
        {
            root = new Node();
        }

        void insert(string& word)
        {
            Node* node = root;

            for(char ch: word)
            {
                if(!node -> containsKey(ch))
                {
                    node -> add(ch, new Node());
                }
                node = node -> go(ch);
            }
            node -> setEnd();
        }

        bool checkIfPrefixExists(string& word)
        {
            Node* node = root;

            for(char ch: word)
            {
                if(node -> containsKey(ch))
                {
                    node = node -> go(ch);
                    if(node -> isEnd() == false) return false;
                }
                else return false;
            }
            return true;
        }
};

string completeString(int n, vector<string>& arr)
{
    Trie trie;
    
    for(string s: arr)
    {
        trie.insert(s);
    }
    string longest = "";
    for(string s: arr)
    {
        if(trie.checkIfPrefixExists(s))
        {
            if(s.size() > longest.length())
            {
                longest = s;
            }
            else if(s.size() == longest.length() && s < longest)
            {
                longest = s;
            }
        }
    }


    if(longest == "") return "None";
    return longest;
}

int main()
{
    int n = 5;

    vector<string> arr = {"n", "nin", "ninj", "ninja", "nil", "ni" };

    cout << completeString(n, arr) << endl;
}