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
			int pp;
			if(a>b)
			pp=a;
			else
			pp=b;
			int cll=0;
			for(int i=0;i<n;i++)
			{
//				if(arr[i]>pp)
//				break;
				int cl=collinear(arr[i], 0, 0,arr[i], a, b) ;
				if(cl==1){
					cll=1;
					break;
				}
				
			}
			if(cll==1)
			{
				cout<<"-1"<<endl;
			}
			else{
				auto lw=upper_bound(arr,arr+n,pp)-arr;
				cout<<lw<<endl;
			}
			
		}
	}
}
