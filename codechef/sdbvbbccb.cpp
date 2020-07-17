#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct Points {
    ll x, y;
    inline bool operator ==(Points a){
        return (a.x==x&&a.y==y);
    }
};
ll fun(ll a,ll b)
{
	return a+b;
}
vector<vector<Points>> ans;

ll orientation(Points p, Points q, Points r) 
{ 
    ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0; 
    return (val > 0)? 1: 2; 
}

bool count_indx(Points a, Points b, Points c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
  
bool count_index(Points a, Points b, Points c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool cmp(Points a, Points b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
void convex_hull(vector<Points>& v) {
    if (v.size() == 1)
        return;

    sort(v.begin(), v.end(), &cmp);
    Points p1 = v[0], p2 = v.back();
    vector<Points> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (ll i = 1; i < (ll)v.size(); i++) {
        if (i == v.size() - 1 || count_index(p1, v[i], p2)) {
            while (up.size() >= 2 && !count_index(up[up.size()-2], up[up.size()-1], v[i]))
                up.pop_back();
            up.push_back(v[i]);
        }
        if (i == v.size() - 1 || count_indx(p1, v[i], p2)) {
            while(down.size() >= 2 && !count_indx(down[down.size()-2], down[down.size()-1], v[i]))
                down.pop_back();
            down.push_back(v[i]);
        }
    }

    vector<Points> tpts;
    for (ll i = 0; i < (ll)up.size(); i++){
        tpts.push_back(up[i]);
        v.erase(remove(v.begin(),v.end(),up[i]),v.end());
        }
    for (ll i = down.size() - 2; i > 0; i--){
        tpts.push_back(down[i]);
        v.erase(remove(v.begin(),v.end(),down[i]),v.end());
        }
    vector<Points> temp = v;
    for(auto itr:temp){
        for(ll i=0;i<tpts.size();++i){
        ll x=orientation(tpts[i],tpts[(i+1)%tpts.size()],itr);
        if(!x) v.erase(remove(v.begin(),v.end(),itr),v.end());
        }
    }
    ans.push_back(tpts);
}

void solve(){
	ll n,q;cin>>n>>q;
    vector<Points> points(n);
    for(ll i=0;i<n;++i){
        ll u,v;
        cin>>u>>v;
        points[i].x=u;points[i].y=v;
    }
    vector<Points> copy=points;
    while(copy.size()>2){
        convex_hull(copy);
    }
    copy.clear();
    while(q--){
    ll answer=0;
    Points P;
	cin>>P.x>>P.y;
    for(auto itr:ans){
        int okay=0;
        for(ll i=0;i<itr.size();++i){
            if(!count_index(itr[i],itr[(i+1)%itr.size()],P)) {
                okay=1;
				break;
            }
        }
        if(okay==0) answer++;
        else break;
    }
    cout<<answer<<endl;
    }
    ans.clear();
    points.clear();
}
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
}
int main()
{
	fast();
   	int tc;
    cin>>tc;
    while(tc--)
  	{
       solve();
    }
}
