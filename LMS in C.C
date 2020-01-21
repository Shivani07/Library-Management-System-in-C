#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
	int no;
	struct node *next;
	struct node *prev;
}*start=NULL,*first,*last;

int item;

void sort()
{
	while(first!=NULL)
	{
		 if(first->no<first->next->no)
		 first->no=first->next->no;
		 first->next=first->next->next;
	}
}



			/*SINGLE LINKEDLIST*/

void add_end() /*To create a linkedlist*/
{
	struct node *ptr,*temp;
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->no=item;
	temp->next=NULL;
	if(start==NULL)
		start=temp;
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void add_beg()    /*Add node at beginning*/
{
	struct node *temp;
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	temp=malloc(sizeof(struct node));
	temp->no=item;
	temp->next=start;
	start=temp;
}

void addpos()   /*To insert at particular position*/
{
	struct node *temp,*ptr;
	int i,pos;
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	ptr=start;
	for(i=1;i<pos;i++)
	{
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("\nThere are less than %d elements",&pos);
			return;
		}
	}
	temp=malloc(sizeof(struct node));
	temp->next=ptr->next;
	temp->no=item;
	ptr->next=temp;
}

void del()     //to delete an element from the list
{
	struct node *temp,*ptr;
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	if(start->no==item)     //deletion from beginning
	{
		temp=start;
		start=start->next;
		free(temp);
		return;
	}
	ptr=start;
	while(ptr->next->next!=NULL)    //deletion from between
	{
		if(ptr->next->no==item)
		{
			temp=ptr->next;
			ptr->next=temp->next;
			free(temp);
			return;
		}
		ptr=ptr->next;

	if(ptr->next->no==item)   /*deletion from end*/
	{
		temp=ptr->next;
		free(temp);
		ptr->next=NULL;
		return;
	}
	else
	printf("Element %d not found",item);
    }
      getch();
}

void display()     //To display the linkedlist
{
	struct node *ptr,*first;
	clrscr();
	if(start==NULL)
	{
		printf("\nLinkedlist is empty");
		getch();

	}
	ptr=start;
	printf("\tList is:\n");
	while(ptr!=NULL)
	{
		first=start;
		sort();
		printf("\n\t%d",ptr->no);
		ptr=ptr->next;
	}
	getch();
}

void search()   //to search an element from the list
{
	struct node *ptr=start;
	int pos=1;
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	while(ptr!=NULL)
	{
		if(ptr->no==item)
		{
			printf("\n\tItem found\n\tPosition:%d",pos);
			getch();
			return;
		}
		ptr=ptr->next;
		pos++;
	}
	if(ptr==NULL)
	printf("\n\tItem not found in the list");
	getch();
}

		  /*CIRCULAR LINKEDLIST*/

void addatbeg()  //to add element in the beginning
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	temp->no=item;
	if(first==NULL)
	{
		first=temp;
		temp->next=first;
		last=first;
	}
	else
	{
		temp->next=first;
		first=temp;
		last->next=temp;
	}
}

void addatend()  //add element in the end
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element: ");
	scanf("%d",&item);
	temp->no=item;
	temp->next=first;
	last->next=temp;
	last=temp;

}
void addpos_c()   /*To insert at particular position*/
{
	struct node *temp,*ptr;
	int i,pos;
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	ptr=first;
	for(i=1;i<pos;i++)
	{
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("\nThere are less than %d elements",&pos);
			return;
		}
	}
	temp=malloc(sizeof(struct node));
	temp->next=ptr->next;
	temp->no=item;
	ptr->next=temp;
}

void del_c()     //to delete element from circular linkedlist
{
	struct node *temp,*ptr;
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	if(last->next==last && last->no==item)
	{
		temp=last;
		last->next=NULL;
		free(temp);
		getch();
		return;
	}
	ptr=last->next;
	if(ptr->no==item)     //deletion from beginning
	{
		temp=ptr;
		last->next=ptr->next;
		free(temp);
		return;
	}
	ptr=ptr->next;
	while(ptr->next!=last)    //deletion from between
	{
		if(ptr->next->no==item)
		{
			temp=ptr->next;
			ptr->next=temp->next;
			free(temp);
			return;
		}
		ptr=ptr->next;
	}
	if(ptr->next==last && ptr->next->no==item)   /*deletion from end*/
	{
		temp=ptr->next;
		ptr->next=last->next;
		free(temp);
		last=ptr;
		return;
	}
	printf("Element %d not found",item);
}
void search_c()   //to search an element from the list
{
	struct node *ptr=first;
	int pos=1;
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	while(ptr!=NULL)
	{
		if(ptr->no==item)
		{
			printf("\n\tItem found\n\tPosition:%d",pos);
			getch();
			return;
		}
		ptr=ptr->next;
		pos++;
	}
	if(ptr==NULL)
	printf("\n\tItem not found in the list");
	getch();
}


void display_c()     //To display the linkedlist
{
	struct node *ptr;
	clrscr();
	if(first==NULL)
	{
		printf("\nLinkedlist is empty");
		getch();

	}
	else
	{
	ptr=first;
	printf("\tList is:\n");
	while(ptr->next!=first )
	{
		sort();
		printf("\n\t%d",ptr->no);
		ptr=ptr->next;
	}
	printf("\n\t%d",ptr->no);
	}
	getch();
}

			    /*DOUBLY LINKEDLIST*/

void addatbeg_d()  //to add element in the beginning
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	temp->no=item;
	if(first==NULL)       /*creation of list*/
	{
		temp->prev=temp->next=NULL;
		last=first=temp;
	}
	else
	{
		temp->prev=NULL;
		temp->next=first;
		first->prev=temp;
		first=temp;
	}
}

void addatend_d()  //add element in the end
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element: ");
	scanf("%d",&item);
	temp->no=item;
	if(last==NULL)
	{
		temp->prev=temp->next=NULL;
		first=last=temp;
	}
	else
	{
		temp->next=NULL;
		temp->prev=last;
		last->next=temp;
		last=temp;
	}

}


void addpos_d()   /*To insert at particular position*/
{
	struct node *temp,*ptr;
	int i,pos;
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	ptr=first;
	for(i=1;i<pos;i++)
	{
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("\nThere are less than %d elements",&pos);
			return;
		}
	}
	temp=malloc(sizeof(struct node));
	temp->next=ptr->next;
	temp->no=item;
	ptr->next=temp;
}

void del_d()     //to delete element from doubly linkedlist
{
	struct node *temp,*ptr;
	int c;
	clrscr();
	printf("\n1.Delete from beginnig");
	printf("\n2.Delete from end");
	scanf("%d",&c);
	switch(c)
	{
	case 1:
	{
	if(first==NULL)           /* deletion from beginning*/
	{
		printf("\nList is empty");
		getch();
		return;
	}
	else if(first->next==NULL)
	{
		printf("\nThe only node is deleted");
		temp=first;
		first=last=NULL;
	}
	else
	{
		printf("\nNode deleted from beginning");
		temp=first;
		first=first->next;
		first->prev=NULL;
	}
	free(temp);
	}
	break;
	case 2:
	{	      /*deletion from end*/
	if(last==NULL)
	{
		printf("\nList is empty");
		getch();
		return;
	}
	else if(last->prev==NULL)
	{
		printf("\nThe only node is deleted ");
		temp=last;
		first=last=NULL;
	}
	else
	{
		printf("\nNode deleted from last");
		temp=last;
		last=last->prev;
		last->next=NULL;
	}
	free(temp);
	}
    }  //end of switch

} // end of del_d

void display_d()     //To display the linkedlist
{
	struct node *ptr;
	clrscr();
	if(first==NULL)
	{
		printf("\nLinkedlist is empty");
		getch();

	}
	else
	{
	ptr=first;
	printf("\tList is:\n");
	while(ptr->next!=NULL )
	{
		sort();
		printf("\n\t%d",ptr->no);
		ptr=ptr->next;
	}
	printf("\n\t%d",ptr->no);
	}
	getch();
}

			/*CIRCULAR DOUBLY LINKEDLIST*/


void addatbeg_cd()  //to add element in the beginning
{
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	ptr->no=item;
	if(first==NULL)
	{
		first=(struct node*)malloc(sizeof(struct node));
		first->no=item;
		first->prev=first->next=first;
		return;
	}
	else
	{
		temp=first->next;
		first->next=ptr;
		ptr->prev=first;
		ptr->next=temp;
		temp->prev=ptr;
		return;
	}
}

void addatend_cd()  //add element in the end
{
	struct node *temp,*ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element: ");
	scanf("%d",&item);
	ptr->no=item;
	temp=first->prev;
	first->prev=ptr;
	ptr->prev=temp;
	ptr->next=first;
	temp->next=ptr;

}

void addpos_cd()   /*To insert at particular position*/
{
	struct node *temp,*ptr;
	int i,pos;
	clrscr();
	printf("\nEnter the element: ");
	scanf("%d",&item);
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	ptr=first;
	for(i=1;i<pos;i++)
	{
		ptr=ptr->prev;
		if(ptr==NULL)
		{
			printf("\nThere are less than %d elements",&pos);
			return;
		}
	}
	temp=malloc(sizeof(struct node));
	temp->prev=ptr->prev;
	temp->no=item;
	ptr->prev=temp;
}

void del_cd()     //to delete element from doubly linkedlist
{
	struct node *temp,*ptr;
	int c;
	clrscr();
	printf("\n1.Delete from beginnig");
	printf("\n2.Delete from end");
	scanf("\n%d",&c);
	switch(c)
	{
	case 1:
	{
	if(first->next==first)           /* deletion from beginning*/
	{
		printf("\nList is empty");
		getch();
		return;
	}
	else
	{	printf("\nNode deleted from beginning");
		temp=first->next;
		first->next=temp->next;
		temp->next->prev=first->prev;
		first->prev->next=temp->next;
		free(temp);
	}
	}
	break;
	case 2:
	{	      /*deletion from end*/
	if(first->next==first)
	{
		printf("\nList is empty");
		getch();
		return;
	}
	else
	{
		printf("\nNode deleted from last");
		temp=first->prev;
		first->prev=temp->prev;
		temp->prev->next=first->prev;
		first->next->prev=temp->prev;
		free(temp);
	}
	}
    }  //end of switch

} // end of del_d

void display_cd()     //To display the linkedlist
{
	struct node *ptr,*temp;
	temp=first->next;
	clrscr();
	if(first==NULL)
	{
		printf("\nLinkedlist is empty");
		getch();

	}
	else
	{
	printf("\tList is:\n");
	while(temp->next!=first )
	{
		sort();
		printf("\n\t%d",temp->no);
		temp=temp->next;
	}
	printf("\n\t%d",temp->no);
	}
	getch();
}





void main()
{
	int ch;
	clrscr();
	printf("Prateek Srivastava\nBCA - 2\nID: 714001\nData Structure Practical\nProgram for Linked List\n\n");
	printf("\n\t   **************** PROGRAM FOR LINKLIST ****************");
	printf("\n\n\t   ************************ MENU ************************");
	printf("\n\t   ******      1. Press 1 for SIMPLE LINKLIST      ******");
	printf("\n\t   ******     2. Press 2 for CIRCULAR LINKLIST     ******");
	printf("\n\t   ******      3. Press 3 for DOUBLY LINKLIST      ******");
	printf("\n\t   ******  4. Press 4 for CIRCULAR DOUBLY LINKLIST ******");
	printf("\n\t   ******              5. Press 5 to EXIT          ******");
	printf("\n\n\t   ***************  Enter your choice...  ***************\n");
	scanf("\n%d",&ch);
	switch(ch)
	{
		case 1:{        while(1)
				{
				clrscr();
				printf("\n\n\t\t******** SIMPLE LINKLIST ********");
				printf("\n\t\t       1.Press 1 to INSERT");
				printf("\n\t\t       2.Press 2 to DELETE");
				printf("\n\t\t       3.Press 3 to SEARCH");
				printf("\n\t\t       4.Press 4 to DISPLAY");
				printf("\n\t\t       5.Press 5 to EXIT");
				printf("\n\t\t       Enter your choice...\n");
				scanf("\n%d",&ch);
				switch(ch)
				{
					case 1:{
						clrscr();
						printf("\n\n\t\t****************************************\n\n");
						printf("\t\t1.Press 1 to ADD ELEMENT AT BEGINNING\n");
						printf("\t\t2.Press 2 to ADD ELEMENT AT ANY POSITION\n");
						printf("\t\t3.Press 3 to ADD ELEMENT AT THE END\n\n");
						printf("\t\t****************************************\n");
						scanf("%d",&ch);
						switch(ch)
						{
							case 1:add_beg();
							break;
							case 2:addpos();
							break;
							case 3:add_end();
							break;
						}
					     }
					break;
					case 2:del();
					break;
					case 3:search();
					break;
					case 4:display();
					break;
					case 5:exit(1);
					break;

				}
				}
			}
		case 2:{
				while(1)
				{
				clrscr();
				printf("\n\n\t\t******** CIRCULAR LINKLIST ********");
				printf("\n\n\t\t       1.Press 1 to INSERT");
				printf("\n\t\t       2.Press 2 to DELETE");
				printf("\n\t\t       3.Press 3 to SEARCH");
				printf("\n\t\t       4.Press 4 to DISPLAY");
				printf("\n\t\t       5.Press 5 to EXIT\n");
				printf("\t\t       Enter your choice...\n");
				scanf("\n%d",&ch);
				switch(ch)
				{

					case 1:{
						clrscr();
						printf("\n\n\t\t****************************************\n\n");
						printf("\t\t1.Press 1 to ADD ELEMENT AT BEGINNING\n");
						printf("\t\t2.Press 2 to ADD ELEMENT AT ANY POSITION\n");
						printf("\t\t3.Press 3 to ADD ELEMENT AT THE END\n");
						printf("\n\t\t****************************************\n");
						scanf("%d",&ch);
						switch(ch)
						{
							case 1:addatbeg();
							break;
							case 2:addpos_c();
							break;
							case 3:addatend();
							break;
						}
					     }
					break;
					case 2:del_c();
					break;
					case 3:search_c();
					break;
					case 4:display_c();
					break;
					case 5:exit(1);
					break;

				}
				}
			}
		case 3:{
			while(1)
				{
				clrscr();
				printf("\n\n\t\t****** DOUBLY LINKLIST ******\n");
				printf("\n\t\t     1.Press 1 to INSERT");
				printf("\n\t\t     2.Press 2 to DELETE");
				printf("\n\t\t     3.Press 3 to SEARCH");
				printf("\n\t\t     4.Press 4 to DISPLAY");
				printf("\n\t\t     5.Press 5 to EXIT\n");
				printf("\t\t     Enter your choice...\n");
				scanf("\n%d",&ch);
				switch(ch)
				{

					case 1:{
						clrscr();
						printf("\n\n\t\t********************************\n");
						printf("\n\t\t1.Press 1 to ADD AT BEGINNING\n");
						printf("\t\t2.Press 2 to ADD AT ANY POSITION\n");
						printf("\t\t3.Press 3 to ADD AT THE END\n");
						printf("\n\t\t********************************\n");
						scanf("%d",&ch);
						switch(ch)
						{
							case 1:addatbeg_d();
							break;
							case 2:addpos_d();
							break;
							case 3:addatend_d();
							break;
						}
					     }
					break;
					case 2:del_d();
					break;
					case 3:search_c();
					break;
					case 4:display_d();
					break;
					case 5:exit(1);
					break;

				}
				}

			}
		case 4:{
			while(1)
				{
				clrscr();
				printf("\n\n\t\t******** CIRCULAR DOUBLY LINK LIST ********\n");
				printf("\n\t\t\t    1.Press 1 to INSERT");
				printf("\n\t\t\t    2.Press 2 to DELETE");
				printf("\n\t\t\t    3.Press 3 to SEARCH");
				printf("\n\t\t\t    4.Press 4 to DISPLAY");
				printf("\n\t\t\t    5.Press 5 to EXIT\n");
				scanf("\n%d",&ch);
				switch(ch)
				{

					case 1:{
						clrscr();
						printf("\n\n\t\t*********************************\n\n");
						printf("\t\t1.Press 1 to ADD AT BEGINNING\n");
						printf("\t\t2.Press 2 to ADD AT ANY POSITION\n");
						printf("\t\t3.Press 3 to ADD AT THE END\n");
						printf("\n\t\t*********************************\n");
						scanf("%d",&ch);
						switch(ch)
						{
							case 1:addatbeg_cd();
							break;
							case 2:addpos_cd();
							break;
							case 3:addatend_cd();
							break;
						}
					     }
					break;
					case 2:del_cd();
					break;
					case 3:search_c();
					break;
					case 4:display_cd();
					break;
					case 5:exit(1);
					break;

				}
				}

			 }
		case 5:exit(1);
	}
}

