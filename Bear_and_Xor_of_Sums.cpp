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
ll koko(ll l, ll r, vector<ll> &BIT, ll p)
{
    ll i = p, sum = 0;
    //0-p
    while (i != 0)
    {
        sum += BIT[i];
        i = i & (i - 1);
    }
    //0-l
    i = l;
    ll ssum = 0;
    while (i != 0)
    {
        ssum += BIT[i];
        i = i & (i - 1);
    }
    return sum - ssum;
}
ll rec(vector<ll> &BIT, ll l, ll r, ll n, ll &ans, ll p)
{
    ans ^= BIT[p];
    if (l - 1 >= 0)
        ans ^= BIT[p] - BIT[l - 1];

    ll x = koko(l, r, BIT, p);
    ans ^= x;
    if (l + 1 <= r)
        x = koko(l + 1, r, BIT, p);
    ans ^= x;
    return 0;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> vec(n), BIT(n + 1, 0);
    for (ll i = 0; i < n; i++)
        cin >> vec[i];
    BIT[0] = 0;
    for (ll i = 1; i < n + 1; i++)
    {
        // ll parent = i - (((~i) + 1) & i); // x&(x-1) to flip right most set bit
        ll next = i;
        while (next < n + 1)
        {
            BIT[next] += vec[i - 1];
            next = (((~next) + 1) & next) + next;
        }
    }
    // for (ll i = 0; i < n + 1; i++)
    //     cout << BIT[i] << endl;
    ll ans = BIT[1];
    for (ll i = 2; i < n + 1; i++)
    {
        ll parent = i - (((~i) + 1) & i);
        ll next = i + (((~i) + 1) & i);
        cout << parent + 1 << " " << i << " " << ans << endl;
        rec(BIT, parent + 1, i, n, ans, i);
        cout << "ans: " << ans << endl;
    }
    // rec(ans, 2, BIT);
    cout << ans << endl;
}