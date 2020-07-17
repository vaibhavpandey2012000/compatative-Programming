#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int s=0;
		for(int i=0;i<64;i++)
		{
			int num=i^(i+1);
			s+= __builtin_popcount(num);
			cout<<num<<"-->"<< __builtin_popcount(num)<<"  "<<s<<endl;
		}
	}
}
