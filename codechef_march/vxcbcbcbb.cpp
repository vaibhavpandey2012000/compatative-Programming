#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		cin>>s;
		int arr[s.length()];
		int op=0,cl=0;
		memset(arr,-1,sizeof(arr));
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='(') op++;
			else cl++;
			if(cl>op)
			{
				cl=0;
				op=0;
			}
			else if(op>0 && s[i]==')')
			{
				arr[i-2*cl+1]=i;
				cout<<i<<" "<<i-2*cl+1<<endl;
			}
			
		}
		
		
		for(int i=s.length()-2;i>=0;i--)
		{
			if(s[i]==')' && arr[i+1]!=-1)
			arr[i]=arr[i+1];
		}
		
		for(int i=0;i<s.length();i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		int q;
		cin>>q;
		while(q--)
		{
			int p;
			cin>>p;
			p--;
			if(arr[p]!=-1)
			cout<<arr[p]+1<<endl;
			else
			cout<<arr[p]<<endl;
		}
		
		
	}
}
