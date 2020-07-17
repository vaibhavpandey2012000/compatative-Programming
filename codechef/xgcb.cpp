#include<bits/stdc++.h>
#define         ll                 long long
#define         ld                 long double
#define         pi                 pair<int,int>
#define         pl                 pair<ll,ll>
#define         vi                 vector<int> 
#define         vvi             vector< vi >
#define         vl                 vector<ll>
#define         vpi             vector<pi> 
#define         vpl             vector<pl>
#define         vvl             vector<vl>
#define         vvpl             vector<vpl>
#define         pb                 emplace_back
#define         MP                 make_pair
#define         sz(x)             (ll)x.size()
#define         ss                 second
#define         ff                 first
#define         inf             0x7fffffff
#define         linf             2000000000000000007
#define         endl             "\n"
#define         mod             1000000007
#define         MAX             100010
#define         fill(a,x)         memset(x,a,sizeof x)
#define         all(x)             x.begin(),x.end()
#define         rep(i,a,n)         for(ll i=a;i<n;++i)
#define         repr(i,n,b)     for(ll i=n;i>=b;i--)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test=1;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        map<ll,ll> cnta, cntb, cntf;
        vl a(n), b(n);
        rep(i,0,n){
            cin>>a[i];
            cnta[a[i]]++;
            cntf[a[i]]++;
        }
        rep(i,0,n){
            cin>>b[i];
            cntb[b[i]]++;
            cntf[b[i]]++;
        }
        bool ok=true;
        for(auto x:cntf){
            if(x.ss&1){
                ok=false;
                break;
            }
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        sort(all(a));
        sort(all(b));
        vl ansa, ansb;
        for(auto x:cnta){
            if(cntb.find(x.ff)!=cntb.end()){
                if(cntb[x.ff]>=x.ss){
                    cntb[x.ff]-=x.ss;
                    cntb[x.ff]/=2;
                    while(cntb[x.ff]--){
                        ansb.pb(x.ff);
                    }
                }
                else{
                    x.ss-=cntb[x.ff];
                    x.ss/=2;
                    while(x.ss--){
                        ansa.pb(x.ff);
                    }
                }
            }
            else{
                x.ss/=2;
                while(x.ss--)
                    ansa.pb(x.ff);
            }
        }
        for(auto x:cntb){
            if(x.ss!=0){
                x.ss/=2;
                while(x.ss--){
                    ansb.pb(x.ff);
                }
            }
        }
        if(ansa.size()==0 || ansb.size()==0){
            cout<<0<<endl;
            continue;
        }
        sort(all(ansb));
        sort(all(ansa));
        ll ele=min(a[0], b[0]);
        reverse(all(ansa));
        n=ansa.size();
        ll ans=0;
        rep(i,0,n){
            if(min(ansa[i], ansb[i])>2*ele){
                ans+=2*ele;
            }
            else{
                ans+=min(ansa[i], ansb[i]);
            }
        }
        cout<<ans<<endl;
    }
}
