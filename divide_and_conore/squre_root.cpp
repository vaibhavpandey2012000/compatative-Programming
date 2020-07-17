#include<bits/stdc++.h>
using namespace std;
float binarySearch(int n,int p)
{
	int s=0,e=n;
	float ans;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(mid*mid<=n)
		{
			ans=mid;
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
	}
	float aa=1;
	for(int i=0;i<p;i++)
	{
		aa=aa*.1;
		for(int i=1;i<9;i++)
		{
			ans=ans+aa;
			if(ans*ans>n)
			{
				ans=ans-aa;
				break;
			}
		}
	}
	return ans;
}
int main()
{
	int n,p;
	cin>>n>>p;
	float ans=binarySearch(n,p);
	cout<<ans<<endl;
}