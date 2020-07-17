#include<bits/stdc++.h>
using namespace std;
struct points{
	int a,b,c;
};
int dot(points p1,points p2)
{
	return(p1.a*p2.a+p1.b*p2.b+p1.c*p2.c);
}
double lengthvector(points p1)
{
	return sqrt(dot(p1,p1));
}
double angle(points p1,points p2)
{
	return acos(dot(p1,p2)/lengthvector(p1)*lengthvector(p2));
}
int main()
{
	points p1,p2;
	cin>>p1.a>>p1.b>>p1.c;
	cin>>p2.a>>p2.b>>p2.c;
	int ans1=dot(p1,p2);
	cout<<ans1<<endl;
	double length_of_vector=lengthvector(p1);
	cout<<length_of_vector<<endl;
	int projection_a_on_b=dot(p1,p2)/sqrt(dot(p2,p2));
	cout<<projection_a_on_b<<endl;
	double angl=angle(p1,p2);
	cout<<angl<<endl;
}