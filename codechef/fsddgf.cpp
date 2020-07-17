#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,p=0;
		cin>>n;
		vector<int> v(n);
		
		for(int i=0;i<n;i++)
		cin>>v[i];
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++)
		{
			if(v[i]==-1) continue;
			int flg=1;
			for(int j=i+1;j<n;j++)
			{
				if(v[j]==-1) continue;
				if((v[i]%2==v[j]%2) || (abs(v[i]-v[j])==1))
				{
					flg=0;
					v[i]=-1;
					v[j]=-1;
				}	
			}
			if(flg){
			cout<<"NO"<<endl;
			p=1;
			break;	
			} 
		}
		if(p==0)
		cout<<"YES"<<endl;
	}
}
