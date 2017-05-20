#include<stdio.h>
#include<conio.h>
typedef struct node
{
	int data,height;
	struct node *left,*right;
}node;
node *insert(node *,int);
node *delete(node *,int);
node *leftrotate(node *);
node *rightrotate(node *);
node *ll(node *);
node *rr(node *);
node *lr(node *);
node *rl(node *);
int ht(node *);
int bf(node *);
void inorder(node *);
void preorder(node *);
int main()
{
	int ch,n,x,i;
	node *root=NULL;
	clrscr();
	while(1)
	{
		printf("\nchoice:\n1.create 2.insert 3.delete 4.display 5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter no.of nodes:");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				printf("enter data:");
				scanf("%d",&x);
				root=insert(root,x);
			}
			break;
			case 2:printf("enter data:");
					scanf("%d",&x);
					root=insert(root,x);
					break;
			case 3: printf("enter data:");
					scanf("%d",&x);
					root=delete(root,x);
					break;
			case 4: printf("preorder:\n");
					preorder(root);
					break;
			case 5: exit(0);
					break;
		}
	}
	getch();
	return 0;
}
node *insert(node *temp,int x)
{
	if(temp==NULL)
	{
		temp=(node *)malloc(sizeof(node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
	}
	else if(x<temp->data)
	{
		temp->left=insert(temp->left,x);
		if(bf(temp)==2)
		{
			if(x<temp->left->data)
				temp=ll(temp);
			else
				temp=lr(temp);
		}
	}
	else if(x>temp->data)
	{
		temp->right=insert(temp->right,x);
		if(bf(temp)==-2)
		{
			if(x>temp->right->data)
				temp=rr(temp);
			else
				temp=rl(temp);
		}
	}
	temp->height=ht(temp);
	return temp;
}
node *delete(node *temp,int x)
{
	node *p;
	if(temp==NULL)
		return NULL;
	else
		if(x>temp->data)
		{
			temp->right=delete(temp->right,x);
			if(bf(temp)==2)
				if(bf(temp->left)>=0)
					temp=ll(temp);
				else
					temp=lr(temp);
		}
		else
			if(x<temp->data)
			{
				temp->left=delete(temp->left,x);
				if(bf(temp)==-2)
					if(bf(temp->right)<=0)
						temp=rr(temp);
					else
						temp=rl(temp);
			}
			else { if(temp->right!=NULL)
			{
				p=temp->right;
				while(p->left!=NULL)
					p=p->left;
				temp->data=p->data;
				temp->right=delete(temp->right,p->data);
				if(bf(temp->left)>=0)
					temp=ll(temp);
				else
					temp=lr(temp);
			}
			else
				return(temp->left);
			}
	temp->height=ht(temp);
	return temp;
}
int ht(node *temp)
{
	int lh,rh;
	if(temp==NULL)
		return 0;
	if(temp->left==NULL)
		lh=0;
	else
		lh=1+temp->left->height;
	if(temp->right==NULL)
		rh=0;
	else
		rh=1+temp->right->height;
	if(lh>rh)
		return lh;
	else
		return rh;
}
int bf(node *temp)
{
	int lh,rh;
	if(temp==NULL)
		return 0;
	if(temp->left==NULL)
		lh=0;
	else
		lh=1+temp->left->height;
	if(temp->right==NULL)
		rh=0;
	else
		rh=1+temp->right->height;
	return(lh-rh);
}
node *rightrotate(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->height=ht(x);
	y->height=ht(y);
	return y;
}
node *leftrotate(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->height=ht(x);
	y->height=ht(y);
	return y;
}
node *ll(node *temp)
{
	temp=rightrotate(temp);
	return temp;
}
node *lr(node *temp)
{
	temp->left=leftrotate(temp->left);
	temp=rightrotate(temp);
	return temp;
}
node *rl(node *temp)
{
	temp->right=rightrotate(temp->right);
	temp=leftrotate(temp);
	return temp;
}
node *rr(node *temp)
{
	temp=leftrotate(temp);
	return temp;
}
void preorder(node *temp)
{
	if(temp!=NULL)
	{
		printf("%d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
