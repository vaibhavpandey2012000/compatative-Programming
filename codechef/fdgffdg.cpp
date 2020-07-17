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
		if(n==1)
		{
			cout<<n<<" "<<arr[0]<<" 0"<<endl;
			continue;
		}
		int i=1,j=n-1;
		int cnt=1;
		long long aa=arr[0],bb=0,sm=arr[0];
		bool flp=0;
		while(1)
		{
			if(flp)
			{
				cnt++;
				long long sum=0;
				while(sum<=sm)
				{
				//	cout<<sum<<" "<<sm<<endl;
					sum+=arr[i];
					i++;
					if(i>j) break;
				}
			//	cout<<"pp"<<"";
				aa+=sum,sm=sum;
				flp=0;
			}
			else{
					cnt++;
					long long sum=0;
					while(sum<=sm)
					{
					//	cout<<sum<<" "<<sm<<endl;
						sum+=arr[j];
						j--;
						if(i>j)break;
					}
				//	cout<<"ss"<<endl;
					bb+=sum ,sm=sum;
					flp=1;
			}
		//	cout<<i<<" "<<j<<endl;
			if(i>j) break;
		}
		cout<<cnt<<" "<<aa<<" "<<bb<<endl;
	}
}
