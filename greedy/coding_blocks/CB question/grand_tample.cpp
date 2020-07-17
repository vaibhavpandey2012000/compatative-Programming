#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc=1;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<long long>x,y;
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			x.push_back(a);
			y.push_back(b);
		}	
		x.push_back(0);
		y.push_back(0);
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		long long dx=0,dy=0;
		for(int i=1;i<x.size();i++)
		{
			if(dx<abs(x[i]-x[i-1])) dx=abs(x[i]-x[i-1]-1);
			if(dy<abs(y[i]-y[i-1])) dy=abs(y[i]-y[i-1]-1);
		}
		cout<<dx*dy<<endl;
	}
}