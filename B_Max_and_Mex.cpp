#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <set>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <ctime>

using namespace std;

#define mod 998244353
#define lli long long int
#define ll long long
#define li long int
#define FastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0)

class PNC
{
public:
    vector<unsigned lli> f;
    lli m;
    PNC(lli n, lli m = mod)
    {
        f.resize(n + 1);
        this->m = m;
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            f[i] = (i * f[i - 1]) % m;
        }
    }
    lli power(lli b, lli p, lli m = mod)
    {
        lli res = 1;
        while (p > 0)
        {
            if (p & 1)
                res = ((res % m) * (b % m)) % m;
            b = ((b % m) * (b % m)) % m;
            p = p >> 1;
        }
        return res;
    }
    lli modInverse(lli n, lli m = mod) { return power(n, m - 2, m); }
    lli factorial(lli n) { return f[n]; }
    lli nCr(lli n, lli r)
    {
        if (r == 0)
            return 1;
        return (f[n] * modInverse(f[r], m) % m * modInverse(f[n - r], m) % m) % m;
    }
    lli nPr(lli n, lli r)
    {
        if (r == 0)
            return 1;
        return (f[n] * modInverse(f[n - r], m) % m) % m;
    }
};
ll firstMissingPositive(vector<ll> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        while (arr[i] >= 0 && arr[i] < n && arr[i] != arr[arr[i]])
        {
            swap(arr[i], arr[arr[i]]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i)
        {
            return i;
        }
    }
    return n;
}

int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll N, Q, it;
        cin >> N >> Q;
        set<ll> v;
        vector<ll> vec;
        ll maxi = INT_MIN;
        for (ll i = 0; i < N; i++)
        {
            cin >> it;
            v.insert(it);
            vec.push_back(it);
            maxi = max(maxi, it);
        }
        if (Q == 0)
        {
            cout << v.size() << "\n";
            continue;
        }
        ll mex = firstMissingPositive(vec, N);
        if (mex > maxi)
        {
            cout << v.size() + Q << "\n";
        }
        else
        {
            ll temp = (mex + maxi - 1) / 2 + 1;
            if (v.find(temp) != v.end())
            {
                cout << v.size() << "\n";
            }
            else
            {
                cout << v.size() + 1 << "\n";
            }
        }
    }
}