#include<bits/stdc++.h>
using namespace std;
#define ll long long
int collinear(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) 
{  
    int a = x1 * (y2 - y3) +  x2 * (y3 - y1) +  x3 * (y1 - y2); 
    if (a == 0) 
        return 1;
    else
        return 0; 
} 

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];
		int q;
		cin>>q;
		while(q--)
		{
			int a,b;
			cin>>a>>b;
			int pp=binary_search(arr,arr+n,a+b);
			if(pp){
				cout<<"-1"<<endl;
				continue;
			}
			auto up=upper_bound(arr,arr+n,a+b)-arr;
			cout<<up<<endl;
		}
	}
}
