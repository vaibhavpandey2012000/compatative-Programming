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

struct node *construct(int instart,int inend,int postend,string in,string post)
{
	if(postend<0||instart>inend) return NULL;
	struct node *pp=createnode(post[postend]);
	
	int i=instart;
	for(;i<inend;i++)
	{
		if(pp->data==in[i])
		break;
	}
	
	pp->ll=construct(instart,i-1,postend-1+i-inend,in,post);
	pp->rr=construct(i+1,inend,postend-1,in,post);
	
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

int hight(struct node *root)
{
	if(root==NULL)
	return 0;
	else
	return max(hight(root->ll)+1,hight(root->rr)+1);
}
int main()
{
	string in,post;
	cin>>in>>post;
	
	root=construct(0,in.length()-1,post.length()-1,in,post);
	
	trevelson(root);
	
	cout<<endl<<hight(root)<<endl;
}
