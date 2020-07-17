#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool sorted(int *v,int n)
{
	if(n==1)
		return true;
	if(v[0]<v[1] && sorted(v+1,n-1))
		return true;
	else
		return false;
}
int main()
{
	int n;
	cin>>n;
	int v[n];
	for(int i=0;i<n;)
	{
		cin>>v[i];
		i++;
	}
	bool istrue=sorted(v,n);
	cout<<istrue<<endl;
}