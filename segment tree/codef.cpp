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
		struct nodetree
		{
			ll prefix;
			ll suffix;
			ll sum;
			ll maxsum;
		};
		void buildtree(ll *a,nodetree *tree,ll ss,ll se,ll idx)
		{
			if(ss==se)
			{
				tree[idx]=((nodetree){a[ss],a[ss],a[ss],a[ss]});
			}
			else
			{
				ll mid=(ss+se)/2;
				buildtree(a,tree,ss,mid,idx*2+1);
				buildtree(a,tree,ss,mid,idx*2+2);

				nodetree left=tree[idx*2+1];
				nodetree right=tree[idx*2+2];

				tree[idx].prefix=max(left.prefix,left.sum+right.prefix);
				tree[idx].suffix=max(right.suffix,right.sum+left.suffix);
				tree[idx].sum=left.sum+right.sum;
				int pp=max(left.suffix,right.suffix);
				int kk=max(left.maxsum,right.maxsum);
				tree[idx].maxsum=max(kk,pp);

			}
		}
		nodetree query(nodetree *tree,ll qs,ll qe,ll ss,ll se,ll idx)
		{
			if(qs>se || qe<ss)
			{
				return ((nodetree){INT_MIN,INT_MIN,INT_MIN,INT_MIN});
			}
			if(ss>=qs && se<=qe)
			{
				return tree[idx];
			}
			nodetree temp;
			ll mid=(ss+se)/2;
			nodetree left=query(tree,qs,qe,ss,mid,2*idx+1);
			nodetree right=query(tree,qs,qe,mid+1,se,2*idx+2);

			temp.prefix=max(left.prefix,left.sum+right.prefix);
			temp.suffix=max(right.suffix,right.sum+left.suffix);
			temp.sum=left.sum+right.sum;
			int pp=max(left.suffix,right.suffix);
			int kk=max(left.maxsum,right.maxsum);
			temp.maxsum=max(kk,pp);

			return temp;

		}

		int main(){
		 //   ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		   // cin>>test;
		    while(test--){
		    	ll n;
		    	cin>>n;
		    	ll *a=new ll[n];
		    	REP(i,0,n)
		    	{
		    		cin>>a[i];
		    	}
		    	nodetree *tree=new nodetree[4*(n)+1];
		    	buildtree(a,tree,0,n-1,0);
		    	int q;
		    	cin>>q;
		    	while(q--)
		    	{
		    		int l,r;
		    		cin>>l>>r;
		    		cout<<query(tree,l-1,r-1,0,n-1,0).maxsum<<endl;
		    	}

		    }
	    }