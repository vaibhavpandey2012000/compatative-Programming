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
			map<int,list<int> >adj1,adj2;
		public:
			graph(int v)
			{
				this->v=v;
			}
			
			void addedge(int a,int b)
			{
				adj1[a].PB(b);
				adj2[b].PB(a);
			}
			void dfshelper1(int node,map<int,bool>&visited,int &v)
			{
				visited[node]=true;
				v++;
				for(auto neg:adj1)
				{
					int node=neg.FF;
					if(!visited[node])
					{
						dfshelper1(node,visited,v);
					}
				}
			}
			void dfshelper(int node,map<int,bool>&visited,int &v1)
			{
				visited[node]=true;
				v1++;
				for(auto neg:adj2)
				{
					int node=neg.FF;
					if(!visited[node])
					{
						dfshelper(node,visited,v1);
					}
				}
			}
			bool dfs(int src)
			{

				map<int,bool>visited;
				map<int,bool>visited1;
				//vector<int>v1,v2;
				int v1=0,v2=0;
				dfshelper1(src,visited1,v1);
				dfshelper(src,visited,v2);
				cout<<v1<<"  "<<v2<<endl;
				if(v1==v && v2==v)
				{
					return true;
				}
				else
				{
					return false;
				}
				
			}


		};
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		    //cin>>test;
		    while(test--){
		    	int v,e;
		    	cin>>v>>e;
		    	graph g(v);
		    	REP(i,0,e)
		    	{
		    		int a,b;
		    		cin>>a>>b;
		    		g.addedge(a,b);
		    	}
		    	bool k=g.dfs(0);
		    	if(k==true)
		    	{
		    		cout<<"Strongly conected"<<endl;
		    	}
		    	else
		    	{
		    		cout<<"not Strongly connected"<<endl;
		    	}

		    }
	    }