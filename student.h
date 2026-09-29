#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
        int rollno;
        char name[50];
        float percentage;
        struct student *next;
}SLL;
void stud_add(SLL **);
void stud_show(SLL *);
void stud_save(SLL *);
void stud_del(SLL **);
void del_all(SLL **);
void stud_sort(SLL *);
void rev_list(SLL **);
int countNode(SLL *);
void stud_mod(SLL *);
int roll_finder(SLL *);
