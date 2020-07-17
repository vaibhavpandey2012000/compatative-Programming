#include<bits/stdc++.h>
using namespace std;
const int maxN=100005;
vector<int>arr[maxN],topo;
int in[maxN];
void khans(int v)
{
	queue<int>q;
	for(int i=1;i<v;i++)
	if(in[i]==0) q.push(i);
	while(!q.empty())
	{
		int node=q.front();
		cout<<node<<" ";
		q.pop();
		for(auto ch:arr[node])
		{
			in[ch]--;
			if(in[ch]==0) 
			q.push(ch);
		}	
	}
		cout<<"p"<<endl;
}
int main(){
	int v,e,a,b;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		in[b]++;
	}
	khans(v);
}
