#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
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
        string s, p, t;
        cin >> s >> t >> p;
        //s->t
        vector<ll> countS(26, 0), countP(26, 0), countT(26, 0);
        ll jIn = 0;
        bool flag = true;
        if (s.length() > t.length())
        {
            cout << "NO\n";
            continue;
        }
        for (ll i = 0; i < s.length(); i++)
        {
            bool ok = false;
            for (; jIn < t.length(); jIn++)
                if (s[i] == t[jIn])
                {
                    jIn++;
                    ok = true;
                    break;
                }
            if (!ok)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            cout << "NO\n";
            continue;
        }
        for (auto it : s)
            countS[it - 'a']++;
        for (auto it : t)
            countT[it - 'a']++;
        for (auto it : p)
            countP[it - 'a']++;

        for (ll i = 0; i < 26; i++)
        {
            if (countT[i] == 0)
            {
                if (countS[i] > 0)
                {
                    flag = false;
                    break;
                }
                continue;
            }
            if ((countS[i] + countP[i]) < countT[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}