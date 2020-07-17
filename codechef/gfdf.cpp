#include<bits/stdc++.h>
using namespace std;
int main()
{
	long tc;
	cin>>tc;
	while(tc--)
	{
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		long long  ans=abs(c-a)*abs(d-b)+1;
		cout<<ans<<endl;
	}
}
