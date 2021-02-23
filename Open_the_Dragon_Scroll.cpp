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
string numToBit(ll n, ll N)
{
    string ans = "";
    while (n)
    {
        if (n & 1)
            ans += '1';
        else
            ans += '0';
        n = n / 2;
    }
    if (ans.size() == N)
    {
        reverse(ans.begin(), ans.end());
        return ans;
    }
    while (ans.size() != N)
        ans += '0';
    reverse(ans.begin(), ans.end());
    return ans;
}
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
string onesFirst(ll n, ll oneCount)
{
    string ans = "";
    for (ll i = 0; i < oneCount; i++)
        ans += '1';
    for (ll i = 0; i < (n - oneCount); i++)
        ans += '0';
    return ans;
}
string zeroesFirst(ll n, ll zeroesCount)
{
    string ans = "";
    for (ll i = 0; i < zeroesCount; i++)
        ans += '0';
    for (ll i = 0; i < (n - zeroesCount); i++)
        ans += '1';
    return ans;
}
ll xorOfBits(string aBits, string bBits)
{
    ll ans = 0;
    string res = "";
    for (ll i = 0; i < aBits.size(); i++)
        res += (aBits[i] == bBits[i] ? '0' : '1');
    // cout << res << endl;
    ll powExp = 0;
    for (ll i = res.size() - 1; i >= 0; i--, powExp++)
        ans += ((ll)(res[i] - '0') * pow(2, powExp));
    return ans;
}
int main()
{
    FastIO;
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        string aBits = numToBit(a, n);
        string bBits = numToBit(b, n);
        ll aBitsOnesCount = countBit(aBits, '1');
        ll aBitsZeroesCount = n - aBitsOnesCount;
        ll bBitsOnesCount = countBit(bBits, '1');
        ll bBitsZeroesCount = n - bBitsOnesCount;
        // cout << numToBit(a, n) << " " << numToBit(b, n) << endl;
        // cout << countBit(numToBit(a, n), '1') << endl;
        string res = "";
        // cout << onesFirst(n, aBitsOnesCount) << endl;
        ///////Option one when one first in a /////////
        string newA = onesFirst(n, aBitsOnesCount);
        string newB = zeroesFirst(n, bBitsZeroesCount);
        ll num1 = xorOfBits(newA, newB);
        // cout << newA << " " << newB << endl;
        // cout << xorOfBits(newA, newB) << endl;
        ///////Option one when one first in a /////////
        newA = onesFirst(n, bBitsOnesCount);
        newB = zeroesFirst(n, aBitsZeroesCount);
        ll num2 = xorOfBits(newA, newB);
        cout << max(num1, num2) << endl;
    }
    return 0;
}