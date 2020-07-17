#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a=1,b=2;
	cin>>n;
	if(n==1) {
		cout<<1<<endl;
		return 0;
	}
	if(n>=2&&n<4)
	{
		cout<<"NO SOLUTION"<<endl;
		return 0;
	}
	while(1)
	{
		cout<<b<<" ";
		b=b+2;
		if(b>n) break;
	}
	while(1)
	{
		cout<<a<<" ";
		a=a+2;
		if(a>n) break;
	}
	return 0;
}
