#include<bits/stdc++.h>
using namespace std;
struct Points {
    long  x, y;
    inline bool operator ==(Points a){
        return (a.x==x&&a.y==y);
    }
};
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
vector<vector<Points>>ans;
int orientation(Points p, Points q, Points r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0; 
    return (val > 0)? 1: 2; 
}
bool count_indx(Points a, Points b, Points c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

bool count_index(Points a, Points b, Points c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
bool cmp(Points a,Points b)
{
	return a.x<b.x||(a.x==b.x && a.y==b.y);
}
void convex_hull(vector<Points> & a)
{
	int nn=a.size();
	if(nn==1)
		return;
	sort(a.begin(),a.end(),&cmp);
	Points p1=a[0],p2=a.back();
	vector<Points> uppper,lower;
	uppper.push_back(p1);
	for(int i=1;i<nn;i++)
	{
		if(i==nn-1||count_index(p1,a[i],p2))
		{
			while (uppper.size() >= 2 && !count_index(uppper[uppper.size()-2], uppper[uppper.size()-1], a[i]))
                uppper.pop_back();
            uppper.push_back(a[i]);
		}
		if (i == nn - 1 || count_indx(p1, a[i], p2)) 
		{
            while(lower.size() >= 2 && !count_indx(lower[lower.size()-2], lower[lower.size()-1], a[i]))
                lower.pop_back();
            lower.push_back(a[i]);
        }
	}
	vector<Points> tpts;
	for (int i = 0; i <uppper.size(); i++)
	{
        tpts.push_back(uppper[i]);
        a.erase(remove(a.begin(),a.end(),uppper[i]),a.end());
    }

    for (int i = lower.size() - 2; i > 0; i--)
    {
        tpts.push_back(lower[i]);
        a.erase(remove(a.begin(),a.end(),lower[i]),a.end());
    }

    vector<Points> temp = a;
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
	vector<Points> points(n),copy;
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
		Points p;
		cin>>p.x>>p.y;
		for(auto itr:ans)
		{
			int okay=0;
			for(int i=0;i<itr.size();i++)
			{
				if(!count_index(itr[i],itr[(i+1)%itr.size()],p)){
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
