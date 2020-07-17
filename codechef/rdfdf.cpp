#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
		res=res*a , b--;
		else
		a=a*a ,b=b/2;
	}
	return res;
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<fastpow(a,b)<<endl;
}
