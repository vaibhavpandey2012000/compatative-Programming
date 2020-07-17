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
		int lazy[1000]={0};
		void built(int *a,int s,int e,int* tree,int ind)
		{
			if(s==e){
				tree[ind]=a[s];
				return;
			}
			int m=(s+e)/2;
			built(a,s,m,tree,2*ind);
			built(a,m+1,e,tree,2*ind+1);
			tree[ind]=min(tree[2*ind],tree[2*ind+1]);
			return;
		}
		int query(int *tree,int ss,int se,int qs,int qe,int ind)
		{
			//complete overlap
			if(ss>=qs && se<=qe)
			{
				return tree[ind];
			}
			//no overlap
			if(se<qs || ss>qe)
			{
				return INT_MAX;
			}
			//partial overlap
			int m=(ss+se)/2;
			int left=query(tree,ss,m,qs,qe,2*ind);
			int right=query(tree,m+1,se,qs,qe,2*ind+1);
			return min(left,right);
		}
		void update(int *tree,int ss,int se,int ind,int inc,int index)
		{
			if(ss==se)
			{
				tree[index]+=inc;
				return;
			}
			if(ind<ss || ind>se)
			{
				return;
			}
			int mid=(ss+se)/2;
			update(tree,ss,mid,ind,inc,2*index);
			update(tree,mid+1,se,ind,inc,2*index+1);
			tree[index]=min(tree[2*index],tree[2*index+1]);
		}
		void rangeupdate(int *tree,int ss,int se,int s,int e,int inc,int ind)
		{
			if(e<ss || s>se)
			{
				return;
			}
			if(ss==se)
			{
				tree[ind]+=inc;
				return;
			}
			int mid=(ss+se)/2;
			rangeupdate(tree,ss,mid,s,e,inc,2*ind);
			rangeupdate(tree,mid+1,se,s,e,inc,2*ind+1);
			tree[ind]=min(tree[2*ind],tree[2*ind+1]);
			return;
		}
		void lazyupdate(int *tree,int ss,int se,int l,int r,int inc,int ind)
		{
			if(lazy[ind]!=0)
			{
				tree[ind]+=lazy[ind];
				if(ss!=se)
				{
					lazy[2*ind]+=lazy[ind];
					lazy[2*ind+1]+=lazy[ind];
				}
				lazy[ind]=0;
			}
			// no overlap
			if(r<ss || l>se)
			{
				return;
			}
			// complete overlap
			if(l<ss && r>se)
			{
				tree[ind]+=inc;
				if(ss!=se)
				{
					lazy[2*ind]+=inc;
					lazy[2*ind+1]+=inc;
				}
			}
			//partial overlap
			int mid=(ss+se)/2;
			lazyupdate(tree,ss,mid,l,r,inc,ind);
			lazyupdate(tree,mid+1,se,l,r,inc,ind);
			tree[ind]=min(tree[2*ind],tree[2*ind+1]);
			return;
		}
		// int lazyquary(int *tree,int ss,int se,int l,int r,int ind)
		// {
		// 	//lazy value update
		// 	if(lazy[ind]!=0)
		// 	{
		// 		tree[ind]+=lazy[ind];
		// 		if(ss!=se)
		// 		{
		// 			lazy[2*ind]+=lazy[ind];
		// 			lazy[2*ind+1]+=lazy[ind];
		// 		}
		// 		lazy[ind]=0;
		// 	}
		// 	//no overlap
		// 	if(r<ss || l>se)
		// 	{
		// 		return INT_MAX;
		// 	}
		// 	//complte overlap
		// 	if(ss>l && se<r)
		// 	{
		// 		return tree[ind];
		// 	}
		// 	//partial overlap
		// 	int mid=(ss+se)/2;
		// 	int laft=lazyquary(tree,ss,mid,l,r,2*ind);
		// 	int right=lazyquary(tree,mid+1,se,l,r,2*ind+1);
		// 	return min(left,right);
		// }
		int main(){
		  //  ios_base::sync_with_stdio(false); cin.tie(NULL);
			int n;
			cin>>n;
			int *a=new int[n];
			REP(i,0,n)
			cin>>a[i];
			int *tree=new int[4*n+1]{0};
			built(a,0,n-1,tree,1);
			REP(i,1,10)
			cout<<tree[i]<<" ";
			cout<<endl;
			update(tree,0,n-1,2,4,1);
			REP(i,1,10)
			cout<<tree[i]<<" ";
			cout<<endl;
			// //update(tree,0,n-1,3aa	a,15,1);
			// rangeupdate(tree,0,n-1,2,4,10,1);
			// // int l,r;
			// // cin>>l>>r;
			// // cout<<query(tree,0,n-1,l,r,1)<<endl;

			// // cin>>l>>r;
			// // cout<<query(tree,0,n-1,l,r,1)<<endl;
			
			// int aa=6;
			// while(aa--)
			// {
			// int l,r;
			// cin>>l>>r;
			// cout<<query(tree,0,n-1,l,r,1)<<endl;
			// }
			
		    
	    }