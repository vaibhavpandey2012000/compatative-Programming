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
		vector<int> e,o;
		for(int i=0;i<2*n;i++)
		{
			int temp;
			cin>>temp;
			if(temp%2==0)
			e.push_back(i+1);
			else
			o.push_back(i+1);
		}
		if(e.size()%2==1)
		{
			for(int i=0;i<e.size()-1;i+=2)
			{
				cout<<e[i]<<" "<<e[i+1]<<endl;
			}
			for(int i=0;i<o.size()-1;i+=2)
			{
				cout<<o[i]<<" "<<o[i+1]<<endl;
			}
		}
		else
		{
			if(e.size()==0)
			{
				for(int i=0;i<e.size()-2;i+=2)
				{
					cout<<e[i]<<" "<<e[i+1]<<endl;
				}
				for(int i=0;i<o.size();i+=2)
				{
					cout<<o[i]<<" "<<o[i+1]<<endl;
				}
			}
			else
			{
				for(int i=0;i<e.size();i+=2)
				{
					cout<<e[i]<<" "<<e[i+1]<<endl;
				}
				for(int i=0;i<o.size()-2;i+=2)
				{
					cout<<o[i]<<" "<<o[i+1]<<endl;
				}
			}
		}
	}
}
