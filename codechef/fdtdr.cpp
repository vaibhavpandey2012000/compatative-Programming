#include<bits/stdc++.h>
using namespace std;
struct pt {
    long  x, y;
    inline bool operator ==(pt a){
        return (a.x==x&&a.y==y);
    }
};
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
vector<vector<pt>>ans;
int orientation(pt p, pt q, pt r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0; 
    return (val > 0)? 1: 2; 
}
bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
bool cmp(pt a,pt b)
{
	return a.x<b.x||(a.x==b.x && a.y==b.y);
}
void convex_hull(vector<pt> & a)
{
	int nn=a.size();
	if(nn==1)
		return;
	sort(a.begin(),a.end(),&cmp);
	pt p1=a[0],p2=a.back();
	vector<pt> up,down;
	up.push_back(p1);
	for(int i=1;i<nn;i++)
	{
		if(i==nn-1||cw(p1,a[i],p2))
		{
			while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
		}
		if (i == nn - 1 || ccw(p1, a[i], p2)) 
		{
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
	}
	vector<pt> tpts;
	for (int i = 0; i <up.size(); i++)
	{
        tpts.push_back(up[i]);
        a.erase(std::remove(a.begin(),a.end(),up[i]),a.end());
    }

    for (int i = down.size() - 2; i > 0; i--)
    {
        tpts.push_back(down[i]);
        a.erase(std::remove(a.begin(),a.end(),down[i]),a.end());
    }

    vector<pt> temp = a;
    for(auto itr:temp){
        for(int i=0;i<tpts.size();++i){
        int  x=orientation(tpts[i],tpts[(i+1)%tpts.size()],itr);
        if(!x) a.erase(remove(a.begin(),a.end(),itr),a.end());
        }
    }
    ans.push_back(tpts);
}
void solve()
{
	int n,q;
	cin>>n>>q;
	vector<pt> points(n),copy;
	for(int i=0;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		points[i].x=u;
		points[i].y=v;
	}
	copy=points;
	while(copy.size()>2)
	{
		convex_hull(copy);
	}
	copy.clear();
	for(int i=0;i<q;i++)
	{
		long answer=0;
		pt p;
		cin>>p.x>>p.y;
		for(auto itr:ans)
		{
			int okay=0;
			for(int i=0;i<itr.size();i++)
			{
				if(!cw(itr[i],itr[(i+1)%itr.size()],p)){
					okay=1;
					break;
				}
			}
			if(!okay)
			answer++;
			else 
			break;
		}
		cout<<answer<<endl;
	}
	ans.clear();
	points.clear();
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
