#include<bits/stdc++.h>
using namespace std;
string minwindow(string s,string p)
{
	int len1=s.length();
	int len2=p.length();
	if(len1<len2)
	return "NOT POSSIBLE";
	
	int has_pat[256]={0};
	int has_str[256]={0};
	
	for(int i=0;i<len2;i++)
	has_pat[p[i]]++;
	
	int start=0,start_ind=-1,min_len=INT_MAX;
	int cnt=0;
	for(int j=0;j<len1;j++)
	{
		has_str[s[j]]++;
		
		if(has_pat[s[j]]!=0 && has_str[s[j]]<=has_pat[s[j]])
		{
			cnt++;
		}
		if(cnt==len2)
		{
			while(has_str[s[start]]>has_pat[s[start]] || has_pat[s[start]]==0)
			{
				if(has_str[s[start]]>has_pat[s[start]])
				{
					has_str[s[start]]--;
				}
				start++;
			}
			int len_window=j-start+1;
			if(min_len>len_window)
			{
				min_len=len_window;
				start_ind=start;
			}
		}
	}
	if(start_ind == -1)
	return "NOT POSSIBLE";
	else
	return s.substr(start_ind,min_len);
}
int main()
{
	string s,p;
	getline(cin,s);
	getline(cin,p);
	string ans=minwindow(s,p);
	cout<<ans<<endl;
}

