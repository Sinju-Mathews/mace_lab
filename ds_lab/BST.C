#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
 {
  int info;
  struct node *left,*right;
 };
 typedef struct node NODE;
NODE *p,*q,*root,*newnode,*temp;

void creation()
{
int num;
printf("\nenter the root :");
scanf("%d",&num);
newnode=(NODE *) malloc(sizeof(NODE));
newnode->info=num;
newnode->left=NULL;
newnode->right=NULL;
if(root==NULL)
root=newnode;
}

void insertion(NODE *temp)
{
if (newnode->info<temp->info)
    {
	if(temp->left!=NULL)
		 insertion(temp->left);
	else
	{
		temp->left=newnode;
		printf("Inserted Element: %d ",newnode->info);
	}
   }
else
   {
	if(temp->right!=NULL)
		insertion(temp->right);
	else
	{
		temp->right=newnode;
		printf("Inserted Element: %d ",newnode->info);
	}
   }
}
void deletion()
{
	int n,item;
	printf("enter the element to be deleted: ");
	scanf("%d",&n);
	if(root==NULL)
		printf("the tree is empty\n");

	else
	{
	p=q=root;
	while(n!=q->info&&q!=NULL)
	{
		p=q;
		if(n<p->info)
			q=p->left;
		else
			q=p->right;
	}
	if(q==NULL)
		printf("element not found");

	 else if(q->right==NULL&&q->left==NULL)
	{
		if(q==root)
			root=NULL;
		else if(p->right==q)
			p->right=NULL;
		else
			p->left=NULL;
		item=q->info;
		free(q);
		printf("element deleted: %d",item);
	}
	else if(q->right!=NULL&&q->left==NULL)
	{
		if(q==root)
		  root=root->right;
		else if(p->right==q)
		{
			p->right=q->right;
			q->right=NULL;
		 }
		 else
		 {
		   p->left=q->right;
		   q->right=NULL;
		 }
		 item=q->info;
		free(q);
		printf("element deleted: %d",item);
	}
	else if(q->right==NULL&&q->left!=NULL)
	{


		if(q==root)
		  root=root->left;

		else if(p->right==q)
		{
			p->right=q->left;
			q->left=NULL;
		 }
		 else
		 {
		   p->left=q->left;
		   q->left=NULL;
		 }
		item=q->info;
		free(q);
		printf("element deleted: %d",item);
	}
	else if(q->right!=NULL&&q->left!=NULL)
	{
	temp=p=q;
	q=q->left;
	if(q->right==NULL)
	{
		temp->info=q->info;
		p->left=q->left;
	}
	else
	{
		while(q->right!=NULL)
		{
			p=q;
			q=q->right;
		}
		temp->info=q->info;
		p->right=NULL;
	}

	item=q->info;
	free(q);
	printf("element deleted: %d",item);
	}
	}
}

void inorder(NODE *t)
{
if(t!=NULL)
{
inorder(t->left);
printf("%d\t",t->info);
inorder(t->right);
}
}


void preorder(NODE *t)
{
if(t!=NULL)
{
printf("%d\t",t->info);
preorder(t->left);
preorder(t->right);
}
}

void postorder(NODE *t)
{
if(t!=NULL)
{
postorder(t->left);
postorder(t->right);
printf("%d\t",t->info);
}
}

void find(NODE *t,int n)
{
if(t!=NULL)
{
if(t->info==n)
printf("element found");
else if(n<t->info)
	find(t->left,n);
else
	find(t->right,n);
}
else
printf("element not found");
}

int main()
{
int num,c,ct,i,n;
clrscr();
root=NULL;
printf("CREATION");
creation();
printf("1. INSERTION\n2. DELETION\n3. DISPLAY\n4. FIND\n5. EXIT\n");
do
{
printf("\nEnter Your Choice :");
scanf("%d",&c);
switch(c)
{
case 1:
	if(root==NULL)
	creation();
	else{
	printf("\nenter the element :");
	scanf("%d",&num);
	newnode=(NODE *) malloc(sizeof(NODE));
	newnode->info=num;
	newnode->left=NULL;
	newnode->right=NULL;
	temp=root;
	insertion(temp);
	}
	break;
case 2:
	deletion();
	break;
case 3: if(root==NULL)
		printf("TREE is EMPTY");
	else{
	printf("\n1.INORDER\t2. PREORDER\t3. POSTORDER");
	printf("\nenter choice : ");
	scanf("%d",&ct);
	switch(ct)
	{
	case 1:inorder(root);
		break;
	case 2:preorder(root);
		break;
	case 3:postorder(root);
		break;
	default: printf("wrong input");
	}
	}
	break;
case 4: if(root==NULL)
		printf("TREE is EMPTY");
	else{
	printf("enter the element to search:");
	scanf("%d",&n);
	find(root,n);
	}
	break;
case 5: printf("---EXIT---");
	break;
default:printf("wrong input");
}
}while(c!=5);
getch();
return 0;
}