#include "header.h" 
void stud_save(SLL *ptr)
{
        FILE *fp=fopen("student.dat","w");
        while(ptr)
        {
                fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                ptr=ptr->next;
        }
        printf("Records Saved Successfully in a File...\n");
        fclose(fp);
}
