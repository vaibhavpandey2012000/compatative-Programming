#include<bits/stdc++.h>
using namespace std;
string s[10]={"","","abc","def","ghi","jkl","mno","pgrs","tuv","wxyz"};
void phonekey(char *in,char *out,int i,int j)
{
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	int p=in[i]-'0';
	if(p==0||p==1)
	{
		phonekey(in,out,i+1,j);
	}
	string ss=s[p];
	
	for(int pp=0;pp<ss.length();pp++)
	{
		out[j]=ss[pp];
		phonekey(in,out,i+1,j+1);
	}

}
int main()
{
	char in[100],out[100];
	cin>>in;
	phonekey(in,out,0,0);
}
