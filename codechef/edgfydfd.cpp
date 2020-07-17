#include<bits/stdc++.h>
using namespace std;
string fxn(string s,string p)
{
	string minwin="";
	int j=0,mn=s.length()+1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==p[j])
		{
			j++;
			if(j==p.length())
			{
				int end=i+1;
				j--;
				while(j>=0)
				{
					if(p[j]==s[i])
					j--;
					i--;
				}
				i++;
				j++;
				if(end-i<mn){
					mn=end-i;
					minwin=s.substr(i,end);	
				}	
			}
		}
	}
	return minwin;
}
int main()
{
	string s,p;
	getline(cin,s);
	getline(cin,p);
	string mtc=fxn(s,p);
	if(mtc=="")
	{
		cout<<"NOT FOUND"<<endl;
	}
	else
	{
		cout<<mtc<<endl;
	}
	
}
