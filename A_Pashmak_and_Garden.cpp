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

int main()
{
    ll x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    if (y1 == y2)
    {
        ll sideLen = abs(x2 - x1);
        if (y1 + sideLen <= 1000 && y2 + sideLen <= 1000)
            cout << x1 << " " << (y1 + sideLen) << " " << x2 << " " << (y2 + sideLen) << endl;
        else if (y1 - sideLen >= -1000 && y2 - sideLen >= -1000)
            cout << x1 << " " << (y1 - sideLen) << " " << x2 << " " << (y2 - sideLen) << endl;
        else
            cout << -1 << endl;
    }
    else if (x1 == x2)
    {
        ll sideLen = abs(y2 - y1);
        if (x1 + sideLen <= 1000 && x2 + sideLen <= 1000)
            cout << (x1 + sideLen) << " " << y1 << " " << (x2 + sideLen) << " " << y2 << endl;
        else if (x1 - sideLen >= -1000 && x2 - sideLen >= -1000)
            cout << (x1 - sideLen) << " " << y1 << " " << (x2 - sideLen) << " " << y2 << endl;
        else
            cout << -1 << endl;
    }
    else
    {
        ll sideLen = abs(x2 - x1);
        if (sideLen != abs(y2 - y1))
        {
            cout << -1 << endl;
            return 0;
        }
        if (y1 < y2)
        {
            if ((y1 + sideLen) <= 1000 && (y2 - sideLen) >= -1000)
                cout << x1 << " " << (y1 + sideLen) << " " << x2 << " " << (y2 - sideLen) << endl;
            else
                cout << -1 << endl;
        }
        else
        {
            if ((y1 - sideLen) >= -1000 && (y2 + sideLen) <= 1000)
                cout << x1 << " " << (y1 - sideLen) << " " << x2 << " " << (y2 + sideLen) << endl;
            else
                cout << -1 << endl;
        }
    }
}