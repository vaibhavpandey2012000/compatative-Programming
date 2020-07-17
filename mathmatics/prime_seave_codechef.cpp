#include<bits/stdc++.h>
using namespace std;
const int MX=1000000+1;
int seave[MX]={0};
void prime_seave()
{
	seave[1]=1;
	for(int i=2;i<=MX;i++)
	{
		int ii=1;
		if(seave[i]==0)
		{
			seave[i]=ii;
			ii++;
			for(int j=2*i;j<=MX;j+=i)
			{
				if(seave[j]==0)
				{
					seave[j]==ii;
					ii++;
				}
			}
		}
	}
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cout<<seave[i]<<" ";
		}
	}
}