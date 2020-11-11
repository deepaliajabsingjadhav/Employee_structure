
//create employee structure using singly linkedlist

//--------------------------------------------------------------------------------------------------------------------------------

//Auther name :  Deepali Ajabsing Jadhav
//
//Description : implimentation of small employee structure using singly linkedlist in c
//
//Date        :  10 NOV 2020
//
//------------------------------------------------------------------------------------------------------------------------------



#include<stdio.h>

#include<stdlib.h>

#include<string.h>

struct employee
{
	int Eno;

	char Ename[30];

	char Ecity[30];

	int Eage;

	struct employee *next;


};

typedef struct employee NODE;

typedef struct employee * PNODE;

typedef struct employee ** PPNODE;

int Count(PNODE Head)
{
	int iCnt=0;

	PNODE temp=Head;

    	while(temp != NULL)
    	{
        	iCnt++;   
	   
		temp = temp->next;
    	}

	return iCnt;
}


void Create(PPNODE Head,int id,char name[],char city[],int age)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    PNODE temp=(*Head);
    
    newn->Eno=id;

    strcpy(newn->Ename,name);

    strcpy(newn->Ecity,city);

    newn->Eage=age;

    newn->next=NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
	    while(temp->next!=NULL)
	    {
	    	temp=temp->next;
	    }

	    temp->next=newn;

	    temp=temp->next;
    }
}

void InsertFirst(PPNODE Head,int id,char name[],char city[],int age)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    PNODE temp=(*Head);

    newn->Eno=id;

    strcpy(newn->Ename,name);

    strcpy(newn->Ecity,city);

    newn->Eage=age;

    newn->next=NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
           newn->next=(*Head);

	   *Head=newn;
    }
}

void InsertLast(PPNODE Head,int id,char name[],char city[],int age)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    PNODE temp=(*Head);

    newn->Eno=id;

    strcpy(newn->Ename,name);

    strcpy(newn->Ecity,city);

    newn->Eage=age;

    newn->next=NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

            temp->next=newn;

            temp=temp->next;
    }
}


void InsertMiddle(PPNODE Head, int id,char name[],char city[],int age, int pos)
{
	    int size = 0, i = 0;

	    PNODE temp = *Head;

	    PNODE newn = NULL;

	    size = Count(*Head);

	    if((pos < 1) || (pos > (size + 1)))
	    {
	        return;
	    }
	
	    else if(pos == 1)
	
	    {
	        InsertFirst(Head, id,name,city,age);
	    }
	
	    else if(pos == size + 1)

	    {
        
		    InsertLast(Head, id,name,city,age);
    
	    }

	    else

	    {

	 	    newn= (PNODE)malloc(sizeof(NODE));


	 	    newn->Eno=id;


	 	    strcpy(newn->Ename,name);


	 	    strcpy(newn->Ecity,city);

		    newn->Eage=age;


	 	    newn->next=NULL;



	    	    for(i = 1; i< pos-1; i++)

	    	    {
            
			    temp = temp->next;
        
		    }

         
		    newn->next = temp->next;

  
	   	    temp->next = newn;
    
	    }
}

void DeleteFirst(PPNODE Head)
{
	PNODE temp=(*Head);

	(*Head)=(*Head)->next;

	free(temp);

	temp->next=NULL;

	printf("\n");

}

void DeleteLast(PPNODE Head)
{
	PNODE temp=(*Head);

	while(temp->next->next != NULL)
	{
		temp=temp->next;
	}

	free(temp->next);

	temp->next=NULL;

        printf("\n");

}

void DeleteMiddle(PPNODE Head, int pos)

{

	int size = 0,i = 0;

    	size = Count(*Head);

	PNODE temp1, temp2;

	    if((pos < 1) || (pos > size))
	    {
	        return;
	    }

	    if(pos == 1)

	    {
        
		    DeleteFirst(Head);
    
	    }

	    else if(pos == size)

	    {

	    	    DeleteLast(Head);

	    }

	    else

	    {

	    	    temp1 = *Head;


	    	    for(i = 1; i< pos-1; i++)

	    	    {

			    temp1 = temp1->next;

	    	    }

	    	    temp2 = temp1->next;


	    	    temp1->next = temp2->next;


	    	    free(temp2);
	
		    printf("\n");



	    }
}


void Display(PNODE Head)
{

    	while(Head != NULL)
    
	{
	
		printf("\n");

		printf("Emplyee id : %d\t Name : %s\tcity  : %s\tage  :%d\n",Head->Eno, Head->Ename, Head->Ecity, Head->Eage);

		Head = Head->next;
    }

   	
}


//search the employee according to theire id  and if you found the doubly entry of same id then display the appropritae msg

void Search(PNODE Head,int id)
{
	PNODE temp=Head;

	int icnt=0;

	printf("\nemployee information according to theire id:\n");

	while(temp != NULL)
	{
		if(temp->Eno == id)
		{
			
			 printf("Emplyee id : %d\t Name : %s\tcity  : %s\tage  :%d\n",temp->Eno, temp->Ename, temp->Ecity, temp->Eage);

			 printf("\n");

			  icnt++;
		}

		temp=temp->next;
	}

	printf("\n");
	
	if(icnt > 1)
	{
		printf("duplicate id's employee is found in your compnay\n");
	
	}

	if(icnt == 0)
	{
		printf("no employee is found of this ID\n");
	}

}



int main()
{
	int i=0;

	int n=0;

	int ch=0;

	int pos=0;

	PNODE First = NULL;

	int id=0;

	char name[50];

	char city[50];

	int age=0;

	int res=0;

	printf("enter how many employee record do you want\n");

	scanf("%d",&n);

	do
	{
		printf("\n");

		printf("0:create employee list\n");

		printf("1:insert first\n");

		printf("2:insert middle\n");

		printf("3:insert last\n");

		printf("4:delete first\n");

		printf("5:delete middle\n");

		printf("6:delete last\n");

		printf("7:Display\n");

		printf("8:count\n");

		printf("9:Search\n");


		printf("20:exit\n");

		printf("\n");

		printf("enter your choice\n");

		scanf("%d",&ch);

		printf("\n");


		switch(ch)
		{
			case 0:

				for(i=0;i<n;i++)
				{
				printf("enter employee id\n");

				scanf("%d",&id);

				printf("enter employee name\n");

				scanf(" %[^'\n']s",name);

				printf("enter employee city\n");

				scanf(" %[^'\n']s",city);

				printf("enter employee age\n");

				scanf("%d",&age);

				Create(&First,id,name,city,age);
				}

				break;

			case 1:
				printf("\nenter data to insert at first position\n");
				
				printf("enter employee id\n");

                                scanf("%d",&id);

                                printf("enter employee name\n");

                                scanf(" %[^'\n']s",name);

                                printf("enter employee city\n");

                                scanf(" %[^'\n']s",city);

				printf("enter employee age\n");

                                scanf("%d",&age);

				InsertFirst(&First,id,name,city,age);

				break;

			case 2:
				printf("\nenter data to insert at middle  position\n");

                                printf("enter employee id\n");

                                scanf("%d",&id);

                                printf("enter employee name\n");

                                scanf(" %[^'\n']s",name);

                                printf("enter employee city\n");

                                scanf(" %[^'\n']s",city);

				printf("enter employee age\n");

                                scanf("%d",&age);

				printf("\nenter position to insert the record\n");

				scanf("%d",&pos);

                                InsertMiddle(&First,id,name,city,age,pos);

                                break;


			case 3:
				printf("\nenter data to insert at last\n");

			       	printf("enter employee id\n");

                                scanf("%d",&id);

                                printf("enter employee name\n");

                                scanf(" %[^'\n']s",name);

                                printf("enter employee city\n");

                                scanf(" %[^'\n']s",city);

				printf("enter employee age\n");

                                scanf("%d",&age);

                                InsertLast(&First,id,name,city,age);

                                break;

			case 4:
				printf("First record delete succefully\n");

				DeleteFirst(&First);

				break;

			case 5:
				printf("enter position to delete record\n");

				scanf("%d",&pos);

				printf("record successfully deleted\n");

				DeleteMiddle(&First,pos);

				break;

			case 6:
				printf("Last record deleted successfully\n");

				DeleteLast(&First);

				break;

			case 7: 
				printf("----------------------------------------------------------------------------------\n");
				
				Display(First);
				
				printf("-----------------------------------------------------------------------------------\n");

				break;

			case 8:

				printf("total number of employee\n");

				res=Count(First);

				printf("%d\n",res);

				break;

			case 9:
				printf("enter employee id for search\n");

				scanf("%d",&id);

				Search(First,id);

				break;

			case 20:
				printf("Thank you for using this application\n");

				exit(0);
		}

	}while(ch != 10);

    return 0;
}

