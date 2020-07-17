#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a==9 && b==1)
	cout<<99<<" "<<100<<endl;
	else if(b-a==1)
	{
		cout<<b*100-1<<" "<<b*100<<endl;
	}
	else if(a==b)
	{
		cout<<a*100<<" "<<a*100+1<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
}
