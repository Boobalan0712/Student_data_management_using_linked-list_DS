#include "student.h"
void stud_show(SLL *ptr)
{
        if(ptr==0)
        {
                printf("\033[31mNo student records Available..\n\033[0m");
                return ;
        }
        printf("-------------------------------------\nRollno.   Name    Percentage\n-------------------------------------\n");
        while(ptr)
        {
                printf("%d    %s   %f\n",ptr->rollno,ptr->name,ptr->percentage);
                ptr=ptr->next;
        }
}
