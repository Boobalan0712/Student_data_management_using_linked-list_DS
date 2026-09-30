#include "student.h"
int main()
{
        SLL *headptr=0;
        char op;
        FILE *fp=fopen("student.dat","r");
        if(fp!=0)
        {
                SLL **ptr=&headptr;
                SLL *new,*last;
                while(1)
                {
                        new=malloc(sizeof(SLL));
                        if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->percentage)==-1)
                                break;
                        new->next=0;
                        if(*ptr==0)
                                *ptr=new;
                        else
                        {
                                last=*ptr;
                                while(last->next)
                                        last=last->next;
                                last->next=new;
                        }
                }
                printf("\033[31;3m\nStudent records copied from file...\n\033[0m");
        }
        while(1)
        {
                printf("\n******** STUDENT RECORD MENU ********\n\na/A : Add new record\nd/D : Delete a record\ns/S : Show the list\nm/M : Modify a record\nv/V : Save records\ne/E : Exit\nt/T : Sort the list\nl/L : Delete all the records\nr/R : Reverse the list\n\nEnter your choice : ");
                scanf(" %c",&op);
                printf("\n");
                switch(op)
                {
                        case 'a':
                        case 'A':
                                stud_add(&headptr);
                                break;
                        case 's':
                        case 'S':
                                stud_show(headptr);
                                break;
                        case 'm':
                        case 'M':
                                stud_mod(headptr);
                                break;
                        case 'd':
                        case 'D':
                                stud_del(&headptr);
                                break;
                        case 'l':
                        case 'L':
                                del_all(&headptr);
                                break;
                        case 'v':
                        case 'V':
                                stud_save(headptr);
                                break;
                        case 't':
                        case 'T':
                                stud_sort(headptr);
                                break;
                        case 'r':
                        case 'R':
                                rev_list(&headptr);
                                break;
                        case 'e':
                        case 'E':
                                {
                                        char op;
                                        printf("S/s : Save and exit\nE/e : Exit without saving\n\nEnter your choice : ");
                                        scanf(" %c",&op);
                                        switch(op)
                                        {
                                                case 's':
                                                case 'S':
                                                        stud_save(headptr);
                                                        break;
                                                case 'e':
                                                case 'E':
                                                        return 0;
                                        }
                                }
                                return 0;
                }
        }
}
//*********************** Sorting the list ****************************************

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

// ******************************** Reversing the list *********************************

void rev_list(SLL **ptr)
{
        if(*ptr==0)
        {
                printf("No Records Found...\n");
                return ;
        }
        int co=0,i;
        co=countNode(*ptr);
        if(co>1)
        {
                SLL **a,*t=*ptr;
                a=malloc(sizeof(SLL *)*co);
                for(i=0;i<co;i++)
                {
                        a[i]=t;
                        t=t->next;
                }
                for(i=co-1;i>0;i--)
                        a[i]->next=a[i-1];
                a[0]->next=0;
                *ptr=a[co-1];
        }
        printf("List has Been Reversed Successfully...\n");
}

//****************************** Count Nodes ********************************

int countNode(SLL *ptr)
{
        int count=0;
        while(ptr)
        {
                count++;
                ptr=ptr->next;
        }
        return count;
}
// **************************** To find Not already used roll no **********************

int roll_finder(SLL *ptr)
{
        int roll=1;
        SLL *cur;
        while(1)
        {
                cur=ptr;
                while(cur)
                {
                        if(cur->rollno == roll)
                                break;
                        cur=cur->next;
                }
                if(cur==0)
                        return roll;
                roll++;
        }
}
