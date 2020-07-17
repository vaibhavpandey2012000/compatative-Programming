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
		long solve(int a[4][4])
		{
			long ans=INT_MIN;
			REP(i,0,4)
			{
				REP(j,0,4)
				{
					REP(k,0,4)
					{
						REP(l,0,4)
						{
							set<int>s;
							s.insert(i);
							s.insert(j);
							s.insert(k);
							s.insert(l);
							if(s.size()<4)
							{
								continue;
							}
							vl v;
							v.PB(a[0][i]);
							v.PB(a[1][j]);
							v.PB(a[2][k]);
							v.PB(a[3][l]);
							sort(ALL(v));
							long as=100*v[0]+75*v[1]+50*v[2]+25*v[3];
							for(int zz=0;zz<4;zz++)
							{
								if(v[i]==0)
									as-=100;
							}
							ans=max(ans,as);
						}
					}
				}
			}
			return ans;
		}
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		    cin>>test;
		    long ans=0;
		    while(test--){
		    	int n;
		    	cin>>n;
		    	int dp[4][4]={0};
		    	REP(i,0,n)
		    	{
		    		char ch;int p,t;
		    		cin>>ch>>p;
		    		t=int(ch-65);
		    		p=(p/3)-1;
		    		dp[t][p]++;
		    	}

		    		/*REP(j,0,4)
		    		{
		    			REP(k,0,4)
		    			{
		    				cout<<dp[j][k]<<" ";
		    			}
		    			cout<<endl;
		    		} */
		    	long pp=solve(dp);
		    	cout<<pp<<endl;
		    	 ans+=pp;
		    }
		    cout<<ans<<endl;
	    }