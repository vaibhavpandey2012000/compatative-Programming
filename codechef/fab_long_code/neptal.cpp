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
		  //  cin>>test;
		    while(test--){
		    	ll C,N,K,i,ind1,ind2,flag=0;
				cin>>C>>N>>K;
				vector<pair<ll,ll> >vect;
				REP(i,0,N)
				{
					cin>>ind1>>ind2;
					vect.push_back(make_pair(ind1,ind2));
				}
				sort(vect.begin(),vect.end());
				if(K==0)
				{
					REP(i,0,N-1)
					{
						if(max(vect[i].FF,vect[i+1].FF)<=min(vect[i].SS,vect[i+1].SS))
					{
						flag=1;
						break;
				}
			}
				if(flag==1)
				cout<<"Bad\n";
				else 
				cout<<"Good\n";
				}
				else
				{
					ll cnt=0,len1,len2,len,check=0,con=0,val1,val2;
					REP(i,0,N-1)
					{
						ind1=vect[i].FF;
						ind2=vect[i].SS;
						if(max(vect[i].FF,vect[i+1].FF)<=min(vect[i].SS,vect[i+1].SS))
						{
							check++;
							len1=(vect[i].SS-vect[i].FF+1);
							len2=(vect[i+1].SS-vect[i+1].FF+1);
							if(len1<len2)
							{
								con=i;
								len=len1;
							}
							else
							con=i+1,len=len2;
						}
					if(check>1)
					{
						flag=1;
						break;
					}
	    		 }
	  			  // cout<<"check "<<check<<endl;
	    		 if(check==1)
	    		 {
	     			flag=1;
	     			REP(i,0,N-1)
	     			{
	     				len1=(vect[i+1].FF-vect[i].SS+1);
	     				if(len<len1)
					{
						flag=0;
	     	    		 break;
					}
				}
				if(len<vect[0].FF)
	     		flag=0;
	     		if(con==N-1&&(len<=abs(C-vect[N-1].FF)))
	     		flag=0;
				if(len<abs(C-vect[N-1].SS))
	     		flag=0;
			}
			if(flag==1)
			cout<<"Bad\n";
			else 
			cout<<"Good\n";
		}
	}
}