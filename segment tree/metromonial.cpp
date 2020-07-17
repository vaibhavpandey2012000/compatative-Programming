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
		class person{
		public:
			string name,age,color,married,city,education,caste,sallery;

		};
		int main(){
		   // ios_base::sync_with_stdio(false); cin.tie(NULL);
		    int test=1;
		  //  cin>>test;
		    while(test--){
		    	vector<person>male;
		    	vector<person>female;
		    	while(1){
		    	string gen;
		    	cout<<"Enter the gender :";
		    	cin>>gen;
		    	if(gen=="male" or gen=="Male" or gen=="MALE")
		    	{
		    		string ss;
		    		cout<<"you are register before or not :";
		    		cin>>ss;
		    		if(ss=="yes" or ss=="YES" or ss=="y" or ss=="Y")
		    		{
		    			string ans;
		    			cout<<"you want to see your solemate ?\n";
		    			cin>>ans;
		    			if(ans=="yes" or ans=="YES" or ans=="y" or ans=="Y")
		    			{
		    				person girl;
		    				cout<<"girl name :";
		    				cin>>girl.name;
		    				cout<<endl;

		    				cout<<"girl age:";
		    				cin>>girl.age;
		    				cout<<endl;

		    				cout<<"girl color:";
		    				cin>>girl.color;
		    				cout<<endl;

		    				cout<<"girl married:";
		    				cin>>girl.married;
		    				cout<<endl;

		    				cout<<"girl city :";
		    				cin>>girl.city;
		    				cout<<endl;

		    				cout<<"girl education :";
		    				cin>>girl.education;
		    				cout<<endl;

		    				cout<<"girl caste :";
		    				cin>>girl.caste;
		    				cout<<endl;

		    				cout<<"girl sallery :";
		    				cin>>girl.sallery;
		    				cout<<endl;
		    				int flag=0;

		    				REP(i,0,male.size())
		    				{
		    					if(girl.name==male[i].name or girl.age==male[i].age or girl.color==male[i].color or
		    						girl.married==male[i].married or girl.city==male[i].city or girl.caste==male[i].caste or
		    						girl.sallery<male[i].name )
		    					{
		    						cout<<endl;
		    						cout<<"name: "<<male[i].name<<endl;
		    						cout<<"age: "<<male[i].age<<endl;
		    						cout<<"color: "<<male[i].color<<endl;
		    						cout<<"married: "<<male[i].married<<endl;
		    						cout<<"city: "<<male[i].city<<endl;
		    						cout<<"caste: "<<male[i].caste<<endl;
		    						cout<<"sallery: "<<male[i].sallery<<endl;
		    						cout<<endl;
		    						flag=1;
		    					}
		    				}
		    				if(flag==0)
		    				{
		    					cout<<"NO RESULT FOUND"<<endl;
		    				}

		    			}
		    		}
		    		else{
		    			person temp;
		    			cout<<"REGISTER YOURSELF"<<endl;
		    			cout<<"Enter your name:";
		    			cin>>temp.name;
		    			cout<<endl;
		    			cout<<"Enter your age:";
		    			cin>>temp.age;
		    			cout<<endl;
		    			cout<<"Enter your color:";
		    			cin>>temp.color;
		    			cout<<endl;
		    			cout<<"Enter your married detail:";
		    			cin>>temp.married;
		    			cout<<endl;
		    			cout<<"Enter your city:";
		    			cin>>temp.city;
		    			cout<<endl;
		    			cout<<"Enter your education:";
		    			cin>>temp.education;
		    			cout<<endl;
		    			cout<<"Enter your caste:";
		    			cin>>temp.caste;
		    			cout<<endl;
		    			cout<<"Enter your sallery:";
		    			cin>>temp.sallery;
		    			cout<<endl;
		    			cout<<"Thankyou.."<<endl;
		    			male.PB(temp);
		    		}

		    	}
		    	else
		    	{
		    		string ss;
		    		cout<<"you are register before or not :";
		    		cin>>ss;
		    		if(ss=="yes" or ss=="YES" or ss=="y" or ss=="Y")
		    		{
		    			string ans;
		    			cout<<"you want to see your solemate ?\n";
		    			cin>>ans;
		    			if(ans=="yes" or ans=="YES" or ans=="y" or ans=="Y")
		    			{
		    				person boy;
		    				cout<<"boy name :";
		    				cin>>boy.name;
		    				cout<<endl;

		    				cout<<"boy age:";
		    				cin>>boy.age;
		    				cout<<endl;

		    				cout<<"boy color:";
		    				cin>>boy.color;
		    				cout<<endl;

		    				cout<<"boy married:";
		    				cin>>boy.married;
		    				cout<<endl;

		    				cout<<"boy city :";
		    				cin>>boy.city;
		    				cout<<endl;

		    				cout<<"boy education :";
		    				cin>>boy.education;
		    				cout<<endl;

		    				cout<<"boy caste :";
		    				cin>>boy.caste;
		    				cout<<endl;

		    				cout<<"boy sallery :";
		    				cin>>boy.sallery;
		    				cout<<endl;
		    				int flag=0;

		    				REP(i,0,female.size())
		    				{
		    					if(boy.name==female[i].name or boy.age==female[i].age or boy.color==female[i].color or
		    						boy.married==female[i].married or boy.city==female[i].city or boy.caste==female[i].caste or
		    						boy.sallery<female[i].name )
		    					{
		    						cout<<endl;
		    						cout<<"name: "<<female[i].name<<endl;
		    						cout<<"age: "<<female[i].age<<endl;
		    						cout<<"color: "<<female[i].color<<endl;
		    						cout<<"married: "<<female[i].married<<endl;
		    						cout<<"city: "<<female[i].city<<endl;
		    						cout<<"caste: "<<female[i].caste<<endl;
		    						cout<<"sallery: "<<female[i].sallery<<endl;
		    						cout<<endl;
		    						flag=1;
		    					}
		    				}
		    				if(flag==0)
		    				{
		    					cout<<"NO RESULT FOUND"<<endl;
		    				}
		    			}
		    		}
		    		else{
		    			person temp;
		    			cout<<"REGISTER YOURSELF"<<endl;
		    			cout<<"Enter your name:";
		    			cin>>temp.name;
		    			cout<<endl;
		    			cout<<"Enter your age:";
		    			cin>>temp.age;
		    			cout<<endl;
		    			cout<<"Enter your color:";
		    			cin>>temp.color;
		    			cout<<endl;
		    			cout<<"Enter your married detail:";
		    			cin>>temp.married;
		    			cout<<endl;
		    			cout<<"Enter your city:";
		    			cin>>temp.city;
		    			cout<<endl;
		    			cout<<"Enter your education:";
		    			cin>>temp.education;
		    			cout<<endl;
		    			cout<<"Enter your caste:";
		    			cin>>temp.caste;
		    			cout<<endl;
		    			cout<<"Enter your sallery:";
		    			cin>>temp.sallery;
		    			cout<<endl;
		    			cout<<"Thankyou.."<<endl;
		    			female.PB(temp);
		    		}
		    	}
		    }
		    
		    }
	    }