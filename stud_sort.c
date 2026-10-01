#include "student.h"
void stud_sort(SLL *ptr)
{
        if(ptr==0)
        {
                printf("No Records Found..\n");
                return ;
        }
        char op;
        int co,i,j;
        SLL *p1=ptr,*p2,t;
        co=countNode(ptr);
        printf("N/n : Sort with name\nP/p : Sort with percentage\n\nEnter your choice : ");
        scanf(" %c",&op);
        switch(op)
        {
                case 'n':
                case 'N':
                        {
                                for(i=0;i<co-1;i++)
                                {
                                        p2=p1->next;
                                        for(j=1+i;j<co;j++)
                                        {
                                                if(strcmp(p1->name,p2->name)>0)
                                                {
                                                        strcpy(t.name,p1->name);
                                                        t.percentage=p1->percentage;

                                                        strcpy(p1->name,p2->name);
                                                        p1->percentage=p2->percentage;

                                                        strcpy(p2->name,t.name);
                                                        p2->percentage=t.percentage;
                                                }
                                                p2=p2->next;
                                        }
                                        p1=p1->next;
                                }
                                printf("\nSorting Completed According to Name..\n");
                        }
                        break;
                case 'p':
                case 'P':
                        {
                                for(i=0;i<co-1;i++)
                                {
                                        p2=p1->next;
                                        for(j=1+i;j<co;j++)
                                        {
                                                if(p1->percentage < p2->percentage)
                                                {
                                                        strcpy(t.name,p1->name);
                                                        t.percentage=p1->percentage;

                                                        strcpy(p1->name,p2->name);
                                                        p1->percentage=p2->percentage;

                                                        strcpy(p2->name,t.name);
                                                        p2->percentage=t.percentage;
                                                }
                                                p2=p2->next;
                                        }
                                        p1=p1->next;
                                }
                                printf("\nSorting Completed According to Percentage..\n");

                        }
                        break;
        }
}
