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
		struct Point
		{
			int x,y;
		};
		Point p0;
		Point next_to_top(stack<Point>&s)
		{
			Point p=s.top();
			s.pop();
			Point res=s.top();
			s.push(p);
			return res;
		}
		void swap(Point &p1,Point &p2)
		{
			Point temp=p1;
			p1=p2;
			p2=temp;
		}
		int distsq(Point p1,Point p2)
		{
			return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
		}
		int orientation(Point p,Point q,Point r)
		{
			int val=(q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);
			if(val==0)return 0;
			return (val>0)?1:2;
		}
		int compare(const void *vp1,const void *vp2)
		{
			Point *p1=(Point*)vp1;
			Point *p2=(Point*)vp2;
			int o=orientation(p0,*p1,*p2);
			if(o==0)
			{
				return distsq(p0,*p2)>=distsq(p0,*p1)?-1:1;
			}
			return (o==2)?-1:1;
		}


		void convexHull(vector<Point> points,int n)
		{
			int ymin=points[0].y,min=0,m=1;
			REP(i,1,n)
			{
				int y=points[i].y;
				if((y<ymin)||((ymin==y)&&(points[i].x<points[min].x)))
				{
					ymin=points[i].y;
					min=i;
				}
			}
			swap(points[0],points[min]);
			p0=points[0];
			qsort(&points[1],n-1,sizeof(Point),compare);
			REP(i,1,n)
			{
				while(i<(n-1) && orientation(p0,points[i],points[i+1])==0)
				i++;
				points[m]=points[i];
				m++;
			}
			if(m<3)return;
			stack<Point>s;
			s.push(points[0]);
			s.push(points[1]);
			s.push(points[2]);
			REP(i,3,m)
			{
				while(orientation(next_to_top(s),s.top(),points[i])!=2)
					s.pop();
				s.push(points[i]);
			}
			while(!s.empty())
			{
				Point p=s.top();
				cout<<"("<<p.x<<","<<p.y<<")"<<endl;
				s.pop();
			}

		}
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		   // cin>>test;
		    while(test--){
				int n;
				cin>>n;
		    	// Point points[]={{0,0},{6,0},{2,1},{4,1},{3,3},{3,4}};
		    	vector<Point>points(n);
		    	for(int i=0;i<n;i++)
		    	{
		    		int a,b;
		    		cin>>a>>b;
		    		points[i].x=a;
		    		points[i].y=b;
				}
		    	convexHull(points, n);


		    }
	    }
