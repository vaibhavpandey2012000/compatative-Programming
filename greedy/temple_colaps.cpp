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
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		   // cin>>test;
		    while(test--){
		    	int n;
		    	cin>>n;
		    	vector<int>xx,yy;
		    	xx.PB(0);
		    	yy.PB(0);
		    	for(int i=0;i<n;i++)
		    	{
		    		int xxx,yyy;
		    		cin>>xxx>>yyy;
		    		xx.PB(xxx);
		    		yy.PB(yyy);
		    	}
		    	sort(ALL(xx));
		    	sort(ALL(yy));
		    	// for(int i=0;i<=n;i++)
		    	// {
		    	// 	cout<<xx[i]<<"-"<<yy[i]<<endl;
		    	// }
		    	vector<int>dx,dy;
		    	for(int i=1;i<=n;i++)
		    	{
		    		int t1=xx[i]-xx[i-1]-1;
		    		int t2=yy[i]-yy[i-1]-1;
		    		dx.PB(t1);
		    		dy.PB(t2);
		    	}
		    	// for(int i=0;i<n;i++)
		    	// {
		    	// 	cout<<dx[i]<<"-"<<dy[i]<<endl;
		    	// }
		    	int maxx=dx[0],maxy=dy[0];
		    	for(int i=1;i<n;i++)
		    	{
		    		if(maxx<dx[i])
		    		{
		    			maxx=dx[i];
		    		}
		    	}
		    	for(int i=1;i<n;i++)
		    	{
		    		if(maxy<dy[i])
		    		{
		    			maxy=dy[i];
		    		}
		    	}
		    	cout<<maxx*maxy<<endl;
		    }
	    }