#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a1;
	for(int i=0;i<15;i++)
	{
		if((n-i)%5==0 && (n-i)%10!=0)
		{
			a1=n-i;
			break;
		}
	}
	int ans=a1/5+n/10-1;
	cout<<a1/5<<" "<<n/10<<endl;
}
