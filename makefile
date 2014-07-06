#参数设定
CC=g++
FLAG=-c -std=c++11
EXEC=Agenda
OBJECTS = Agenda.o AgendaService.o AgendaUI.o \
Date.o User.o Meeting.o Storage.o

#可执行文件
$(EXEC) : $(OBJECTS) 
	$(CC) -o $(EXEC) $(OBJECTS)
#中间文件
Agenda.o : Agenda.cpp AgendaUI.h
	$(CC) $(FLAG) Agenda.cpp

AgendaUI.o : AgendaUI.h AgendaUI.cpp AgendaService.h
	$(CC) $(FLAG) AgendaUI.cpp

AgendaService.o : AgendaService.h AgendaService.cpp Storage.h
	$(CC) $(FLAG) AgendaService.cpp

Storage.o : Storage.h Storage.cpp Meeting.h User.h
	$(CC) $(FLAG) Storage.cpp

Meeting.o : Meeting.h Meeting.cpp Date.h
	$(CC) $(FLAG) Meeting.cpp

User.o : User.h User.cpp
	$(CC) $(FLAG) User.cpp

Date.o : Date.h Date.cpp
	$(CC) $(FLAG) Date.cpp

.PHONY : clean
clean :
	-rm -f Agenda *.o *~

.PHONY : run
run :
	./$(EXEC)

