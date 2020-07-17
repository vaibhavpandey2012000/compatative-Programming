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
		point p0;
		point next_to_top(stack<point>&s)
		{
			point p=s.top();
			s.pop();
			point res=s.top();
			s.push(p);
			return res;
		}
		void swap(point &p1,point &p2)
		{
			point temp=p1;
			p1=p2;
			p2=temp;
		}
		int distsq(point p1,point p2)
		{
			return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
		}
		int orientation(point p,point q,point r)
		{
			int val=(q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);
			if(val==0)return 0;
			return (val>0)?1:2;
		}
		int compare(const void *vp1,const void *vp2)
		{
			point *p1=(point*)vp1;
			point *p2=(point*)vp2;
			int o=orientation(p0,*p1,*p2);
			if(o==0)
			{
				return distsq(p0,*p2)>=distsq(p0,*p1)?-1:1;
			}
			return (o==2)?-1:1;
		}


		void convexHull(point points[],int n)
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
			qsort(&points[1],n-1,sizeof(point),compare);
			REP(i,1,n)
			{
				while(i<(n-1) && orientation(p0,points[i],points[i+1])==0)
				i++;
				points[m]=points[i];
				m++;
			}
			if(m<3)return;
			stack<point>s;
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
				point p=s.top();
				cout<<"("<<p.x<<","<<p.y<<")"<<endl;
				s.pop();
			}

		}
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		   // cin>>test;
		    while(test--){

		    	 point points[]={{0,0},{0,3},{1,1},{2,2},{3,3},{3,0}};
		    	 int n=sizeof(points)/sizeof(points[0]);
		    	 convexHull(points, n);


		    }
	    }