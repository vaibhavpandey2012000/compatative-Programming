#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
};
int orintation(point p,point q,point r)
{
	int val=(q.x-p.x)*(r.y-q.y)-(q.y-p.y)*(r.x-q.x);
	if(val==0) return 0;
	if(val>0) return 1;
	else return 2;
}
vector<point> convex_hull(vector<point> &p)
{
	vector<point> hull;
	if(p.size()<3)return hull;
	int l=0;
	for(int i=0;i<p.size();i++)
	{
		if(p[i].x<p[l].x)
		l=i;
	}
	int pp=l,qq;
	
	do{
		hull.push_back(p[pp]);
		qq=(pp+1)%p.size();
		for(int i=0;i<p.size();i++)
		{
			if(orintation(p[pp],p[i],p[qq])==2)
			{
				qq=i;
			}
		}
		pp=qq;
	}
	while(pp!=l);
}
int main()
{
	int n;
	cin>>n;
	vector<point>p(n);
	for(int i=0;i<n;i++)
	cin>>p[i].x>>p[i].y;
	vector<point> ans=convex_hull(p);
	for(auto e:ans)
	{
		cout<<e.x<<" "<<e.y<<endl;
	}
}
