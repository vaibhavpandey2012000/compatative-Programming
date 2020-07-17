#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int p=-1;
	int cnt=0;
	while(p<=n)
	{
		if(arr[p+2]==1)
		p++;
		else
		p+=2;
	//	cout<<p<<" ";
		cnt++;
	}
	cout<<cnt-1<<endl;
}
