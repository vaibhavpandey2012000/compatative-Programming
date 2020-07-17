#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int c1=0,c2=0,c3=0,f=1;
		int n;
		cin>>n;
		vector<int>v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		for(int i=0;i<n;i++)
		{
			if(v[i]==5)
			c1++;
			else if(v[i]==10)
			c2++,c1--;
			else if(v[i]==15)
			{
				if(c2>0)
				c2--;
				else
				c1=c1-2;
			}
			if(c1<0 || c2<0 || c3<0)
			{
				f=0;
				cout<<"NO"<<endl;
			}
		}
		if(f)
		cout<<"YES"<<endl;
	}
}
