#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		long n;
		cin>>n;
		if(n==1) 
		{
			cout<<"FastestFinger"<<endl;
			continue;
		}
		else if(n==2)
		{
			cout<<"Ashishgup"<<endl;
			continue;
		}
		else if(n%2==1)
		{
			cout<<"Ashishgup"<<endl;
			continue;
		}
		else 
		{
			int cntr=0,cnt2=0;
			for(int i=2;i*i<=n;i++)
			{
				if(n%i==0)
				{
					while(n%i==0)
					{
						n/=i;
						if(i==2)cnt2++;
						else cntr++;
					}
				}
			}
			if(n==2) cnt2++;
			if(n>2) cntr++;
			if(cnt2>1)
			{
				if(cntr)cout<<"Ashishgup"<<endl;
				else cout<<"FastestFinger"<<endl;
			}
			else{
				if(cntr>1)cout<<"Ashishgup"<<endl;
				else cout<<"FastestFinger"<<endl;
			}
		}
	}
}
