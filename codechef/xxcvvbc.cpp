#include<bits/stdc++.h>
using namespace std;
struct points{
	int a,b,c;
};

points cross(points p1,points p2)
{
	points ans;
	ans.a=(p1.b*p2.c-p1.c*p2.b);
	ans.b=(p1.c*p2.a-p1.a*p2.c);
	ans.c=(p1.a*p2.b-p1.b*p2.a);
	return ans;
}
points intersection(points a1,points d1,points a2,points d2)
{
	return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}
int main()
{
	points p1,p2;
	cin>>p1.a>>p1.b>>p1.c;
	cin>>p2.a>>p2.b>>p2.c;
	points p3,p4;
	cin>>p3.a>>p3.b>>p3.c;
	cin>>p4.a>>p4.b>>p4.c;
	points ans=intersection(p1,p3,p2,p4);
	cout<<ans.a<<" "<<ans.b<<" "<<ans.c<<endl;
	
}
