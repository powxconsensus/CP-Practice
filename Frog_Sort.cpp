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
        vector<ll> w(n);
        for (ll i = 0; i < n; i++)
            cin >> w[i];
        for (ll i = 0; i < n; i++)
        {
            cin >> x;
            mp[w[i]] = x;
        }
        ll count = 0;

        vector<ll> AllPos(20, -1);
        count = 0;
        for (ll i = 0; i < n; i++)
            AllPos[i] = w[i];
        for (ll i = 0; i < AllPos.size(); i++)
        {
            if (AllPos[i] != -1)
            {
                for (ll j = 0; j < i; j++)
                {
                    if (AllPos[j] != -1 && AllPos[j] > AllPos[i])
                    {
                        ll minJump = (i - j - 1) / mp[AllPos[j]] + 1;
                        ll newPos = minJump * mp[AllPos[j]] + j;
                        count += minJump;
                        if (AllPos[newPos] != -1)
                        {
                            ll xx = newPos;
                            ll xxV = AllPos[j];
                            while (AllPos[xx] != -1)
                            {
                                if (xxV < AllPos[xx])
                                {
                                    ll temp = AllPos[xx];
                                    AllPos[xx] = xxV;
                                    xxV = temp;
                                    xx += mp[temp];
                                    count++;
                                }
                                else
                                {
                                    xx += mp[xxV];
                                    count++;
                                }
                            }
                            AllPos[xx] = xxV;
                        }
                        else
                            AllPos[newPos] = AllPos[j];
                        AllPos[j] = -1;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}