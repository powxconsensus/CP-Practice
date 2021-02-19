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

int ask(int l, int r)
{
    if (l >= r)
        return -1;
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    int ans;
    cin >> ans;
    return ans - 1;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    int smax = ask(0, n - 1);
    if (smax == 0 || ask(0, smax) != smax)
    {
        int l = smax, r = n - 1;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (ask(smax, m) == smax)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        cout << "! " << r + 1 << endl;
    }
    else
    {
        int l = 0, r = smax;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (ask(m, smax) == smax)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        cout << "! " << l + 1 << endl;
    }
    return 0;
}