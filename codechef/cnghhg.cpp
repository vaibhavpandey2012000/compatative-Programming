#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int tt=0;
void ff()
{
	for(int i=0;i<10000;i++)
	{
		tt+=(i+1);
		v.push_back(tt);
		if(tt>100000)
		break;
	}
}

int main() 
{
	ff();
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++)
	{
		int n;
		cin>>n;
		int cnt=1;
		for(int i=1;i<500;i++)
		{
			if(v[i]>n)
			break;
			cnt++;
		}
		cout<<cnt<<endl;
	}
} 

