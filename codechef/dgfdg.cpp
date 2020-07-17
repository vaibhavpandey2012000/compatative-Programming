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

struct node *construct_in_pre(int pres,int ins,int inl,string in,string pre)
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
	
	pp->ll=construct_in_pre(pres+1,ins,inindex-1,in,pre);
	pp->rr=construct_in_pre(pres+inindex-ins+1,inindex+1,inl,in,pre);
	return pp;
}

struct node *construct_in_post(int ins,int inl,int poste,string in,string post)
{
	if(poste<0 || ins>inl) return NULL;
	
	struct node *pp=createnode(post[poste]);
	
	int i=ins;
	for(;i<=inl;i++)
	{
		if(in[i]==pp->data)
		break;
	}
	
	pp->ll=construct_in_post(ins,i-1,poste-1+i-inl,in,post);
	pp->rr=construct_in_post(i+1,inl,poste-1,in,post);
	
}

void trevelson(struct node *root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	trevelson(root->ll);
	trevelson(root->rr);
}
int main()
{
	string in,post;
	cin>>in>>post;
	
	root=construct_in_post(0,in.length()-1,post.length()-1,in,post);
	
	trevelson(root);
}
