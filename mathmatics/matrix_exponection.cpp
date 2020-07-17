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
		ll k;
		vector<ll>a,b,c;
		ll num,n;
		//using boost::lexical_cast;
		//using boost::bad_lexical_cast;
		vector<vector<ll> > multiply(vector<vector<ll> A,ll p)
		vector<vector<ll> > power(vector<vector<ll> A,ll p)
		{
			if(p==1)
			{
				return A;
			}
			if(p&1)
			{
				return multiply(A,power(A,p-1));
			}
			else
			{
				vector< vector< ll > > X=power(A,p/2);
				return multiply(X,X);
			}
		}
		ll compute(ll n)
		{
			if(n==0)
				return 0;
			// suppose n<=k
			if(n<=k)
			{
				return b[n-1];
			}
			vector<ll> F1(k+1);
			REP(i,1,k+1)
			{
				F1[i]=b[i-1];
			}

			//2.transformation matrix
			vector<vector<ll> > T(k+1,vector<ll>(k+1));
			for(int i=1;i<=k;i++)
			{
				for(int j=1;j<=k;j++)
				{
					if(i<k)
					{
						if(j==(i+1))
							T[i][j]=1;
						else
							T[i][j]=0;
						continue;
					}
					T[i][j]=c[k-j];
				}
			}

			//3. colclute power
			T=power(T,n-1);
		}
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		    cin>>test;
		    while(test--){
		    	cin<<k;
		    	for(int i=0;i<k;i++)
		    	{
		    		cin>>num;
		    		b.PB(num);
		    	}
		    	for(int i=0;i<k;i++)
		    	{
		    		cin>>num;
		    		c.PB(num);
		    	}
		    	cin>>n;
		    	cout<<compute(n)<<endl;
		    	b.clear();
		    	c.clear();
		    }
	    }