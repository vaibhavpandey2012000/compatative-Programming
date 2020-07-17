#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<pair<int,int> > arr[maxN];
int parent[maxN],visit[maxN],weight[maxN];
int findminver(int v)
{
    int minver=-1;
    for(int i=1;i<=v;i++)
    {
        if(!visit[i] && (minver==-1 || weight[i]<weight[minver]))
        minver=i;
    }
    return minver;
}
int primes(int v)
{
    for(int i=0;i<=v;i++)
    weight[i]=INT_MAX;
    
    parent[1]=-1;
    weight[1]=0;
    for(int i=1;i<=v;i++)
    {
        int minver=findminver(v);
        visit[minver]=true;
        for(auto ch:arr[minver])
        {
            if(!visit[ch.first])
            {
                if(weight[ch.first]>ch.second)
                {
                    weight[ch.first]=ch.second;
                    parent[ch.first]=minver;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=v;i++)
    {
        ans+=weight[i];
    }
    return ans;
}
int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
    }
    int ans=primes(v);
    int tpp;
    cin>>tpp;
    cout<<ans<<endl;
}