#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll CLT(int n)
{
	ll ans=1;
	bool flg=1;
	for(int i=0;i<n;i++)
	{
		ans*=(2*n-i);//cout<<2*n-i<<endl;
		ans/=(i+1);//cout<<i+1<<endl;
		if(flg && ans%(n+1)==0)
		{
			ans/=(n+1);
			flg=0;
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	ll ans=CLT(n);
	cout<<ans<<endl;
}
