#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* bru_way(vector<ListNode*>& lists)
{
    vector<int> allValue;
    for(auto list : lists)
    {
        while(list != NULL)
        {
            allValue.push_back(list -> val);
            list = list -> next;
        }
    }

    sort(allValue.begin(), allValue.end());

    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for(int val: allValue)
    {
        curr -> next = new ListNode(val);
        curr = curr -> next;
    }

    return dummy -> next;
}

class Compare
{
    public:
        bool operator()(ListNode* a, ListNode* b)
        {
            return a -> val > b -> val;
        }
};

ListNode* op_way(vector<ListNode*>& lists)
{
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    for(auto list: lists)
    {
        if(list != NULL)
        {
            pq.push(list);
        }
    }

    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    while(!pq.empty())
    {
        ListNode* smallest = pq.top();
        pq.pop();

        tail -> next = smallest;
        tail = tail -> next;

        if(smallest -> next != NULL)
        {
            pq.push(smallest -> next);
        }
    }

    return dummy -> next;
}

int main()
{
    ListNode* a = new ListNode(1);
    a -> next = new ListNode(4);
    a -> next -> next = new ListNode(5);

    ListNode* b = new ListNode(1);
    b -> next = new ListNode(3);
    b -> next -> next = new ListNode(4);

    ListNode* c = new ListNode(2);
    c -> next = new ListNode(6);

    vector<ListNode*> lists = {a, b, c};

    ListNode* result = op_way(lists);

    while(result)
    {
        cout<<result -> val<<" ";
        result = result -> next;
    }
    cout<<endl;
}