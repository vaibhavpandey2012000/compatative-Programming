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
		int arr[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];
		int bb=0,ac=0;
		long sm=0;
		int cnt=0;
		int fp=0;
		int i=0,j=n-1;
		while(1){
			if(fp=0)
			{
				
				int sum=0;
				while(sum<=fp)
				{
					cnt++;
					sum+=arr[i];
					i++;
					if(i>j) break;
				}
				fp=sum;
				ac+=sum;
			}
			else{
				int sum=0;
				while(sum<=fp)
				{
					cnt++;
					sum+=arr[j];
					j--;
					if(i>j)break;
				}
				fp=sum;
				bb+=sum;
			}
			if(i>j) break;
		}
		cout<<cnt/2+(cnt&1)<<" "<<ac<<" "<<bb<<endl;
	}
}
