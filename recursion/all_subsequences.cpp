#include<bits/stdc++.h>
using namespace std;
void subseq(char *in,char *out,int i,int j)
{
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	out[j]=in[i];
	subseq(in,out,i+1,j+1);
	subseq(in,out,i+1,j);
}
int main()
{
	char in[100],out[100];
	cin>>in;
	subseq(in,out,0,0);
}