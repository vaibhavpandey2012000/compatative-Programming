#include<bits/stdc++.h>
using namespace std;
struct node{
	int d,p;
	struct node *next;
};
struct node *start1,*last1 ,*start2,*last2,*astart,*alast;
void fun()
{
	cout<<"1.insert 1st polynomial"<<endl;
	cout<<"2.insert 2nd polynomial"<<endl;
	cout<<"3.addision of polynomal"<<endl;
	cout<<"4.multiplaction of polynomial"<<endl;
	cout<<"5.clear 1st polynomal"<<endl;
	cout<<"6.clear 2nd polynomal"<<endl;
	cout<<"9.result clear"<<endl;
	cout<<"7.resultant polynomial"<<endl;
	cout<<"8.exit"<<endl;
}
void insert1()
{
	int ap;
	cin>>ap;
	for(int i=0;i<ap;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node ));
		cout<<"Enter the data and power of x "<<endl;
		cin>>temp->d>>temp->p;
		temp->next=NULL;
		if(start1==NULL)
		{
			start1=last1=temp;
		}
		else
		{
			last1->next=temp;
			last1=temp;
		}
	}
}
void insert2()
{
	int ap;
	cin>>ap;
	for(int i=0;i<ap;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node ));
		cout<<"Enter the data and power of x "<<endl;
		cin>>temp->d>>temp->p;
		temp->next=NULL;
		if(start2==NULL)
		{
			start2=last2=temp;
		}
		else
		{
			last2->next=temp;
			last2=temp;
		}
	}
}
void sorting(int a)
{
	struct node *ptr,*cpt;
	if(a==3)
	ptr=astart;
	if(a==1)
	ptr=start1;
	if(a==2)
	ptr=start2;
	while(ptr->next!=NULL)
	{
		cpt=ptr->next;
		while(cpt!=NULL)
		{
			if(ptr->p<cpt->p)
			{
				swap(ptr->d,cpt->d);
				swap(ptr->p,cpt->p);
			}
			cpt=cpt->next;
		}
		ptr=ptr->next;
	}
}
void result()
{
	//sorting(3);
	int n=0;
	struct node *pp=astart;
	while(pp!=NULL)
	{
		if(pp->d>=0){
			if(n!=0)
			cout<<"+"<<pp->d<<"X^"<<pp->p;
			else
			cout<<pp->d<<"X^"<<pp->p;
		}
		else
		{
			cout<<pp->d<<"X^"<<pp->p;
		}
		n++;	
		pp=pp->next;
	}
	cout<<endl;
}
void addision()
{
	sorting(1);
	sorting(2);
	struct node *p1=start1,*p2=start2,*res=astart,*last;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->p>p2->p)
		{
			struct node *temp=(struct node *)malloc(sizeof(struct node));
			temp->d=p1->d;
			temp->p=p1->p;
			temp->next=NULL;
			if(astart==NULL)
			{
				astart=last=temp;
			}
			else
			{
				last->next=temp;
				last=temp;
			}
			p1=p1->next;
		//	cout<<temp->d<<" "<<temp->p<<"|";
		}
		else if(p1->p<p2->p)
		{
			struct node *temp=(struct node *)malloc(sizeof(struct node));
			temp->d=p2->d;
			temp->p=p2->p;
			temp->next=NULL;
			if(astart==NULL)
			{
				astart=last=temp;
			}
			else
			{
				last->next=temp;
				last=temp;
			}
			p2=p2->next;
		//	cout<<temp->d<<" "<<temp->p<<"|";
		}
		else if(p1->p==p2->p)
		{
			struct node *temp=(struct node *)malloc(sizeof(struct node));
			temp->d=(p2->d+p1->d);
			temp->p=p2->p;
			temp->next=NULL;
			if(astart==NULL)
			{
				astart=last=temp;
			}
			else
			{
				last->next=temp;
				last=temp;
			}
			p2=p2->next;
			p1=p1->next;
		//	cout<<temp->d<<" "<<temp->p<<"|";
		}
	}
	while(p1!=NULL)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->d=p1->d;
		temp->p=p1->p;
		temp->next=NULL;
		if(astart==NULL)
		{
			astart=last=temp;
		}
		else
		{
			last->next=temp;
			last=temp;
		}
		p1=p1->next;
	//	cout<<temp->d<<" "<<temp->p<<"|";
	}
	while(p2!=NULL)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->d=p2->d;
		temp->p=p2->p;
		temp->next=NULL;
		if(astart==NULL)
		{
			astart=last=temp;
		}
		else
		{
			last->next=temp;
			last=temp;
		}
		p2=p2->next;
	//	cout<<temp->d<<" "<<temp->p<<"|";
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
				insert1();
				break;
			case 2:
				insert2();
				break;
			case 3:
				addision();
				break;
			case 5:
				start1=last1=NULL;
				break;
			case 6:
				start2=last2=NULL;
				break;
			case 7:
				result();
				break;
			case 9:
				astart=alast=NULL;
				break;
			
				
		}
		
	}
}
