C = gcc
CFLAGS =-g -Wall -pedantic -ansi
OBJ = main.o random.o terminal.o blocks.o printArr.o goal.o printx.o fileR.o fileRX.o demoChangeColor.o linked_list.o
EXEC = escape




$(EXEC) : $(OBJ)
	                         $(CC) $(OBJ) -o $(EXEC)

main.o : main.c random.h terminal.h blocks.h printArr.h goal.h printx.h fileR.h demoChangeColor.h linked_list.h
	                          $(CC) -c main.c $(CFLAGS)
random.o : random.c random.h
	                         $(CC) -c random.c $(CFLAGS)
terminal.o : terminal.c terminal.h
	                                  $(CC) -c terminal.c $(CFLAGS)

blocks.o : blocks.c blocks.h
	                                          $(CC) -c blocks.c $(CFLAGS)

printArr.o : printArr.c printArr.h demoChangeColor.h 
	                                          $(CC) -c printArr.c $(CFLAGS)

goal.o : goal.c goal.h
	                                          $(CC) -c goal.c $(CFLAGS)

printx.o : printx.c printx.h
	                                          $(CC) -c printx.c $(CFLAGS)

fileR.o : fileR.c fileR.h
	                                                  $(CC) -c fileR.c $(CFLAGS)

fileRX.o : fileRX.c fileRX.h
	                                                          $(CC) -c fileRX.c $(CFLAGS)
demoChangeColor.o : demoChangeColor.c demoChangeColor.h
	                                                                  $(CC) -c demoChangeColor.c $(CFLAGS)
linked_list.o : linked_list.c linked_list.h
	                                 $(CC) -c linked_list.c $(CFLAGS)


clean:
	                        rm -f $(EXEC) $(OBJ)
