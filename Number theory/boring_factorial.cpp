/*
	a!%p=?
	where 
	a,p are long long
	p prime number
*/
		#include<bits/stdc++.h>
		using namespace std;

		#define ll long long
		#define ld long double
		#define pi pair<int,int>
		#define pl pair<ll,ll>
		#define vi vector<int> 
		#define vvi vector<vi>
		#define vvl vector<vl>
		#define vl vector<ll>
		#define vpi vector<pi> 
		#define vpl vector<pl>

		#define PB emplace_back
		#define MP make_pair
		#define SZ(x) (ll)x.size()
		#define SS second
		#define FF first

		#ifdef LOCAL
		#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

		void err(istream_iterator<string> it) {}
		template<typename T, typename... Args>
		void err(istream_iterator<string> it, T a, Args... args) {
			cerr << *it << " = " << a << endl;
			err(++it, args...);
		}
		#define debugVec(a) cout<<"#### = "<<#a<<endl; for(auto x:a) cout<<x<<" "; cout<<endl;
		#define debug(a) cout<<"#### = "<<#a<<endl; for(auto x:a){ cout<<x.FF<<" "<<x.SS<<endl;}
		#endif

		#ifdef ONLINE_JUDGE
		#define error(args...)
		#define debugVec(a) 
		#define debug(a)
		#endif

		#define endl "\n"
		#define MOD 1000000007
		#define MAX 100010

		#define FILL(a,x) memset(x,a,sizeof x)
		#define ALL(x) x.begin(),x.end()
		#define REP(i,a,n) for(ll i=a;i<n;++i)
		#define REPR(i,n,b) for(ll i=n;i>=b;i--)
		#define tr(x, it) for(typeof(x.begin()) it = x.begin(); it != x.end(); it++)
		 
		using namespace std;
		//using boost::lexical_cast;
		//using boost::bad_lexical_cast;
		ll pow(ll a,ll b,ll m)
		{
			if(b==0)
			{
				return 1;
			}
			ll ans=pow(a,b/2,m);
			ans=((ans%m)*(ans%m))%m;
			if(b&1) ans=(ans*a)%m;
			return ans%m;
		}
		void solve(ll n,ll p)
		{
			if(n>=p)
			{
				cout<<"0"<<endl;
				return;
			}
			else
			{
				ll ans=-1;
				for(ll i=(n+1);i<=(p-1);i++)
				{
					ll nm=pow(i,(p-2),p);
					nm=nm%p;
					ans=(ans*nm)%p;
				}
				cout<<(ans+p)%p<<endl;
			}
		}
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		    cin>>test;
		    while(test--){
		    	ll a,b;
		    	cin>>a>>b;
		    	solve(a,b);
		    }
	    }