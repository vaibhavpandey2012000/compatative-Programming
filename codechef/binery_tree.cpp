#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
void fun()
{
	cout<<"1.insert"<<endl;
	cout<<"2.deletion"<<endl;
	cout<<"3.search"<<endl;
	cout<<"4.max_element"<<endl;
	cout<<"5.min_element"<<endl;
	cout<<"6.printing"<<endl;
	cout<<"11.exit"<<endl;
}

void insertion()
{
	cout<<"Enter the data insert into Binery Tree:";
	int val;
	cin>>val;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	struct node *par=NULL,*pp=root;
	while(pp!=NULL)
	{
		par=pp;
		if(pp->data>val)
			pp=pp->left;
		else if(pp->data<val)
			pp=pp->right;
		else{
			cout<<"deplicate present not inserted"<<endl;
			return;
		}
	}
	if(par==NULL)
	{
		root=temp;
	}
	else if(par->data>val)
	{
		par->left=temp;
	}
	else
	{
		par->right=temp;
	}	
}


void print( struct node *pp)
{
	if(pp==NULL)
	return;
	cout<<pp->data<<" ";
	print(pp->left);
	print(pp->right);
}

struct node * min_element(struct node *root)
{
	struct node *pp=root;
	if(pp==NULL)
	{
		cout<<"Binery Tree is empty"<<endl;
		return NULL;
	}
	while(pp->left!=NULL)
	{
		pp=pp->left;
	}
	return pp;
}

struct node * deleteion(struct node *p,int val)
{
	if(p==NULL) return p;
	else if(p->data>val) p->left=deleteion(p->left,val);
	else if(p->data<val) p->right=deleteion(p->right,val);
	else{
		if(p->left==NULL && p->right==NULL)
		{
			delete p;
			p=NULL;
		}
		else if(root->right==NULL)
		{
			struct node *temp=p;
			p=p->right;
			delete(temp);
		}
		else if(root->left==NULL)
		{
			struct node *temp=p;
			p=p->left;
			delete(temp);
		}
		else{
			struct node *temp=min_element(p->right);
			p->data=temp->data;
			p->right=deleteion(p->right,temp->data);
		}
	}
	return p;
}

void searching()
{
	cout<<"Enter the data to be search:";
	int val;
	cin>>val;
	struct node *pp=root;
	while(1)
	{
		if(pp==NULL)
		{
			cout<<"Data Not present"<<endl;
			return;
		}
		if(pp->data==val)
		{
			cout<<val<<" present!"<<endl;
			break;
		}
		else if(pp->data>val)
		{
			pp=pp->left;
		}
		else{
			pp=pp->right;
		}
	}
}

void max_element()
{
	struct node *pp=root;
	if(pp==NULL)
	{
		cout<<"Binery Tree is empty"<<endl;
		return;
	}
	while(pp->right!=NULL)
	{
		pp=pp->right;
	}
	cout<<pp->data<<endl;
}


int main()
{
	while(1)
	{
		fun();
		int tt,val;
		cin>>tt;
		struct node * pp;
		switch(tt)
		{
			case 1:
				insertion();
				break;
			case 2:
				cin>>val;
				deleteion(root,val);
				break;
			case 3:
				searching();
				break;
			case 4:
				max_element();
				break;
			case 5:
				pp=min_element(root);
				if(pp!=NULL)
				cout<<pp->data;
				break;
			case 6:
				print(root);
				cout<<endl;
				break;
			case 11:
				exit(0);
		}
		
	}
}
//1 50 1 30 1 60 1 38 1 35 1 55 1 22 1 59 1 94 1 13 1 98
