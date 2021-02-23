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
ll countBit(string bit, char ch)
{
    ll count = 0;
    for (ll i = 0; i < bit.size(); i++)
    {
        if (bit[i] == ch)
            count++;
    }
    return count;
}
int main()
{
    FastIO;
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;
        string bits;
        cin >> bits;
        ll zeroCounts = countBit(bits, '0');
        ll oneCounts = countBit(bits, '1');
        ll ans = INT_MAX;
        ll ans1 = zeroCounts * c0 + oneCounts * c1;
        ll ans2 = zeroCounts * c1 + oneCounts * c1 + h * zeroCounts;
        ll ans3 = zeroCounts * c0 + oneCounts * c0 + h * oneCounts;
        cout << min(ans1, min(ans2, ans3)) << endl;
    }
    return 0;
}