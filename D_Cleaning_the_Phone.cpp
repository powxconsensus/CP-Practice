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
        ll n, m;
        cin >> n >> m;
        vector<ll> A(n), B(n), B1, B2;
        for (ll i = 0; i < n; i++)
            cin >> A[i];
        for (ll i = 0; i < n; i++)
        {
            cin >> B[i];
            if (B[i] == 1)
                B1.push_back(A[i]);
            else
                B2.push_back(A[i]);
        }
        ll tempM = 0, ans = 0;
        bool flag = false;
        // cout << B1.size() << " " << B2.size() << endl;
        sort(B1.begin(), B1.end());
        sort(B2.begin(), B2.end());
        pair<ll, ll> mp(INT_MAX, INT_MAX);
        vector<vector<pair<ll, ll>>> dp(2, vector<pair<ll, ll>>(m + 1, mp));
        for (ll i = B1.size() - 1, j = 0; j <= m && i >= 0; j++)
        {
            if (j == 0)
            {
                dp[0][j].first = 0;
                dp[0][j].second = 0;
                continue;
            }
            if (dp[0][j - 1].second >= m)
            {
                dp[0][j] = dp[0][j - 1];
            }
            else
            {
                dp[0][j].first = dp[0][j - 1].first + 1;
                dp[0][j].second = dp[0][j - 1].second + B1[i];
                i--;
            }
        }
        for (ll i = 0; i < n; i++)
        {
            cout << dp[0][i].first << " " << dp[0][i].second << endl;
        }
        continue;
        if (dp[1][m].first == INT_MAX)
        {
            cout << -1 << endl;
            continue;
        }
        cout << dp[1][m].first << endl;
    }

    return 0;
}