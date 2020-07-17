#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int ll=(b-a);
		int uu=(d-c);
		int x,y,x1,x2,y1,y2;
		cin>>x>>y>>x1>>y1>>x2>>y2;
		if(((a|b)&&(x1==x2))||((c|d)&&(y1==y2)))
		{
			cout<<"No"<<endl;
			continue;
		}
		if(x1<=(x+ll) && x2>=(x+ll) && y1<=(y+uu) && y2>=(y+uu))
		{
			cout<<"Yes"<<endl;
			continue;
		}
		cout<<"No"<<endl;
	}
}