#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	
	while(tc--)
	{
		int k;
		cin>>k;
		k=64-k;
		for(int i=1;i<=64;i++)
		{
			if(i==64)
			{
				cout<<"0";
				break;
			}
			if(k)
			{
				cout<<"X";
				k--;
			}
			else{
				cout<<".";
			}
			if(i%8==0) cout<<endl;
		}
		
	}
}
