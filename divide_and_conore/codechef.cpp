#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<ll,ll>
#define pl pair<ll,ll>
#define vi vector<ll> 
#define vvi vector< vi >
#define vl vector<ll>
#define vpi vector<pi> 
#define vpl vector<pl>
#define vvl vector<vl>
#define vvpl vector<vpl>
#define pb emplace_back
#define MP make_pair
#define sz(x) (ll)x.size()
#define ss second
#define ff first
#define inf 0x7fffffff
#define linf 2000000000000000007
#define endl "\n"
#define mod 1000000007
#define MAX 100010
#define fill(a,x) memset(x,a,sizeof x)
#define all(x) x.begin(),x.end()
#define rep(i,a,n) for(ll i=a;i<n;++i)
#define repr(i,n,b) for(ll i=n;i>=b;i--)
using namespace std;
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll test=1;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        vl a(n);
        rep(i,0,n){
            cin>>a[i];
            a[i]=abs(a[i]);
        }
        ll cnt=0, ind=-1;
        vl ans(n), odd(n);
        for(int i=n-1;i>=0;i--){
            if(a[i]%4==0){
                cnt+=n-i;
                a[i]=0;
            }
            else if(a[i]%4==2){
                a[i]=2;
            }
            else{
                a[i]=-1;
                odd[i]=1;
            }
        }
        bool ok=false;
        ll init=0, final=0, previnit=0;
        //cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]%4==2 and ok==false){
                ok=true;
                cnt+=final;
            }
            else if(a[i]%2==0 and ok){
                cnt+=n-i;
                if(a[i]==2){
                    final+=init;
                    init=0;
                    init+=previnit;
                    previnit=0;
                    ok=true;
                }
                else{
                    final+=(previnit+init);
                    previnit=0;
                    init=0;
                    ok=false;
                }
                cnt+=final;
            }
            else if(a[i]%2!=0){
                   if(!ok) init++;
                   else previnit++;
                cnt+=final;
            }
            else if(a[i]%4==0 and !ok){
                final+=init;
                init=0;
                cnt+=final;
            }
            else{
                cnt+=final;
            }
        }
        if(a[0]%2==0) ans[0]=0;
        else {
            //cnt++;
            ans[0]=1;
        }
        for(int i=1;i<n;i++){
            if(odd[i]==1){
                ans[i]=ans[i-1]+1;
                //cnt++;
            }
            else{
                cnt+=(ans[i-1]*(ans[i-1]+1))/2;
                ans[i]=0;
            }
        }
        if(odd[n-1]){
            cnt+=(ans[n-1]*(ans[n-1]+1))/2;
        }
        cout<<cnt<<endl;
    }
