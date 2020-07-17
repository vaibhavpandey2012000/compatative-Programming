#include<bits/stdc++.h>
using namespace std;
int main()
{
	// let center at(0,0) and radius is r
	// line Ax+By+C=0
	// find line and circle tuch or intersect to each other
	double r0,A,B,C,x0,y0;
	cout<<"enter radius of circle and center point"<<endl;
	cin>>r0>>x0>>y0;
	double x1,y1,r1;
	cout<<"enter radius of circle and center point"<<endl;
	cin>>r1>>x1>>x1;
	x1=x1-x0,y1=y1-y0;
	A=-2*x1,B=-2*y1 ,C=x1*x1+y1*y1+r0*r0-r1*r1;
	double dis=abs(C)/sqrt(A*A+B*B);
	if(dis>r1) cout<<"NO intersection point"<<endl;
	else if(dis==r1){
		cout<<"one intersection point"<<endl;
		double x0=A*C/(A*A+B*B);
		double y0=B*C/(A*A+B*B);
		cout<<"intersection points at :("<<x0<<","<<y0<<")"<<endl;
	}
	else{
		cout<<"two intersecton point"<<endl;
		double x0=A*C/(A*A+B*B);
		double y0=B*C/(A*A+B*B);
		double d=sqrt(r1*r1-((C*C)/(A*A+B*B)));
		double m=sqrt((d*d)/(A*A+B*B));
		double ax=x0+B*m,ay=y0-A*m;
		double bx=x0-B*m,by=y0+A*m;
		cout<<"intersection points at :("<<ax<<","<<ay<<")"<<endl;
		cout<<"intersection points at :("<<bx<<","<<by<<")"<<endl;
	} 
}