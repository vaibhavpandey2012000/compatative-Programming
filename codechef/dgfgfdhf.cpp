#include <bits/stdc++.h> 
using namespace std; 
#define ll long 
int main() 
{ 
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		ll arr[n+2],pre[n+2],suf[n+2];
		for(int i=1;i<=n;i++)
		cin>>arr[i];
	//	int pp=0;
		pre[0]=0;
		suf[n+1]=0;
		for(int i=1;i<=n;i++)
		{
			pre[i]=pre[i-1]+arr[i];
		}
		for(int i=n;i>=1;i--)
		{
			suf[i]=suf[i+1]+arr[i];
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<pre[i]<<" ";
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++)
//		{
//			cout<<suf[i]<<" ";
//		}
		int pos=-1,val;
		for(int i=2;i<=n-1;i++)
		{
			if(pre[i-1]==suf[i+1])
			{
				pos=i;
				val=pre[i-1];
				break;
			}
		}
		if(pos==-1)
		{
			cout<<"0 0"<<endl;
		}
		else{
			cout<<pos<<" "<<val<<endl;
		}
		
		
	}
	 
} 

