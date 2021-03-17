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
#define ll long long int
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
        return (f[n] * modInverse(f[r], m) % m * modInverse(f[n - r], m) % m) %
               m;
    }
    lli nPr(lli n, lli r)
    {
        if (r == 0)
            return 1;
        return (f[n] * modInverse(f[n - r], m) % m) % m;
    }
};
void countLucky(string str, vector<ll> &mp, const ll &limit, const ll &l,
                const ll &r)
{
    ll num1 = stoll(str + "7");
    if (num1 > limit)
        return;
    if (num1 >= l)
        mp.push_back(num1);
    countLucky(str + "7", mp, limit, l, r);
    ll num2 = stoll(str + "4");
    if (num2 > limit)
        return;
    if (num2 >= l)
        mp.push_back(num2);
    countLucky(str + "4", mp, limit, l, r);
}

ll countDigit(ll x)
{
    ll ans = 0;
    while (x)
    {
        x /= 10;
        ans++;
    }
    return ans;
}
int main()
{
    FastIO;
    ll l, r;
    scanf("%lld %lld", &l, &r);
    vector<ll> mp;
    ll limit = countDigit(max(l, r));
    limit = pow(10, limit + 1);
    countLucky("", mp, limit, l, r);
    sort(mp.begin(), mp.end());
    ll ans = 0, val = 0;
    if (r <= mp[0])
    {
        cout << (r - l + 1) * mp[0] << "\n";
        return 0;
    }
    ans += (mp[0] - l + 1) * mp[0];
    ll rem = r - l + 1;
    rem -= (mp[0] - l + 1);
    //
    for (ll i = 1; i < mp.size(); i++)
    {
        ll x = mp[i] - mp[i - 1];
        ans += min(x, rem) * mp[i];
        rem -= min(x, rem);
        if (rem <= 0)
            break;
    }
    cout << ans << endl;
}
