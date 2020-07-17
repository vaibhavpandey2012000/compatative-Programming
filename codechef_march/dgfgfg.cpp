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
		map<int,int >mp;
		
		for(int i=0;i<s.length();i++)
		{
//			if(s[i]==')')
//			continue;
			int op=0,cl=0;
			for(int j=i;j<s.length();j++)
			{
				if(s[j]=='(')
				op++;
				if(s[j]==')')
				cl++;
				if(op==cl || (cl>0 && (op==1&&s[j+1]==')'))){
					mp[i]=j;
					break;
				}
				
				else if(cl>op && op!=0)
				break;
			}
		}
		for(auto e:mp)
		{
			cout<<e.first<<" ->"<<e.second;
			
			cout<<endl;
		}
		int q;
		cin>>q;
		while(q--)
		{
			int p;
			cin>>p;
			p--;
			if(mp.find(p)!=mp.end())
			{
				cout<<mp[p]<<endl;
			}
			else{
				cout<<"-1"<<endl;
			}
		}
		
		
	}
}
