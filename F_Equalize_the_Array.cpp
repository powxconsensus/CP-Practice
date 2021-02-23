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
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n, x;
        cin >> n;
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> x;
            mp[x]++;
        }
        vector<ll> f;
        for (auto it : mp)
            f.push_back(it.second);
        sort(f.begin(), f.end());
        ll leftQuan = 0;
        for (ll i = 0; i < f.size(); i++)
            leftQuan = max(leftQuan, (f[i] * (f.size() - i)));
        cout << n - leftQuan << endl;
        ///////////////////////////////////////
        //ll ans = INT_MAX;
        // while (low < high)
        // {
        // ll midC = low + (high - low) / 2;
        // for (ll midC = 1; midC <= n; midC++)
        // {
        //     ll op = 0;
        //     for (auto it : mp)
        //     {
        //         if (it.second < midC)
        //             op += it.second;
        //         else
        //             op += (it.second - midC);
        //     }
        //     ans = min(ans, op);
        // }
        // low = ans;
        // cout << low << endl;
        ///////////////////////////////////////////
    }
    return 0;
}