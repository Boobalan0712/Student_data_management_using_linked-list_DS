target = stud_add.o  stud_del.o stud_main.o  stud_mod.o  stud_save.o stud_show.o  stud_sort.o
student : $(target)
        cc $(target) -o student

stud_main.o : stud_main.c
        cc -c $^
stud_add.o : stud_add.c
        cc -c $^
stud_del.o : stud_del.c
        cc -c $^
stud_mod.o : stud_mod.c
        cc -c $^
stud_save.o : stud_save.c
        cc -c $^
stud_show.o : stud_show.c
        cc -c $^
stud_sort.o : stud_sort.c
        cc -c $^

clear:
        @echo "Cleaning up..."
        @rm -vr *.o
