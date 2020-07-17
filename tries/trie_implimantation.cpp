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
		class Node{
			public:
				int data;
				bool isterminal;
				unordered_map<char,Node*>child;
				Node(char data)
				{
					this->data=data;
					this->isterminal=false;
				}
		};
		class tries{
			public:
			Node *root;
			int count;
				tries(){
					this->root=new Node('\0');
					this->count=0;
				}
				void addword(string str)
				{
					Node *temp=root;
					REP(i,0,str.size())
					{
						char ch=str[i];
						if(temp->child.count(ch))
						{
							temp=temp->child[ch];
						}
						else
						{
							Node *n=new Node(ch);
							temp->child[ch]=n;
							temp=n;
						}
					}
					temp->isterminal=true;
				}
				bool search(string str)
				{
					Node *temp=root;
					REP(i,0,str.size())
					{
						char ch=str[i];
						if(temp->child.count(ch))
						{
							temp=temp->child[ch];
						}
						else
						{
							return false;
						}
					}
					return temp->isterminal;
				}
		};
		int main(){
		  //  ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		   // cin>>test;
		    while(test--){
		    	tries t;
		    	int n;
		    	cin>>n;
		    	REP(i,0,n)
		    	{
		    		string s;
		    		cin>>s;
		    		t.addword(s);
		    	}
		    	int q;
		    	cin>>q;
		    	REP(i,0,q)
		    	{
		    		string s;
		    		cin>>s;
		    		bool ser=t.search(s);
		    		if(ser)
		    		{
		    			cout<<"found."<<endl;
		    		}
		    		else
		    		{
		    			cout<<"Not found."<<endl;
		    		}
		    	}
		    }
		    return 0;
	    }