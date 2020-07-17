#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000005
using namespace std;
ll fxn(int n)
{
	vector<int> v;
	ll ans=n;
	for(int i=2;i*i<=n;i++)
	{
		int flg=1;
		while(n%i==0)
		{
			//cout<<n<<" "<<i<<endl;
			
			if(flg)
			{
				v.push_back(i);
				ans=ans*(i-1);
				flg=0;
			//	cout<<ans<<endl;
			}
			n=n/i;
		}
	}
	if(n>2)
	{
		ans=(ans*(n-1));
		v.push_back(n);
	}
	for(int i=0;i<v.size();i++)
	{
		ans=ans/v[i];
	}
	return ans;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		if(n==2)
		{
			cout<<"1"<<endl;
			continue;
		}
		ll ans=fxn(n);
		cout<<ans<<endl;
	}
}