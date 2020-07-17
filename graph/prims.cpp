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
			int v;
			list<pair<int,int> >*adj;
		public:
			graph(int v)
			{
				this->v=v;
				adj=new list<pair<int,int> >[v];
			}
			void addedge(int q,int s,int w)
			{
				adj[q].PB(MP(s,w));
				adj[s].PB(MP(q,w));
			}
			int findminver(int *weight,bool *visited,int v)
			{
				int minver=-1;
				REP(i,0,v)
				{
					if(!visited[i] && (minver== -1 || weight[i]<weight[minver]))
					{
						minver=i;
					}
				}
				return minver;
			}
			void prims()
			{
				bool *visited=new bool[v];
				int *parent=new int[v];
				int *weight=new int[v];
				REP(i,0,v)
				{
					visited[i]=false;
					weight[i]=1e9;
				}
				parent[0]=-1;
				weight[0]=0;
				for(int i=0;i<v;i++)
				{
					int minvertex=findminver(weight,visited,v);
					visited[minvertex]=true;
					for(auto neg:adj[minvertex])
					{
						if(!visited[neg.FF])
						{
							if(weight[neg.FF]>neg.SS)
							{
								parent[neg.FF]=minvertex;
								weight[neg.FF]=neg.SS;
							}
						}
					}
				}
				for(int i=1;i<v;i++)
				{
					cout<<i<<"--"<<parent[i]<<" with weight:"<<weight[i]<<endl;
				}
			}
		};
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		   // cin>>test;
		    while(test--){
		    	int v,e;
		    	cin>>v>>e;
		    	graph g(v);
		    	REP(i,0,e)
		    	{
		    		int a,b,w;
		    		cin>>a>>b>>w;
		    		g.addedge(a,b,w);
		    	}
		    	g.prims();

		    }
	    }