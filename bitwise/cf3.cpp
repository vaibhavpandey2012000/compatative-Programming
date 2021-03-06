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
		
int main()
{
	ll mod=1000000007;
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		ll arr[n];
		ll ans=1;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(int i=1;i<n;i++)
		{
			if(arr[i-1]&arr[i]!=arr[i])
			{
				ans=0;
				break;
			}
			ll t1=arr[i-1],t2=arr[i];
			int cnt=0;
			while(1)
			{
				int p1=t1&1;
				int p2=t2&1;
				if(p1==1 && p2==1)
				{
					cnt++;
				}
				t1=(t1>>1);
				t2=(t2>>1);
				if(t1==0 && t2==0) break;
			}
			ans=(ans*((1<<cnt)%MOD))%MOD;
		}
		cout<<ans<<endl;	
	}
}