#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	for(int i=0;i<=17;i++)
	{
		cout<<i<<"-->"<<((x*y)&i)<<endl;
	}
}
