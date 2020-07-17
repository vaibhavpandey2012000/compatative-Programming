#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
};
double area(vector<point> &p)
{
	double res=0;
	for(int i=0;i<p.size();i++)
	{
		point pp=i ? p[i-1]:p.back();
		point qq=p[i];
		res+=(pp.x-qq.x)*(pp.y+qq.y);
	}
	return abs(res/2.0);
}

int main()
{
	int n;
	cout<<"enter no of point in space:";
	cin>>n;
	vector<point>p(n);
	for(int i=0;i<n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
	double a=area(p);
	cout<<a<<endl;
}
