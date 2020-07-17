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
		class graph{
			map<int,list<int> >adj;
		public:
			void addedge(int v,int u)
			{
				adj[v].push_back(u);
				adj[u].push_back(v);
			}
			void dfshelper(int node,map<int,bool>&visited)
			{
				visited[node]=true;
				for(auto child:adj[node])
				{
					if(!visited[child])
					{
						dfshelper(child,visited);
					}
				}
			}
			void dfs()
			{
				int comp=0;
				map<int,bool>visited;
				for(auto ele:adj)
				{
					int node=ele.FF;
					if(!visited[node])
					{
						comp++;
						dfshelper(node,visited);
					}
				//	cout<<"total components:"<<comp<<endl;
				}
				cout<<"total components:"<<comp<<endl;
			}

		};
		int main(){
		  //  ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		  //  cin>>test;
		    while(test--){
		    	graph g;
		    	int v,e;
		    	cin>>v>>e;
		    	REP(i,0,e)
		    	{
		    		int a,b;
		    		cin>>a>>b;
		    		g.addedge(a,b);
		    	}
		    	g.dfs();

		    }
	    }