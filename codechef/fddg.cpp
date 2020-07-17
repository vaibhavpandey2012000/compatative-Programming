#include<bits/stdc++.h>
using namespace std;
int fxn(int n)
{
	int ans=1;
	for(int i=2;i*i<=n;i++)
	{
		int cnt =0;
		while(n%i==0)
		{
			cnt++,n=n/i;
		}
		if(cnt)
		ans*=(cnt+1);
	}
	if(n>2)
	ans=ans*2;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int d=fxn(n);
	cout<<d<<endl;
}
