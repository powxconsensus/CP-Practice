#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <climits>

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

int main()
{
    FastIO;
    ll m, n;
    cin >> m >> n;
    string a, b;
    cin >> a >> b;
    ll minIn = 0;
    ll maxIn = 0;
    vector<ll> index;
    for (ll i = 0; i < a.size(); i++)
        if (a[i] == b[0])
        {
            minIn = i;
            break;
        }
    index.push_back(minIn);
    for (ll i = a.size() - 1; i >= 0; i--)
        if (a[i] == b[b.size() - 1])
        {
            maxIn = i;
            break;
        }
    for (ll i = 1; i < b.size() - 1; i++)
    {
        for (ll j = index[index.size() - 1] + 1; j < (a.size() - 1); j++)
        {
            if (a[j] == b[i])
            {
                index.push_back(j);
                break;
            }
        }
    }
    index.push_back(maxIn);
    ll maxxx = INT_MIN;
    for (ll i = 0; i < index.size() - 1; i++)
    {
        if (abs(index[i + 1] - index[i]) > maxxx)
        {
            maxxx = abs(index[i + 1] - index[i]);
        }
    }
    // for (auto it : index)
    //     cout << it << " ";
    // cout << endl;
    // cout << maxxx << endl;
    /////////////////////////////////////////////////
    index.clear();
    index.push_back(maxIn);
    for (ll i = b.size() - 2; i > 0; i--)
    {
        for (ll j = index[index.size() - 1] - 1; j > 0; j--)
        {
            if (a[j] == b[i])
            {
                index.push_back(j);
                break;
            }
        }
    }
    index.push_back(minIn);
    ll maxxx1 = INT_MIN;
    for (ll i = 0; i < index.size() - 1; i++)
    {
        // cout << index[i + 1] << " " << index[i] << endl;
        if (abs(index[i + 1] - index[i]) > maxxx1)
        {
            maxxx1 = abs(index[i + 1] - index[i]);
        }
    }
    // for (auto it : index)
    //     cout << it << " ";
    // cout << endl;
    cout << max(maxxx, maxxx1) << endl;
    return 0;
}