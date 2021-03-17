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
    ll n;
    cin >> n;
    vector<vector<ll>> pt(2 * n + 1, vector<ll>(2 * n + 1, -1));
    ll start = 0, inL = n, value = 0, inR = n;
    for (ll i = 0; i < 2 * n + 1; i++)
    {
        ll l = inL, r = inR;
        value = 0;
        while (l < r)
        {
            pt[i][l] = pt[i][r] = value;
            value++;
            l++;
            r--;
        }
        pt[i][l] = pt[i][r] = value;
        if (i < n)
        {
            inL--;
            inR++;
        }
        else
        {
            inL++;
            inR--;
        }
    }
    for (ll i = 0; i < 2 * n + 1; i++)
    {
        for (ll j = 0; j < 2 * n + 1; j++)
        {
            if (pt[i][j] == -1)
            {
                if (j <= n - 1)
                    cout << "  ";

                continue;
            }
            cout << pt[i][j];
            if (j < 2 * n && pt[i][j + 1] != -1)
                cout << " ";
        }
        cout << endl;
    }
}