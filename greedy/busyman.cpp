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
		bool fxn(pi a,pi b)
		{
			return a.SS<b.SS;
		}
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		    cin>>test;
		    while(test--){
		    	int n;
		    	cin>>n;
		    	vpi v(n);
		    	REP(i,0,n)
		    	{
		    		int a,b;
		    		cin>>a>>b;
		    		v[i].FF=a;
		    		v[i].SS=b;
		    	}
		    	sort(ALL(v),fxn);
		    	// REP(i,0,n)
		    	// {
		    	// 	cout<<v[i].FF<<"--"<<v[i].SS<<endl;
		    	// }
		    	cout<<endl;
		    	int chack=v[0].SS,count=1;
		    	//cout<<v[0].FF<<"-"<<v[0].SS<<endl;
		    	for(int i=1;i<n;i++)
		    	{
		    		if(v[i].FF>=chack)
		    		{
		    			chack=v[i].SS;
		    			count++;
		    		//	cout<<v[i].FF<<"-"<<v[i].SS<<endl;
		    		}
		    	}
		    	cout<<count<<endl;
		    }
		 }
	    