#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
};
struct Line{
	double a,b,c;
};
double det(double a,double b,double c,double d)
{
	return a*d-b*c;
}
bool intersection(Line l1,Line l2,point &ans)
{
	double zn=det(l1.a,l1.b,l2.a,l2.b);
	if(abs(zn)<0.00001)
	return false;
	ans.x=-det(l1.c,l1.b,l2.c,l2.b)/zn;
	ans.y=-det(l1.a,l1.c,l2.a,l2.c)/zn;
	return true;
}
int main()
{
	point ans;
	Line l1,l2;
	cin>>l1.a>>l1.b>>l1.c;
	cin>>l2.a>>l2.b>>l2.c;
	if(intersection(l1,l2,ans))
	{
		cout<<ans.x<<" "<<ans.y<<endl;
	}
	else
	{
		if(l2.a!=0 && l2.b!=0 && l2.c!=0 && l1.a/l2.a==l1.b/l2.b && l1.a/l2.a==l1.c==l2.c)
		cout<<"Pallel to each other"<<endl;
		else
		cout<<"Not intersecting"<<endl;
	}
}
