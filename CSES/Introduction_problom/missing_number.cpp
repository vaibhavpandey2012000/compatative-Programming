#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long sum=0;
	for(int i=0;i<n-1;i++)
	{
		int temp;
		cin>>temp;
		sum+=temp;
	}
	cout<<((long long)n*(n+1))/2-sum<<endl;
}/*
int main()
{
	int n;
	cin>>n;
	int ans=1,ans2=0;
	for(int i=0;i<n-1;i++)
	{
		ans=ans^(i+2);
		int temp;
		cin>>temp;
		ans2=ans2^temp;
	}
	cout<<(ans^ans2)<<endl;
}