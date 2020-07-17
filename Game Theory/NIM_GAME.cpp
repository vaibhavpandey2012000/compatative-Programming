#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"enter number of pile:";
	int n;
	cin>>n;
	cout<<"enter coin in each pail:";
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		ans^=temp;
	}
	ans==0 ? cout<<"B wines"<<endl:cout<<"A wines"<<endl;
}