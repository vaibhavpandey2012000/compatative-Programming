#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[10][10]={0,};
	int vv=1,vc=1;
	for(int i=0;i<10;i++)
	{
		int r=0,c=i;
		while(c<10)
		{
			arr[r][c]=vv;
			vv++;
			r++,c++;
		}
		r=i,c=0;
		while(r<10)
		{
			arr[r][c]=vc;
			vc++;
			r++,c++;
		}
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<setw(5)<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
