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
