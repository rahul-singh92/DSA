#include <iostream>
using namespace std;

class LRUCache
{
    public: 
        class Node
        {
            public:
                int key;
                int val;
                Node* next;
                Node* prev;

                Node(int _key, int _val)
                {
                    key = _key;
                    val = _val;
                }
        };
    
        Node* head = new Node(-1, -1);
        Node* tail = new Node(-1, -1);
        // Capactity of cache
        int cap;
        //Hash map to store key-node mapping
        unordered_map<int, Node*> m;

        LRUCache(int capacity)
        {
            cap = capacity;
            head -> next = tail;
            tail -> prev = head;
        }

        void addNode(Node* newNode)
        {
            Node* temp = head -> next;
            newNode -> next = temp;
            newNode -> prev = head;
            head -> next = newNode;
            temp -> prev = newNode;
        }

        void deleteNode(Node* delNode)
        {
            Node* delPrev = delNode -> prev;
            Node* delNext = delNode -> next;
            delPrev -> next = delNext;
            delNext -> prev = delPrev;
        }

        int get(int key_)
        {
            if(m.find(key_) != m.end())
            {
                Node* resNode = m[key_];
                int res = resNode -> val;
                //Remove old mapping
                m.erase(key_);
                //Move accessed node to front
                deleteNode(resNode);
                addNode(resNode);
                //Update map
                m[key_] = head -> next;
                return res;
            }
            return -1;
        }

        void put(int key_, int value)
        {
            if(m.find(key_) != m.end())
            {
                Node* existingNode = m[key_];
                m.erase(key_);
                deleteNode(existingNode);
            }
            if(m.size() == cap)
            {
                m.erase(tail -> prev -> key);
                deleteNode(tail -> prev);
            }

            addNode(new Node(key_, value));
            m[key_] = head -> next;
        }
};

int main()
{
     // Create cache with capacity 2
    LRUCache cache(2);

    // Put values in cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Get value for key 1
    cout << cache.get(1) << endl; 

    // Insert another key (evicts key 2)
    cache.put(3, 3);

    // Key 2 should be evicted
    cout << cache.get(2) << endl; 

    // Insert another key (evicts key 1)
    cache.put(4, 4);

    // Key 1 should be evicted
    cout << cache.get(1) << endl; 

    // Key 3 should be present
    cout << cache.get(3) << endl; 

    // Key 4 should be present
    cout << cache.get(4) << endl; 
}