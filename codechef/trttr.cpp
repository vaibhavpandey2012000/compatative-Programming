#include<bits/stdc++.h>
using namespace std;
int dis(int x1,int y1,int x2,int y2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	int x1,y1,x2,y2;
	int r1,r2;
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>r1>>r2;
	int dd=dis(x1,y1,x2,y2);
	if(x1==x2&& y1==y2 && r1==r2)
	{
		cout<<"overlaping"<<endl;
	}
	else if(x1==x2&& y1==y2 && r1!=r2)
	{
		cout<<"concentric"<<endl;
	}
	else if((r1+r2)*(r1+r2)==dd)
	{
		cout<<"touches at 1 point"<<endl;
	}
	else if((r1-r2)*(r1-r2)==dd)
	{
		cout<<"touches at 1 point"<<endl;
	}
	else if((r1+r2)*(r1+r2)<dd ||(r1-r2)*(r1+r2) <dd)
	{
		cout<<"far-apart"<<endl;
	}
	else
	{
		cout<<"tuches at 2 point"<<endl;
	}
}
