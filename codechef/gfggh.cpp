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
		for(int i=0;i<64;i++)
		{
			if(i==0)
			{
				cout<<"O";
			}
			else if(i-k>=0)
			{
				cout<<"X";
			}
			else{
				cout<<".";
			}
			if(i!=0 && (i+1)%8==0)
			cout<<endl;
		}
	}
}
