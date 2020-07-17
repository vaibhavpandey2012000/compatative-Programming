#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cout<<i+1<<" ";
	cout<<endl;
	for(int i=1;i<n;i++)
	{
		int cnt=1;
		for(int j=1;j<=n-i;j++)
		cout<<cnt<<" " ,cnt++;
		int p=2*i-1;
		while(p--)
		cout<<"* ";
		cout<<endl;
	}
}
