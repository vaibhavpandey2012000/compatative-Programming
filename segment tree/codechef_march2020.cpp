/*
Chef's fans want to celebrate the special occasion of his birthday, so they are writing letters to him.
 Chef has received N such letters from N fans (numbered 1 through N). Initially,
  for each valid i, he assigned a beauty Bi to the letter from the i-th fan (these values may even be negative, 
  for letters that are not written well).

Now, Chef wants you to process Q queries on these letters. There are two types of queries:

Q x y: Chef wants to choose integers l and r such that 1≤l≤x≤y≤r≤N and read all the letters from fans l,l+1,…,r.
 Find the maximum possible value of the sum of beauties of the letters he reads.
U x v: Chef reevaluates the beauty of the letter from the x-th fan. The new value of Bx becomes v.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and Q.
The second line contains N space-separated integers B1,B2,…,BN.
Each of the next Q lines describes a query in the format described above.

*/
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
		struct node{
			ll sum;
			ll pre;
			ll suff;
		};
		ll arr[100000];
		node stree[400005];
		void build(int ind,int beg,int end)
		{
			if(beg==end)
			{
				stree[ind].sum=arr[beg];
				stree[ind].pre=arr[beg];
				stree[ind].suff=arr[beg];
				return;
			}
			int mid=(beg+end)/2;
			build(2*ind+1,beg,mid);
			build(2*ind+2,mid+1,end);
			stree[ind].sum=(stree[2*ind+1].sum+stree[2*ind+2].sum);
			stree[ind].pre=max(stree[2*ind+1].pre,stree[2*ind+1].sum+stree[2*ind+2].pre);
			stree[ind].suff=max(stree[2*ind+2].suff,stree[2*ind+2].sum+stree[2*ind+1].suff);
		}
		void update(int index,int bg,int ed,int ind)
		{
			if(ed<ind || ind<bg)
			return;
			if(bg==ed)
			{
				stree[ind].sum=arr[ind];
				stree[ind].pre=arr[ind];
				stree[ind].suff=arr[ind];
				return;
			}
			int mid=(bg+ed)/2;
			update(2*index+1,bg,mid,ind);
			update(2*index+2,mid+1,ed,ind);
			stree[ind].sum=(stree[2*ind+1].sum+stree[2*ind+2].sum);
			stree[ind].pre=max(stree[2*ind+1].pre,stree[2*ind+1].sum+stree[2*ind+2].pre);
			stree[ind].suff=max(stree[2*ind+2].suff,stree[2*ind+2].sum+stree[2*ind+1].suff);
		}
		node query(int index, int beg, int end, int l, int r) 
		{ 
   			 node result; 
    		result.sum = result.pre = -1; 
  			if (beg > r || end < l)
  				return result; 
    		if (beg >= l && end <= r) 
    			return stree[index]; 
		    int mid = (beg + end) / 2; 
		    if (l > mid)
		    	return query(2*index+2,mid+1,end,l,r); 
		    if (r <= mid)  
		    	return query(2*index+1, beg, mid,l,r); 
		    node left = query(2*index+1,beg,mid,l,r); 
   		 	node right = query(2*index+2, mid+1,end,l,r); 
		    result.sum = left.sum+right.sum; 
    		result.pre = max(left.pre,left.sum+right.pre); 
   
    		return result; 
		} 
		node query2(int index, int beg, int end, int l, int r) 
		{ 
    		node result; 
    		result.sum = result.suff = -1; 
		    if (beg > r || end < l) 
		    	return result; 
		    if (beg >= l && end <= r)
		    	return stree[index]; 
		    int mid = (beg + end) / 2; 
		    if (l > mid) 
		    	return query2(2*index+2, mid+1,end,l,r); 
		    if (r <= mid)  
		    	return query2(2*index+1,beg,mid,l,r); 
		    node left = query2(2*index+1,beg,mid,l,r); 
    		node right = query2(2*index+2,mid+1,end,l,r); 
		    result.sum = left.sum + right.sum; 
    		result.suff = max(right.suff, left.suff + right.sum); 
   
    		return result; 
		}
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		    cin>>test;
		    while(test--){
		    	int n,q;
		    	cin>>n>>q;
		    	for(int i=0;i<n;i++)
		    	{
		    		cin>>arr[i];
		    	}
		    	build(0,0,n-1);
		    	while(q--)
		    	{
		    		char ch;
		    		cin>>ch;
		    		if(ch=='Q')
		    		{
		    			ll l,r;
		    			cin>>l>>r;
		    			l--,r--;
		    			ll a=0,b=0;
		    			if(r==(n-1))
		    			{
		    				b=0;
		    			}
		    			else
		    			{
		    				b=max(0ll,query(0,0,n-1,r+1,n-1).pre);
		    			}
		    			if(l==0)
		    			{
		    				a=0;
		    			}
		    			else
		    			{
		    				a=max(0ll,query2(0,0,n-1,0,l-1).suff);
		    			}
		    			//cout<<a<<" "<<b<<endl;
		    			ll c=query(0,0,n-1,l,r).sum;
		    			cout<<a+b+c<<endl;
		    		}
		    		else
		    		{
		    			int l,r;
		    			cin>>l>>r;
		    			arr[l-1]=r;
		    			update(0,0,n-1,l-1);
		    		}
		    	}
		    }
	    }