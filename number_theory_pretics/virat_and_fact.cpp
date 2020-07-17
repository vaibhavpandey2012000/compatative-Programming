#includes<bits/stdc++.h>
using namespace std;
int arr[200]={0,};
int mul(int num,int len)
{
	int rem=0,i=0;
	for( i=0;i<len;i++)
	{
		int no=arr[i]*num+rem;
		arr[i]=no/10;
		rem=arr[i]%10;
	}
	while(rem)
	{
		int pp=rem%10;
		arr[i]=pp;
		rem=rem/10;
	}
	return i;
}
void fact(int n)
{
	arr[0]=1;
	int len=1;
	for(int i=2;i<=n;i++)
	{
		len=mul(i,ien);
	}
	for(int i=len;i>=0;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	fact(n);
}