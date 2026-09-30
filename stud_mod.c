#include "student.h"
void stud_mod(SLL *ptr)
{
        if(ptr==0)
        {
                printf("No Records Found...\n");
                return ;
        }
        char op;
        printf("Enter which record to search for modification\n\nR/r : Search by roll number\nN/n : Search by name\nP/p : Search by percentage\n\nEnter Your Choice : ");
        scanf(" %c",&op);
        switch(op)
        {
                case 'r':
                case 'R':
n:
                        {
                                int roll;
                                printf("\nEnter Rollno : ");
                                scanf("%d",&roll);
                                while(ptr)
                                {
                                        if(roll==ptr->rollno)
                                        {
                                                printf("%d %s %f\n\n",ptr->rollno,ptr->name,ptr->percentage);
                                                printf("Enter name and percentage to Modify : ");
                                                scanf("%s %f",ptr->name,&ptr->percentage);
                                                printf("\nModified Successfully..\n");
                                                return ;
                                        }
                                        ptr=ptr->next;
                                }
                                printf("\033[31m\nInvalid Rollno...\n\033[0m");
                        }
                        break;
                case 'n':
                case 'N':
                        {
                                int co=0;
                                char name[20];
                                printf("\nEnter name : ");
                                scanf("%s",name);
                                SLL *after;
                                while(ptr)
                                {
                                        if(strcmp(name,ptr->name)==0)
                                        {
                                                after=ptr->next;
                                                while(after)
                                                {
                                                        if(strcmp(ptr->name,after->name)==0)
                                                        {
                                                                co++;
                                                                if(co==1)
                                                                {
                                                                        printf("\nMore than One Records Found..\n");
                                                                        printf("\n%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                                                                }
                                                                printf("%d %s %f\n",after->rollno,after->name,after->percentage);
                                                        }
                                                        after=after->next;
                                                }
                                                if(co>0)
                                                        goto n;
                                                printf("\n%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                                                printf("\nEnter name and percentage to Modify : ");
                                                scanf("%s %f",ptr->name,&ptr->percentage);
                                                printf("\nModified Successfully..\n");
                                                return;
                                        }
                                        ptr=ptr->next;
                                }
                                printf("\033[31m\nInvalid Name....\n\033[0m");
                        }
                        break;
                case 'p':
                case 'P':
                        {
                                                                int co=0;
                                float p;
                                printf("\nEnter percentage : ");
                                scanf("%f",&p);
                                SLL *after;
                                while(ptr)
                                {
                                        if(p==ptr->percentage)
                                        {
                                                after=ptr->next;
                                                while(after)
                                                {
                                                        if(ptr->percentage==after->percentage)
                                                        {
                                                                co++;
                                                                if(co==1)
                                                                {
                                                                        printf("\nMore than One Records Found..\n");
                                                                        printf("\n%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                                                                }
                                                                printf("%d %s %f\n",after->rollno,after->name,after->percentage);
                                                        }
                                                        after=after->next;
                                                }
                                                if(co>0)
                                                        goto n;
                                                printf("\n%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                                                printf("\nEnter name and percentage to Modify : ");
                                                scanf("%s %f",ptr->name,&ptr->percentage);
                                                printf("\nModified Successfully..\n");
                                                return;
                                        }
                                        ptr=ptr->next;
                                }
                                printf("\033[31m\nInvalid Percentage....\n\033[0m");

                        }
                        break;
        }
}
