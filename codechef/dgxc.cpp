#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
};

int area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 
  
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) 
{    
   float A = area (x1, y1, x2, y2, x3, y3);    
   float A1 = area (x, y, x2, y2, x3, y3);   
   float A2 = area (x1, y1, x, y, x3, y3);    
   float A3 = area (x1, y1, x2, y2, x, y); 
   return (A == A1 + A2 + A3); 
} 

int det(point p,point q)
{
	return (p.x*q.x-p.y*q.x);
}
bool chackpoint(vector<point>&p,point pp)
{
	int mx=p.size()-1,mn=1;
	point u={pp.x-p[0].x,pp.y-p[0].y};
	while(1)
	{
		point v={p[mx].x-p[0].x,p[mx].y-p[0].y};
		point w={p[mn].x-p[0].x,p[mn].y-p[0].y};
		int d1=det(v,u);
		int d2=det(w,u);
		if(mx-mn==1)
		{
			if(isInside(p[0].x, p[0].y, p[mn].x, p[mn].y, p[mx].x, p[mx].y, pp.x, pp.y) )
			return true;
			else
			return false;
		}
		
		if(d2>0 || d1<0)
		return false;
		
		int minp=ceil((mx+mn)/2.0);
		w={p[minp].x-p[0].x,p[minp].y-p[0].y};
		d2=det(w,u);
		if(d2<=0)
		mn=minp;
		else
		mx=minp;
		int maxp=ceil((mx+mn)/2.0);
		if(abs(mn-maxp)==1) break;
		v={p[maxp].x-p[0].x,p[maxp].y-p[0].y};
		d1=det(v,u);
		if(d1>=0)
		mx=maxp;
		else
		mn=minp;	
	}
}
int main()
{
	int n;
	cin>>n;
	vector<point> p(n);
	for(int i=0;i<n;i++)
	cin>>p[i].x>>p[i].y;
	point pp;
	cin>>pp.x>>pp.y;
	bool ans=chackpoint(p,pp);
	ans?cout<<"YES"<<endl :cout<<"NO"<<endl;
}
