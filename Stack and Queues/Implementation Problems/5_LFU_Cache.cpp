#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int key, value, cnt;
    Node *next;
    Node *prev;

    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};

struct List
{
    int size;
    Node *head;
    Node *tail;

    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
        size++;
    }

    void removeNode(Node *delNode)
    {
        Node *delNext = delNode->next;
        Node *delPrev = delNode->prev;
        delNext->prev = delPrev;
        delPrev->next = delNext;
        size--;
    }
};

class LFUCache
{
private:
    map<int, Node *> keyNode;

    map<int, List *> freqListMap;

    int maxSizeCache;

    int minFreq;
    int curSize;

public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);

        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }

        List *nextHighFreqList = new List();

        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
        {
            nextHighFreqList = freqListMap[node->cnt + 1];
        }

        node->cnt += 1;

        nextHighFreqList->addFront(node);

        freqListMap[node->cnt] = nextHighFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);

            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSizeCache == 0)
            return;

        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            if (curSize == maxSizeCache)
            {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);

                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }

            curSize++;
            minFreq = 1;

            List *listFreq = new List();

            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }

            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

int main()
{
    // LFU Cache
    LFUCache cache(2);

    // Queries
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << " ";
    cache.put(3, 3);
    cout << cache.get(2) << " ";
    cout << cache.get(3) << " ";
    cache.put(4, 4);
    cout << cache.get(1) << " ";
    cout << cache.get(3) << " ";
    cout << cache.get(4) << " ";
}