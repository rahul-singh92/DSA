#include <iostream>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool static comp(Item a, Item b)
{
    double r1 = (double) a.value / (double) a.weight;
    double r2 = (double) b.value / (double) b.weight;

    return r1 > r2;
}

double op_way(int W, Item arr[], int n)
{
    sort(arr, arr + n, comp);

    int curWeight = 0;
    double finalvalue = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else
        {
            // If cant be added then take the fractional part
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight * (double) remain);
            break;
        }
    }
    return finalvalue;
}

int main()
{
    int weight = 50;

    Item arr[3] = { {100, 20}, {60, 10}, {120, 30} };

    double ans = op_way(weight, arr, 3);

    cout<<ans<<endl;
}