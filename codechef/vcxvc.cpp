#include<bits/stdc++.h>
using namespace std;
int main()
{
	// let center at(0,0) and radius is r
	// line Ax+By+C=0
	// find line and circle tuch or intersect to each other
	double r,A,B,C;
	cout<<"enter radius of circle"<<endl;
	cin>>r;
	cout<<"entr the line equation"<<endl;
	cin>>A>>B>>C;
	double dis=abs(C)/sqrt(A*A+B*B);
	if(dis>r) cout<<"NO intersection point"<<endl;
	else if(dis==r){
		cout<<"one intersection point"<<endl;
		double x0=A*C/(A*A+B*B);
		double y0=B*C/(A*A+B*B);
		cout<<"intersection points at :("<<x0<<","<<y0<<")"<<endl;
	}
	else{
		cout<<"two intersecton point"<<endl;
		double x0=A*C/(A*A+B*B);
		double y0=B*C/(A*A+B*B);
		double d=sqrt(r*r-((C*C)/(A*A+B*B)));
		double m=sqrt((d*d)/(A*A+B*B));
		double ax=x0+B*m,ay=y0-A*m;
		double bx=x0-B*m,by=y0+A*m;
		cout<<"intersection points at :("<<ax<<","<<ay<<")"<<endl;
		cout<<"intersection points at :("<<bx<<","<<by<<")"<<endl;
	} 
}
