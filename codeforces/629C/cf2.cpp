#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		int cnt=0,sum=0;
		int p1,p2;
		for(int i=1;i<=n;i++)
		{
			if(sum+i>=k)
			{
				p2=k-sum;
				p1=i+1;
				break;
			}
			sum+=i;
		}
	//	cout<<p1<<" "<<p2<<endl;
		for(int i=n;i>=1;i--)
		{
			if(i==p1 || i==p2)
			{
				cout<<"b";
			}
			else
			cout<<"a";
		}
		cout<<endl;
	}
}