#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void primeseave(int n)
{
	v.push_back(2);
	int arr[n+1]={0,};
	//memset(arr,0,sizeof(arr));
	for(int i=3;i<=n;i++)
	{
		arr[i]=1;
	}
	for(int i=3;i<=n;i+=2)
	{
		if(arr[i])
		{
			v.push_back(i);
			for(int j=i*i;j<=n;j+=i)
			{
				arr[j]=0;
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	primeseave(n);
	for(auto i:v)
	{
		cout<<i<<",";
	}
}