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
		struct point
		{
			int x,y;
		};
		int orientation(point p,point q,point r)
		{
			int val=(q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);
			if(val==0) return 0;
			return (val>0)?1:2;
		}
		void convexhull(point points[],int n)
		{
			if(n<3) return;
			vector<point>hull;
			int l=0;
			for(int i=0;i<n;i++)
			{
				if(points[i].x<points[l].x)
					l=i;
			}
			int p=l,q;
			do{
				hull.PB(points[p]);
				q=(p+1)%n;
				for(int i=0;i<n;i++)
				{
					if(orientation(points[p],points[i],points[q])==2)
					{
						q=i;
					}
				}
				p=q;
			}
			while(p!=l);
			for(int i=0;i<hull.size();i++)
			{
				cout<<"("<<hull[i].x<<","<<hull[i].y<<")"<<endl;
			}
		}
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		   // cin>>test;
		    while(test--){

		    	// point points[]={{0,0},{0,3},{1,1},{2,2},{3,3},{3,0}};
		    	// int n=sizeof(points)/sizeof(points[0]);
		    	int n;
		    	cin>>n;
		    	point *points=new point[n];
		    	for(int i=0;i<n;i++)
		    	{
		    		int a,b;
		    		cin>>points[i].x>>points[i].y;

		    	}
		    	convexhull(points,n);

		    }
	    }