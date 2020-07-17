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
			list<int> *adj;
			public:
				graph(int v)
				{
					this->v=v;
					adj=new list<int>[v];
				}
				void addedge(int v,int u,bool bidir=true)
				{
					adj[v].PB(u);
					if(bidir)
					{
						adj[u].PB(v);
					}
				}
				void printedge()
				{
					REP(i,0,v)
					{
						cout<<i<<"-->";
						for( auto neg:adj[i])
						{
							cout<<neg<<",";
						}
						cout<<endl;
					}
				}
				void bfs(int src,int dest)
				{
					queue<int>q;
					bool *visit=new bool[v+1]{0};
					int *dist=new int[v+1]{0};
					int *parent=new int[v+1];
					memset(parent,-1,sizeof(parent));
					q.push(src);
					visit[src]=true;
					while(!q.empty())
					{
						int node=q.front();
						q.pop();
						cout<<node<<",";
						for(auto neg:adj[node])
						{
							if(!visit[neg]){
									q.push(neg);
									visit[neg]=true;
									dist[neg]=dist[node]+1;
									parent[neg]=node;
							}
							
						}
					}
					cout<<endl;
					for(int i=0;i<v;i++)
					{
						cout<<i<<" distance from src:"<<dist[i]<<endl;
					}
					int temp=dest;
					while(temp!=-1)
					{
						cout<<temp<<"<--";
						temp=parent[temp];
					}
				}
		};
		int main(){
		   // ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		  //  cin>>test;
		    while(test--){
		    	int v,e;
		    //	cin>>v>>e;
		    	graph g(36);
		    	int bord[50]={0};
		    	bord[2]=13;
		    	bord[95]=-14;
		    	bord[35]=17;
		    	bord[81]=-11;
		    	REP(u,0,36)
		    	{
		    		REP(dice,1,7)
		    		{
		    			int v=u+dice+bord[u+dice];
		    			g.addedge(u,v,false);
		    		}
		    	}
		    	g.bfs(0,35);
		    }
	    }