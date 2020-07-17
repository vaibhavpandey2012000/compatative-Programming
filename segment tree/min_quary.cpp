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
		void build(int *arr,int *tree,int s,int e,int id)
		{
			if(s==e)
			{
				tree[id]=arr[s];
				return;
			}
			int m=(s+e)/2;
			build(arr,tree,s,m,2*id);
			build(arr,tree,m+1,e,2*id+1);
			tree[id]=min(tree[2*id],tree[2*id+1]);
		}
		int quary(int *tree,int ss,int se,int qs,int qe,int ind)
		{
			if(se<qs || ss>qe)
				return INT_MAX;
			if(ss>=qs && se<=qe)
				return tree[ind];
			int mid=(ss+se)/2;
			int lf=quary(tree,ss,mid,qs,qe,2*ind);
			int rt=quary(tree,mid+1,se,qs,qe,2*ind+1);
			return min(lf,rt);
		}
		void update(int *tree,int ss,int se,int i,int inc,int ind)
		{
			if(ss==se)
			{
				tree[ind]+=inc;
				return;
			}
			else if(i<ss || i>se)
			{
				return;
			}
			int m=(ss+se)/2;
			update(tree,ss,m,i,inc,2*ind);
			update(tree,m+1,se,i,inc,2*ind+1);
			tree[ind]=min(tree[2*ind],tree[2*ind+1]);
			return;

		}
		int main(){
		   // ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		   // cin>>test;
		    while(test--){
		    	int n,q;
		    	cin>>n>>q;
		    	int *arr=new int[n];
		    	int *tree=new int[4*n+1];
		    	memset(tree,INT_MIN,sizeof(tree));
		    	REP(i,0,n)
		    	{
		    		cin>>arr[i];
		    	}
		    	build(arr,tree,0,n-1,1);
		    	REP(i,1,14)
		    	cout<<tree[i]<<" ";
		    	while(q--)
		    	{
		    		//cout<<"pp"<<endl;
		    		int a,b,c;
		    		cin>>a>>b>>c;
		    		if(a==1)
		    		{
		    			cout<<quary(tree,0,n-1,b-1,c-1,1)<<endl;
		    			continue;
		    		}
		    		if(a==2)
		    		{
		    			update(tree,0,n-1,b-1,c,1);
		    			REP(i,1,14)
		    			cout<<tree[i]<<" ";
		    		}
		    	}

		    }
	    }