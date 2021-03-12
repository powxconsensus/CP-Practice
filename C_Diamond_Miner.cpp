#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
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

int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll N;
        cin >> N;
        vector<pair<ll, ll>> diamond(N), miner(N);
        ll x, y, w = 0, z = 0;
        for (ll i = 0; i < 2 * N; i++)
        {
            cin >> x >> y;
            if (x == 0)
            {
                miner[w++] = {x, abs(y)};
            }
            else
            {
                diamond[z++] = {abs(x), y};
            }
        }
        sort(miner.begin(), miner.end(), greater<>());
        sort(diamond.begin(), diamond.end(), greater<>());
        double ans = 0.0;
        for (ll i = 0; i < N; i++)
        {
            ans += (double)sqrt(miner[i].second * miner[i].second +
                                diamond[i].first * diamond[i].first);
        }
        cout << fixed << setprecision(18) << ans << "\n";
    }
}