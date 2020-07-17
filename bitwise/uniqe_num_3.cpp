#include<bits/stdc++.h>
# define ll long long 
using namespace std;
int arr[64]={0};
void make_vec(int n)
{
	int pos=0;
	while(n)
	{
		if(n&1==1)
		{
			arr[pos]=(arr[pos]+1)%3;
		}
		n=(n>>1);
		pos++;
	}
}
int main()
{  
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		make_vec(v[i]);
	}
	ll num=0;
	for(int i=0;i<32;i++)
	{
		if(arr[i])
			num+=(1<<i);
	}
	cout<<num<<endl;

}