#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
};
double areaofp(point p0,point p1,point p2)
{
	double ans=abs((p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x));
	return ans;
}
double areaoft(point p1,point p2,point p3)
{
	return areaofp(p1,p2,p3)/2.0;
}
int main()
{
	 point p1,p2,p3;
	 cin>>p1.x>>p1.y;
	 cin>>p2.x>>p2.y;
	 cin>>p3.x>>p3.y;
	 double area_of_parellopide=areaofp(p1,p2,p3);
	 cout<<area_of_parellopide<<endl;
	 double area_of_trangel=areaoft(p1,p2,p3);
	 cout<<area_of_trangel<<endl;
}