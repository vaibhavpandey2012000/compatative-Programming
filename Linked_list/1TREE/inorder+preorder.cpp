#include<bits/stdc++.h>
using namespace std;

const int maxN=100;

struct node{
	struct node *ll;
	char data;
	struct node *rr;
};


struct node *createnode(char item)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=item;
	temp->ll=temp->rr=NULL;
}

struct node *root=NULL;

struct node *construct(int pres,int ins,int inl,string in,string pre)
{
	if(pres>pre.length()-1||ins>inl) return NULL;
	
	struct node *pp=createnode(pre[pres]);
	
	int inindex=0;
	for(int i=ins;i<=inl;i++)
	{
		if(pp->data==in[i])
		{
			inindex=i;
		}
	}
	
	pp->ll=construct(pres+1,ins,inindex-1,in,pre);
	pp->rr=construct(pres+inindex-ins+1,inindex+1,inl,in,pre);
	return pp;
}

void trevelson(struct node *root)
{
	if(root==NULL)
	return;
	trevelson(root->ll);
	trevelson(root->rr);
	cout<<root->data<<" ";
}
int main()
{
	string in,pre;
	cin>>in>>pre;
	
	root=construct(0,0,in.length()-1,in,pre);
	
	trevelson(root);
}