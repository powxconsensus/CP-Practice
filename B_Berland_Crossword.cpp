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
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
bool checkTwo(ll u, ll r, ll d, ll l, ll n)
{
    return (u == n && (r >= 1) && (l >= 1) && d <= (n - 2));
}
bool checkOne(ll u, ll r, ll d, ll l, ll n)
{
    return (u == (n - 1) && (r >= 1 || l >= 1) && d <= (n - 2));
}
bool Chutiye2N(ll u, ll r, ll d, ll l, ll n)
{
    return (u == n && r == n) && l >= 1 && d >= 1;
}
bool Chutiye1N(ll u, ll r, ll d, ll l, ll n)
{
    return (u == (n - 1) && r == (n - 1)) ? true : false;
}
bool alter(ll u, ll r, ll d, ll l, ll n)
{
    if ((u == n && d == n) && l >= 2 && r >= 2)
        return true;
    if ((u == n && d == n - 1) && ((l >= 1 && r >= 2) || (l >= 2 && r >= 1)))
        return true;
    if ((u == n && d == n) && l >= 2 && r >= 2)
        return true;

    return false;
}
bool check3(ll u, ll r, ll d, ll l, ll n)
{
    if (u == n && r == n && d == n && l >= 2)
        return true;
    // if(u == n-1 && )
    return false;
}
int main()
{
    FastIO;
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        ll n2d = n - 2;
        ll n1d = n - 1;
        if (u <= n2d && r <= n2d && d <= n2d && l <= n2d)
            yes;
        else if (checkTwo(u, r, d, l, n) || checkTwo(l, u, r, d, n) || checkTwo(d, l, u, r, n) || checkTwo(r, d, l, u, n))
            yes;
        else if (checkOne(u, r, d, l, n) || checkOne(l, u, r, d, n) || checkOne(d, l, u, r, n) || checkOne(r, d, l, u, n))
            yes;
        else if (Chutiye2N(u, r, d, l, n) || Chutiye2N(l, u, r, d, n) || Chutiye2N(d, l, u, r, n) || Chutiye2N(r, d, l, u, n))
            yes;
        else if (Chutiye1N(u, r, d, l, n) || Chutiye1N(l, u, r, d, n) || Chutiye1N(d, l, u, r, n) || Chutiye1N(r, d, l, u, n))
            yes;
        else if (alter(u, r, d, l, n) || alter(l, u, r, d, n) || alter(d, l, u, r, n) || alter(r, d, l, u, n))
            yes;
        else if (check3(u, r, d, l, n) || check3(l, u, r, d, n) || check3(d, l, u, r, n) || check3(r, d, l, u, n))
            yes;
        else
            no;
    }
    return 0;
}