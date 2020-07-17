#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<"FastestFinger"<<endl;
			continue;
		}
		if(n==2)
		{
			cout<<"Ashishgup"<<endl;
			continue;
		}
		else{
			if(n%2==1)
			{
				cout<<"Ashishgup"<<endl;
				continue;
			}
			vector<int> vv;
			for(int i=2;i<=sqrt(n);i++)
			{
				if(n%i==0)
				{
					vv.push_back(i);
				}
				int pp=n/i;
				if(pp%2==1 && n%pp==0)
				{
					vv.push_back(pp);
				}
			}
			if(vv.size()==0)
			{
				cout<<"FastestFinger"<<endl;
				continue;
			}
			else
			{
				int ppp=1;
				for(int i=0;i<vv.size();i++)
				{
					if((n/vv[i])==2)
					{
						ppp=0;break;
					}
					
				}
				if(ppp) cout<<"FastestFinger"<<endl;
				else cout<<"Ashishgup"<<endl;
			}
		}
	}
}
