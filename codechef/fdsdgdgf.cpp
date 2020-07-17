#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> arr(n),b(n);
		for(int i=0;i<n;i++)
		cin>>arr[i];
		for(int j=0;j<n;j++)
		cin>>b[j];
		int flg=1;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(arr[i]>arr[j] && b[i]!=b[j])
				{
					swap(arr[i],arr[j]);
					swap(b[i],b[j]);
				}
			}
		}
		for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
		for(int i=0;i<n;i++)
		cout<<b[i]<<" ";
		cout<<endl;
		for(int i=0;i<n-1;i++)
		if(arr[i]>=arr[i+1]){
			flg=0;
			break;
		}
		
		if(flg==0) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
