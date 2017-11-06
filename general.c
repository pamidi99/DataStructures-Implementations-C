#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lftptr;
struct node *rhtptr;
};
struct stack
{
int top;
int level[50];
struct node *location[50];
}s;
struct node* convert(struct node *root)
{
struct node *newnode;
int nodes,data,level;
printf("enter no.of nodes");
scanf("%d",&nodes);
int i;
for(i=0;i<nodes;i++)
{
printf("enter node and level");
scanf("%d %d",&level,&data);
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->lftptr=newnode->rhtptr=NULL;
if(root==NULL)
{
root=newnode;
s.top=0;
s.level[s.top]=level;
s.location[s.top]=newnode;
}
else
{
int predlvl;
struct node *predloc;
predlvl=s.level[s.top];
predloc=s.location[s.top];
if(level>predlvl)
{
predloc->lftptr=newnode;
s.top=s.top+1;
s.level[s.top]=level;
s.location[s.top]=newnode;
}
else
{
while(predlvl>level)
{
s.top=s.top-1;
predlvl=s.level[s.top];
predloc=s.location[s.top];
}
predloc->rhtptr=newnode;
s.top=s.top+1;
s.level[s.top]=level;
s.location[s.top]=newnode;
}
}
}
return root;
}
void display(struct node *root)
{
if(root!=NULL)
{
printf("%d\t",root->data);
display(root->lftptr);
display(root->rhtptr);
}
}
int main()
{
struct node *root=NULL;
root=convert(root);
display(root);
return 0;
}
