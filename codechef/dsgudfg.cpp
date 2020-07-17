#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	for(int i=0;i<=35;i++)
	{
		cout<<i<<"-->"<<(x&i)*(y&i)<<endl;
	}
}
