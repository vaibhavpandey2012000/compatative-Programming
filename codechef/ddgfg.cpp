#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll pow(ll a,ll b)
{
	if(b==0)
	return 1;
	int ans=pow(a,b/2);
	ans=(ans*ans);
	if(b&1)
	return (ans*a);
	return ans;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll a,b,x;
		cin>>a>>b>>x;
		if(a==1 && x==1)
		{
			cout<<1<<endl;
			continue;
		}
		else if(b<0)
		{
			cout<<"0"<<endl;
			continue;
		}
		else{
			ll num=pow(a,b);
			//cout<<num<<endl;
			ll pp=num%x;
			if(pp<=x/2)
			{
				cout<<num-pp<<endl;
			}
			else 
			{
				pp=x-pp;
				cout<<num+pp<<endl;
			}
		}
	}
	
}
