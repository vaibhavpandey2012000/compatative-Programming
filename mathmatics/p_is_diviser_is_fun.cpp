
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define be begin()
#define en end()
#define all(x) (x).begin(),(x).end()
#define alli(a, n, k) (a+k),(a+n+k)
#define REP(i, a, b, k) for(__typeof(a) i = a;i < b;i += k)
#define REPI(i, a, b, k) for(__typeof(a) i = a;i > b;i -= k)
#define REPITER(it, a) for(__typeof(a.begin()) it = a.begin();it != a.end(); ++it)
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define eps 1e-6
#define pi 3.141592653589793
using namespace std;
template<class T> inline T gcd(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
template<class T> inline T mod(T x) { if(x < 0) return -x; else return x; }
typedef vector<int> VII;
typedef vector<ll> VLL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<int, PII > PPII;
typedef vector< PII > VPII;
typedef vector< PPII > VPPI;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX = 1e6 + 5;
ll A[MAX];
ll mpow (ll a, ll b, ll c) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % c;
        b >>= 1;
        a = (a *a) % c;
    }
    return res;
}
int main(int argc, char* argv[])
{
   
    ll pro = 1, x, ans = 1, pro1;
    int n;
    cin >> n;
    REP(i, 0, n, 1) {
        cin >> A[i];
        pro = (pro * (A[i] + 1)) % MOD;
    }
    REP(i, 0, n, 1) {
        pro1 = (pro * mpow(A[i]+1, MOD-2, MOD)) % MOD;
        x = (A[i] * (A[i]+1)) % MOD;
        x = (x * mpow(2, MOD-2, MOD)) % MOD;
        ans = (ans * ((pro1*x + 1) % MOD)) % MOD;
    }
    cout << ans << endl;
    return 0;
}