#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
ll calc(set<ll> v)
{
	int mn=1;
	while(v.find(mn)!=v.end())
	mn++;
	return mn;
}
int main(){
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		ll sum=0;
		for(int i=0; i<1<<n; i++)
		{
			set<ll> s;
			int temp=i;
			int j=0;
			while(temp)
			{
				if (temp&1) // if jth bit is set print a[j]
				{
					s.insert(a[j]);
				//	cout<<a[j]<<" ";
				}
				temp >>= 1;
				j++;
			}
			sum=(sum+calc(s))%MOD;
			s.clear();
		//	cout<<endl;
		}
		cout<<sum<<endl;
		
	}

}

