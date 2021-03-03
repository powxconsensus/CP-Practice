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
        ll n, m, k;
        cin >> n >> m >> k;
        vector<string> str(n);
        for (ll i = 0; i < n; i++)
            cin >> str[i];
        vector<vector<ll>> mp(n, vector<ll>(m, 0));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
                mp[i][j] = (str[i][j] == '0') ? 0 : 1;
        }
        vector<vector<pair<ll, ll>>> vertical(n, vector<pair<ll, ll>>(m, {0, 0}));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (i == 0)
                {
                    if (mp[i][j] == 0)
                        vertical[i][j].first++;
                    else
                        vertical[i][j].second++;
                    continue;
                }
                vertical[i][j] = vertical[i - 1][j];
                if (mp[i][j] == 0)
                    vertical[i][j].first++;
                else
                    vertical[i][j].second++;
            }
        }
        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < m; j++)
        //     {
        //         cout << "{" << vertical[i][j].first << " " << vertical[i][j].second << "} ";
        //     }
        //     cout << endl;
        // }
        vector<vector<pair<ll, ll>>> horizontal(n, vector<pair<ll, ll>>(m, {0, 0}));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (i == 0)
                {
                    if (mp[i][j] == 0)
                        vertical[i][j].first++;
                    else
                        vertical[i][j].second++;
                    continue;
                }
                vertical[i][j] = vertical[i - 1][j];
                if (mp[i][j] == 0)
                    vertical[i][j].first++;
                else
                    vertical[i][j].second++;
            }
        }
    }
    return 0;
}