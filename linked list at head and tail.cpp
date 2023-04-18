#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;	
};
typedef struct Node NODE;
NODE *head=NULL,*tail=NULL,*temp,*NN,*res;
void display()
{
	if(head==NULL && tail==NULL)
	{
		printf("No Nodes\n");
	}
	else
	{
		temp=head;
		while(temp)
		{
			printf("%d %d %d \n",temp,temp->data,temp->next);
			temp=temp->next;
		}
		printf("\n");
	}	
}
void insert(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
	}
	else
	{
		tail->next=NN;
		tail=NN;
	}
}
 NODE *dele()
 {
 	if(head==NULL && tail==NULL)
 	{
 		return NULL;
	}
	else if(head==tail)
	{
		res=head;
		head=NULL;
		tail=NULL;
		return res;
	}
	else
	{
		temp=head;
		while(temp->next->next)
		{
			temp=temp->next;
		}
		res=tail;
		temp->next=NULL;
		tail=temp;
		return res;
	}
 }
 void insert_head(NODE *NN)
 {
 	if(head==NULL && tail==NULL)
 	{
 		head=NN;
 		tail==NN;
	 }
	 else
	 {
	 	NN->next=head;
	 	head=NN;
	 }
 }
 NODE * dele_head()
 {
 	if(head==NULL && tail==NULL)
 	{
 		return NULL;
	 }
	 else if(tail==head)
	 {
	 	res=head;
	 	head=NULL;
	 	tail=NULL;
	 	return res;
	 }
	 else
	 {
	 	res=head;
	 	head=head->next;
	 	res->next=NULL;
	 	return res;
	 }
 }
 void reverse()
 {
 	NODE *cur,*prev,*next;
 	if(head==NULL && tail==NULL)
 	{
 		printf("NO Nodes\n");		
	}
	else if(head==tail)
	{
		printf("No need or list contains single element");
	}
	else
	{
		tail=head;
		cur=head;
		prev=NULL;
		next=NULL;
		while(cur)
		{
			next=cur->next;
			cur->next=prev;
			prev=cur;
			cur=next;
		}
		head=prev;
	}
 }
 void insert_by_pos(NODE *NN,int pos)
 {
 	int p,flag=0;
 	if(head==NULL && tail==NULL)
 	{
	     head=NN;
	     tail=NN;
	}
	else 
	{
	    temp=head;
	    
		for(p=1;p<pos-1;p++)
		{
			if(temp==NULL)
			{
				printf("Insertion is not possible\n");
				flag=1;
				break;
			}
			temp=temp->next;
		}
		if(flag==0)
		{
			NN->next=temp->next;
		    temp->next=NN;
		}
	}
 }
NODE *dele_by_pos(int pos)
{
	int p;
	if(head==NULL && tail==NULL)
	{
		return NULL;
	}
	temp=head;
	for(p=1;p<pos-1;p++)
	{
		if(temp==NULL)
		{
			return NULL;
		}
		temp=temp->next;
	}
	res=temp->next;
	temp->next=temp->next->next;
	res->next=NULL;
	return res;
}
int main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1.insert\n 2.delete\n 3.display\n 4.insert at head\n 5.delete at head\n 6.reverse\n 7.insert by position\n 8.delete at position\n 9.exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			//insert
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert(NN);			
		}
		else if(ch==2)
		{
		    //delete	
		    res=dele();
		    if(res==NULL)
		    {
		    	printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else if(ch==3)
		{
			//display
			display();
		}
		else if(ch==4)
		{
			//insert at head
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;	
			insert_head(NN);	
		}
		else if(ch==5)
		{
			//delete at head
			res=dele_head();
			if(res==NULL)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}	
		}
		else if(ch==6)
		{
			reverse();
		}
		else if(ch==7)
		{
			scanf("%d",&val);            //insert by position
			scanf("%d",&pos);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert_by_pos(NN,pos);
		}
		else if(ch==8)
		{
			scanf("%d",&pos);
			res=dele_by_pos(pos);
			if(res==NULL)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}	
			                        //delete by position
		}
		else
		{
			break;
		}
	}
}
