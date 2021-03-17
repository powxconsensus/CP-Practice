#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
    ll k;
    string str;
    cin >> k;
    cin >> str;
    ll len = str.length();
    map<char, ll> mp;
    for (ll i = 0; i < len; i++)
        mp[str[i]]++;
    for (auto it : mp)
        if (it.second % k != 0)
        {
            cout << -1 << endl;
            return 0;
        }
    string ans = "", res = "";
    ll reLen = len / k;
    for (auto it : mp)
    {
        for (ll i = 0; i < it.second / k; i++)
            ans += it.first;
    }
    // ll devLen = ans.length();
    // string temp = ans;
    // while (ans.length() != reLen)
    //     ans += temp;
    // ll nMP = mp.size() - 1;
    for (ll i = 0; i < k; i++)
        res += ans;
    cout << res << endl;
}