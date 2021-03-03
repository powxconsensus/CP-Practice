#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <climits>
#include <stack>

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

bool checkReg(string str)
{
    stack<char> st;
    for (ll i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            st.push('(');
        else if (st.size() != 0)
            st.pop();
        else
            return false;
    }
    return (st.size() == 0);
}
bool recur(string str)
{
    string op = "()";
    for (ll i = 0; i < 2; i++)
    {
        for (ll j = 0; j < 2; j++)
        {
            for (ll k = 0; k < 2; k++)
            {
                string temp = "";
                for (ll m = 0; m < str.size(); m++)
                {
                    if (str[m] == 'A')
                        temp += op[i];
                    else if (str[m] == 'B')
                        temp += op[j];
                    else
                        temp += op[k];
                }
                // cout << temp << endl;
                if (checkReg(temp))
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    FastIO;
    ll tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        ll flag = false;
        if (!recur(str))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}