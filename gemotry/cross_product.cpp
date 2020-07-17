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
int dot(points p1,points p2)
{
	return p1.a*p2.a+p1.b*p2.b+p1.c*p2.c;
}
int volume(points p1,points  p2,points p3)
{
	points k=cross(p1,p2);
	return dot(k,p3);
}
int main()
{
	points p1,p2;
	cin>>p1.a>>p1.b>>p1.c;
	cin>>p2.a>>p2.b>>p2.c;
	points ans=cross(p1,p2);
	cout<<ans.a<<" "<<ans.b<<" "<<ans.c<<endl;
	points p3;
	cin>>p3.a>>p3.b>>p3.c;
	int ansv=volume(p1,p2,p3);
	cout<<abs(sansv)<<endl;
	
}