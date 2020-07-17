#include<bits/stdc++.h>
using namespace std;
bitset<30> col,d1,d2;
void solveNqueen(int r,int n,int &ans)
{
	if(r==n) {
		ans++;
		return;
	}
	for(int c=0;c<n;c++)
	{
		if(!col[c] && !d1[r-c+n-1] && !d2[r+c])
		{
			col[c]=d1[r-c+n-1]=d2[r+c]=1;
			solveNqueen(r+1,n,ans);
			col[c]=d1[r-c+n-1]=d2[r+c]=0;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int ans=0;
	solveNqueen(0,n,ans);
	cout<<ans<<endl;
}
