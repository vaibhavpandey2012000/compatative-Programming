#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *ll;
	struct node *rr;
	bool lt;
	bool rt;
};
struct node *root=NULL;
void fun()
{
	cout<<"1.insert"<<endl;
	cout<<"2.inorder"<<endl;
	cout<<"3.preorder"<<endl;
	cout<<"default.exit"<<endl;
}
struct node *insertion(struct node *root)
{
	struct node *temp,*par,*ptr;
	int found=0;
	ptr=root,par=NULL;
	int val;
	cin>>val;
	while(ptr!=NULL)
	{
		if(ptr->data==val)
		{
			found=1;
			break;
		}
		par=ptr;
		if(ptr->data>val)
		{
			if(ptr->lt==false)
			ptr=ptr->ll;
			else
			break;
		}
		else{
			if(ptr->rt==false)
			ptr=ptr->rr;
			else
			break;
		}
	}
	if(found==1)
	{
		cout<<"Duplicate"<<endl;
	}
	else{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=val;
		temp->lt=true;
		temp->rt=true;
		if(par==NULL)
		{
			root=temp;
			temp->ll=NULL;
			temp->rr=NULL;
		}
		else if(par->data>val)
		{
			temp->ll=par->ll;
			temp->rr=par;
			par->lt=false;
			par->ll=temp;
		}
		else{
			temp->rr=par->rr;
			temp->ll=par;
			par->rt=false;
			par->rr=temp;
		}
	}
	return root;
}
struct node *in_succ(struct node *ptr)
{
	if(ptr->rt==true)
	return ptr->rr;
	else{
		ptr=ptr->rr;
		while(ptr->lt==false)
		ptr=ptr->ll;
		return ptr;
	}
}

struct node *in_pred(struct node *ptr)
{
	if(ptr->lt==true)
	return ptr->ll;
	else{
		ptr=ptr->ll;
		while(ptr->rt==false)
		ptr=ptr->rr;
		return ptr;
	}
}
void inorder(struct node *root)
{
	struct node *ptr;
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	ptr=root;
	while(ptr->lt==false)
	{
		ptr=ptr->ll;
	}
	while(ptr!=NULL)
	{
		cout<<ptr->data<<",";
		ptr=in_succ(ptr);
	}
}
void preorder(struct node *root)
{
	struct node *ptr;
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;;
		return;
	}
	ptr=root;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<",";
		if(ptr->lt==false)
		ptr=ptr->ll;
		else if(ptr->rt==false)
		ptr=ptr->rr;
		else{
			while(ptr!=NULL && ptr->rt==true)
			ptr=ptr->rr;
			if(ptr!=NULL)
			ptr=ptr->rr;
		}
	}
}
int main()
{
	while(1)
	{
		fun();
		int tt;
		cin>>tt;
		switch(tt)
		{
			case 1:
				root=insertion(root);
				break;
			case 2:
				inorder(root);
				cout<<endl;
				break;
			case 3:
				preorder(root);
				cout<<endl;
				break;
			default:
				exit(0);
				
		}
	}
}

// 1 20 1 30 1 10 1 5 1 16 1 14 1 17
