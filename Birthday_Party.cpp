//tatti question, chutiya codechef and problem setter
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
    lli a, x, y, z;
    cin >> a >> x >> y >> z;
    vector<lli> candle(x), ballon(y), cake(z);
    for (ll i = 0; i < x; i++)
        cin >> candle[i];
    for (ll i = 0; i < y; i++)
        cin >> ballon[y];
    for (ll i = 0; i < z; i++)
        cin >> cake[i];
    sort(candle.begin(), candle.end());
    sort(ballon.begin(), ballon.end());
    sort(cake.begin(), cake.end());
    lli ans = INT_MIN;
    for (ll i = 0; i < x; i++)
    {
        for (ll j = 0; j < y; j++)
        {
            for (ll k = 0; k < z; k++)
            {
                lli cost = candle[i] + ballon[j] + cake[k];
                if (cost <= a)
                    ans = max(ans, cost);
            }
        }
    }
    if (ans == INT_MIN)
        cout << -1 << endl;
    else
    {
        ans = a - ans;
        cout << ans << endl;
    }
    return 0;
}