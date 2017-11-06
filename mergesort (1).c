#include<stdio.h>
#include<stdlib.h>
int* mergesort(int *full,int size)
{
	if(size==1){
		  int *out=(int*)malloc(sizeof(int));
		  *out=*full;
		  return out;
}
if(size>1)	{
int leftpart=size/2,i,k=0;
int rightpart=size-(size/2);
int *leftptr=mergesort(full,leftpart);
int *rightptr=mergesort(full+leftpart,rightpart);
int *output=(int*)malloc(size*sizeof(int));
int left_cur_index=0;
int right_cur_index=0;
int leftlast=leftpart-1;
int rightlast=rightpart-1;
for(i=0;i<size;i++)
{
if(left_cur_index<=leftlast && right_cur_index<=rightlast)
{
if(leftptr[left_cur_index]<=rightptr[right_cur_index])
{
output[k++]=leftptr[left_cur_index];
left_cur_index++;
}
else
{
output[k++]=rightptr[right_cur_index];
right_cur_index++;
}
}
else
break;
}
if(left_cur_index<=leftlast)
{
while(left_cur_index<=leftlast)
{
output[k++]=leftptr[left_cur_index];
left_cur_index++;
}
}
else if(right_cur_index<=rightlast)
{
while(right_cur_index<=rightlast)
{
output[k++]=rightptr[right_cur_index];
right_cur_index++;
}
}
return output;
}
else return full;

}
void main()
{
int *a,*b,size,i;
printf("enter size");
scanf("%d",&size);
a=(int*)malloc(size*sizeof(int));
for(i=0;i<size;i++)
scanf("%d",&a[i]);
b=mergesort(a,size);
for(i=0;i<size;i++)
printf("%d\t",b[i]);
}


