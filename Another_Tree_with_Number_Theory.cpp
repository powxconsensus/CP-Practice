#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <climits>

using namespace std;
#define ll long int
class ChildAndCount
{
public:
    vector<ll> childList;
    ll itsCount;
    ll rejectedWorkByHisself;
    ll rejectedWorkNotByHisself;
    ChildAndCount()
    {
        itsCount = 0;
        rejectedWorkByHisself = 0;
        rejectedWorkNotByHisself = 0;
    }
};
ll CalBeforeHand(vector<ChildAndCount> &List, ll root, ll workLeft)
{
    if (List[root].itsCount == 0)
    {
        List[root].rejectedWorkNotByHisself = 0;
        List[root].rejectedWorkByHisself = 0;
        return 0;
    }
    if (workLeft % List[root].itsCount == 0)
    {
        ll workDivided = workLeft / List[root].itsCount;
        for (auto it : List[root].childList)
        {
            // cout << "Root: " << root << " " << it << endl;
            List[root].rejectedWorkNotByHisself += CalBeforeHand(List, it, workDivided);
        }
        return List[root].rejectedWorkNotByHisself;
    }
    List[root].rejectedWorkByHisself = workLeft;
    return workLeft;
}
int main()
{
    ll n, q;
    cin >> n;
    vector<ChildAndCount> List(n + 1);
    for (ll i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        List[x].itsCount++;
        List[x].childList.push_back(i);
    }
    // CalBeforeHand(List, 1, 20);
    //////////////////////////////
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << List[i].itsCount << endl;
    //     cout << "Child: ";
    //     for (auto it : List[i].childList)
    //     {
    //         cout << it << " ";
    //     }
    //     cout << endl;
    //     cout << "byhimself: " << List[i].rejectedWorkByHisself << endl;
    //     cout << "Notbyhimself: " << List[i].rejectedWorkNotByHisself << endl;
    //     cout << endl;
    // }
    //////////////////////////////
    cin >> q;
    while (q--)
    {
        ll v, w;
        cin >> v >> w;
        for (ll i = 1; i <= n; i++)
        {
            List[i].rejectedWorkByHisself = 0;
            List[i].rejectedWorkNotByHisself = 0;
        }
        CalBeforeHand(List, v, w);
        cout << List[v].rejectedWorkNotByHisself + List[v].rejectedWorkByHisself << endl;
    }
}