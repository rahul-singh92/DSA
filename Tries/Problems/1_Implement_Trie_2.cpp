#include <iostream>
using namespace std;

struct Node
{
    Node* links[26] = {NULL};
    int end_width = 0, count_prefix = 0;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node* go(char ch)
    {
        return links[ch - 'a'];
    }

    void add(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    void increaseEnd()
    {
        end_width++;
    }

    void increasePrefix()
    {
        count_prefix++;
    }

    void deleteEnd()
    {
        end_width--;
    }

    void reducePrefix()
    {
        count_prefix--;
    }

    int getEnd()
    {
        return end_width;
    }

    int getPrefix()
    {
        return count_prefix;
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

        void insert(string word)
        {
            Node* node = root;
            for(char ch: word)
            {
                if(!node -> containsKey(ch))
                {
                    node -> add(ch, new Node());
                }
                node = node -> go(ch);
                node -> increasePrefix();
            }
            node -> increaseEnd();
        }

        int countWordsEqualTo(string word)
        {
            Node* node = root;

            for(char ch: word)
            {
                if(node -> containsKey(ch))
                {
                    node = node -> go(ch);
                }
                else
                {
                    return 0;
                }
            }
            return node -> getEnd();
        }

        int countWordsStartingWith(string word)
        {
            Node* node = root;
            for(char ch: word)
            {
                if(node -> containsKey(ch))
                {
                    node = node -> go(ch);
                }
                else
                {
                    return 0;
                }
            }
            return node -> getPrefix();
        }

        void erase(string word)
        {
            Node* node = root;

            for(char ch: word)
            {
                if(node -> containsKey(ch))
                {
                    node = node -> go(ch);
                    node -> reducePrefix();
                }
                else 
                {
                    return;
                }
            }
            node -> deleteEnd();
        }
};

int main()
{
    Trie* trie = new Trie();
    trie -> insert("apple");
    trie -> insert("apple");
    cout << "Inserting strings 'apple' twice into Trie" << endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie -> countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie -> countWordsStartingWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie -> erase("apple");
    cout << "Count Words Equal to 'apple': ";
    cout << trie -> countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie -> countWordsStartingWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie -> erase("apple");
    cout << "Count Words Starting With 'app': ";
    cout << trie -> countWordsStartingWith("app") << endl;
}