#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m,x;
		cin>>n>>x>>m;
		int l=x,r=x;
		int cnt=0;
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			if(b<l && a>r)
			continue;
			else if(a<=l && b<=r)
			{
				cnt+=(l-a);
				l=a;
				//cout<<"a"<<endl;
			}
			else if(a>=l && b>=r)
			{
				cnt+=(b-r);
				r=b;
			//	cout<<"b"<<endl;
			}
			else if(l<=a && r>=b)
			{
				cnt=cnt;
				l=l,r=r;
			//	cout<<"c"<<endl;
			}
			else if(a<l && b>=r)
			{
				cnt+=abs(l-a)+abs(b-r)+1;
				l=a,r=b;
				//cout<<"d"<<endl;
			}
			cout<<cnt<<endl;
		}
		cout<<cnt<<endl;
	}
}
