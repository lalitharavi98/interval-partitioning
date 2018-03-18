#include<stdio.h>
struct interval
{
	int start;
	int end;
	int grp;
};
void mergesort(struct interval a[],int low,int high);
void merge(struct interval a[],int low,int mid,int high);
int main()
{
	int n;
	printf("enter the total number of interval:");
	scanf("%d",&n);
	struct interval a[n];
	int i;
	int next[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a[i].start,&a[i].end);
		a[i].grp=0;
		next[i]=-1;
	}
	mergesort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",a[i].start,a[i].end);
		
	}
	printf("%%%%%%%%%%");
	a[0].grp=1;
	int count=1;
	next[0]=a[0].end;
	int k=1,j;
	int c=0;
	for(i=1;i<n;i++)
	{
		 j=0;
		 c=0;
		 while(next[j]!=-1)
		 {
		 	if(a[i].start>next[j])
		 	{
		 		next[j]=a[i].end;
		 		a[i].grp=j+1;
		 		c=1;
		 		break;
		 	}
		 	j++;
		 }
		 if(c==0)
		 {
		 	next[j]=a[i].end;
		 	a[i].grp=j+1;
		 	count++;

		 }
	}
	printf("No of grps==%d\n",count);
	printf("INTERVAL--- GRP\n");
	for(i=0;i<n;i++)
	{
	printf("[%d %d]------ %d\n",a[i].start,a[i].end,a[i].grp);
	}
	return 0;

}
void mergesort(struct interval a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void merge(struct interval a[],int low,int mid,int high)
{
	int n1=mid-low+1;
	int n2=high-mid;
	struct interval a1[n1],a2[n2];
	int i;
	int k=low;
	for(i=0;i<n1;i++)
	{
		a1[i]=a[low+i];
	}
	for(i=0;i<n2;i++)
	{
		a2[i]=a[mid+i+1];
	}
	int j=0;
	i=0;
	while(i<n1 && j<n2)
	{
		if(a1[i].start<a2[j].start)
		{
			a[k].start=a1[i].start;
			a[k].end=a1[i].end;
			i++;
		}
		else
		{
			a[k].start=a2[j].start;
			a[k].end=a2[j].end;
			j++;
		}
		k++;
	}
	if(i<n1)
	{
		a[k].start=a1[i].start;
		a[k].end=a1[i].end;
		i++;
		k++;
	}
	if(j<n2)
	{
		a[k].start=a2[j].start;
		a[k].end=a2[j].end;
		j++;
		k++;
	}
}
