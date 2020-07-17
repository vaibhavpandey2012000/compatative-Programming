#include<bits/stdc++.h>
using namespace std;
int fxn(int n)
{
	if(n==2 || n==1 || n==3)
	{
		return n;
	}
	if(n==4)
	{
		return 2;
	}
	int num=fxn(n-1)+fxn(n-4);
	return num;
}
int main()
{
	int n;
	cin>>n;
	cout<<fxn(n)<<endl;
}