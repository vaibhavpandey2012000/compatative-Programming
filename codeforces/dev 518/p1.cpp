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
		int main(){
		    ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		    int arr[10]={0};
		  //  cin>>test;
		    while(test--){
		    	int n;
		    	cin>>n;
		    	string s;
		    	cin>>s;
		    	int lll=0,rrr=9;
		    	for(int i=0;i<s.length();i++)
		    	{
		    		if(s[i]=='L')
		    		{
		    			for(int j=0;j<10;j++)
		    			{
		    				if(arr[j]==0)
		    				{
		    					arr[j]=1;
		    					break;
		    				}
		    			}
		    		}
		    		if(s[i]=='R')
		    		{
		    			for(int j=9;j>=0;j--)
		    			{
		    				if(arr[j]==0)
		    				{
		    					arr[j]=1;
		    					break;
		    				}
		    			}
		    		}
		    		if(s[i]=='1')
		    		{
		    			arr[1]=0;
		    		}
		    		if(s[i]=='2')
		    		{
		    			arr[2]=0;
		    		}
		    		if(s[i]=='3')
		    		{
		    			arr[3]=0;
		    		}
		    		if(s[i]=='4')
		    		{
		    			arr[4]=0;
		    		}
		    		if(s[i]=='5')
		    		{
		    			arr[5]=0;
		    		}
		    		if(s[i]=='6')
		    		{
		    			arr[6]=0;
		    		}
		    		if(s[i]=='7')
		    		{
		    			arr[7]=0;
		    		}
		    		if(s[i]=='8')
		    		{
		    			arr[8]=0;
		    		}
		    		if(s[i]=='9')
		    		{
		    			arr[9]=0;
		    		}
		    		if(s[i]=='0')
		    		{
		    			arr[0]=0;
		    		}
		    	}
		    	for(int i=0;i<10;i++)
		    	{
		    		cout<<arr[i];
		    	}
		    	cout<<endl;

		    }
	    }