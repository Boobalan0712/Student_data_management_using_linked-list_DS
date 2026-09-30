#include "student.h"
void stud_del(SLL **ptr)
{
        if(*ptr==0)
        {
                printf("\033[31;3mNo records found...\n\033[0m");
                return ;
        }
        char op;
        SLL *del=*ptr,*prev;
        printf("R/r : Enter roll number to delete\nN/n : Enter name to delete\n\nEnter your choice: ");
        scanf(" %c",&op);
        switch(op)
        {
                case 'r':
                case 'R':
l:
                        {
                                int roll=0;
                                printf("\nEnter rollno to delete...\n");
                                scanf("%d",&roll);
                                while(del)
                                {
                                        if(roll==del->rollno)
                                        {
                                                if(*ptr==del)
                                                        *ptr=del->next;
                                                else
                                                        prev->next=del->next;
                                                free(del);
                                                printf("\nRecord Deleted Successfully...\n");
                                                return ;
                                        }
                                        prev=del;
                                        del=del->next;
                                }
                                printf("\nRollno Not found..\n");
                        }
                        break;

                case 'n':
                case 'N':
                        {
                                SLL *after;
                                char name[20];
                                int co=0;
                                printf("Enter name to delete : ");
                                scanf("%s",name);
                                while(del)
                                {
                                        if(strcmp(name,del->name)==0)
                                        {
                                                after=del->next;
                                                while(after)
                                                {
                                                        if(strcmp(del->name,after->name)==0)
                                                        {
                                                                co++;
                                                                if(co==1)
                                                                {
                                                                        printf("\nName Present More Than One Time..\n\n");
                                                                        printf("%d %s %f\n",del->rollno,del->name,del->percentage);
                                                                }
                                                                printf("%d %s %f\n",after->rollno,after->name,after->percentage);
                                                        }
                                                        after=after->next;
                                                }
                                                if(co>0)
                                                        goto l;
                                                if(*ptr==del)
                                                        *ptr=del->next;
                                                else
                                                        prev->next=del->next;
                                                free(del);
                                                printf("\nRecord Deleted Successfully...\n");
                                                return ;
                                        }
                                        prev=del;
                                        del=del->next;
                                        after=del->next;
                                }
                                printf("\nName Not Found..\n");
                        }
                        break;
        }
}

//*************************** DELETE ALL RECORDS *****************************

void del_all(SLL **ptr)
{
        if(*ptr==0)
        {
                printf("\nNo Records Found..\n");
                return ;
        }
        SLL *del=*ptr;
        while(del)
        {
                *ptr=del->next;
                free(del);
                del=*ptr;
        }
        printf("All Records Deleted Successfully...\n");
}
