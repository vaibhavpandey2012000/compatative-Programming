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
	return a.x<b.x;
}
void convex_hull(vector<Points> & v)
{
	int nn=v.size();
	if(nn==1)
		return;
	sort(v.begin(),v.end(),&cmp);
	Points p1=v[0],p2=v.back();
	vector<Points> uppper,lower;
	uppper.push_back(p1);
	for(int i=1;i<nn;i++)
	{
		if(i==nn-1||count_index(p1,v[i],p2))
		{
			while (uppper.size() >= 2 && !count_index(uppper[uppper.size()-2], uppper[uppper.size()-1], v[i]))
                uppper.pop_back();
            uppper.push_back(v[i]);
		}
		if (i == nn - 1 || count_indx(p1, v[i], p2)) 
		{
            while(lower.size() >= 2 && !count_indx(lower[lower.size()-2], lower[lower.size()-1], v[i]))
                lower.pop_back();
            lower.push_back(v[i]);
        }
	}
	vector<Points> tpts;
	for (int i = 0; i <uppper.size(); i++)
	{
        tpts.push_back(uppper[i]);
        v.erase(remove(v.begin(),v.end(),uppper[i]),v.end());
    }

    for (int i = lower.size() - 2; i > 0; i--)
    {
        tpts.push_back(lower[i]);
        v.erase(remove(v.begin(),v.end(),lower[i]),v.end());
    }

    vector<Points> temp = v;
    for(auto itr:temp){
        for(int i=0;i<tpts.size();++i){
        int  x=orientation(tpts[i],tpts[(i+1)%tpts.size()],itr);
        if(!x) v.erase(remove(v.begin(),v.end(),itr),v.end());
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
	while(copy.size()>3)
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
			if(okay)
			answer++;
			else 
			break;
		}
		cout<<answer<<endl;
	}
	//ans.clear();
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
