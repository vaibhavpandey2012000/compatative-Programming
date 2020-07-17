#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int tc=1;
    cin>>tc;
    while(tc--){
        ll n;
        cin>>n;
        map<ll,ll> mpa, mpb;
        ll nm=0;
        vector<long> v1(n), v2(n);
        for(int i=0;i<n;i++){
            cin>>v1[i];
            mpa[v1[i]]++;
            nm^=v1[i];
        }
        for(int i=0;i<n;i++){
            cin>>v2[i];
            mpb[v2[i]]++;
            nm^=v2[i];
        }
       	if(nm!=0)
       	{
       		cout<<"-1"<<endl;
			continue;	
		}
        sort(v1.begin(),v1.end()); 
       	sort(v2.begin(),v2.end());
        vector<long> sol, solb;
        for(auto x:mpa){
            if(mpb.find(x.first)!=mpb.end()){
                if(mpb[x.first]>=x.second){
                    mpb[x.first]-=x.second;
                    mpb[x.first]/=2;
                    while(mpb[x.first]--){
                        solb.push_back(x.first);
                    }
                }
                else{
                	
                    x.second-=mpb[x.first];
                    mpb[x.first]=0;
                    x.second/=2;
                    while(x.second--){
                        sol.push_back(x.first);
                    }
                }
            }
            else{
                x.second/=2;
                while(x.second--)
                    sol.push_back(x.first);
            }
        }
        for(auto x:mpb){
            if(x.second!=0){
                x.second/=2;
                while(x.second--){
                    solb.push_back(x.first);
                }
            }
        }
        if(sol.size()==0 || solb.size()==0){
            cout<<0<<endl;
            continue;
        }
        sort(solb.begin(),solb.end());
        sort(sol.begin(),sol.end());
        ll ele=min(v1[0], v2[0]);
        reverse(sol.begin(),sol.end());
        ll ss=0;
        for(int i=0;i<sol.size();i++){
            if(min(sol[i], solb[i])>2*ele){
                ss+=2*ele;
            }
            else{
                ss+=min(sol[i], solb[i]);
            }
        }
        cout<<ss<<endl;
    }
}
