#this makefile runs on build
# all directories relative to build except include

all: PubService 
Libs=-lpthread -lmongoclient -lboost_thread -lboost_system -lboost_regex -lstdc++ -lm -lpthread -lwt -L/usr/lib64  -lboost_signals -lwthttp -lwt
#cli: cli.o
SRCDIR=./
OBJDIR=obj

INC= -Wcpp -I ./ -std=c++11
OBJLIST=$(OBJDIR)/PubService.o $(OBJDIR)/MainForm.o $(OBJDIR)/AddBookForm.o $(OBJDIR)/SearchReqForm.o

PubService: $(OBJLIST)

	g++ -o PubService $(OBJLIST) -lwthttp -lwt $(Libs)


$(OBJDIR)/PubService.o: $(SRCDIR)/PubService.cpp
	g++ -c $(SRCDIR)/PubService.cpp -o $(OBJDIR)/PubService.o $(INC)
$(OBJDIR)/AddBookForm.o: $(SRCDIR)/AddBookForm.cpp
	g++ -c $(SRCDIR)/AddBookForm.cpp -o $(OBJDIR)/AddBookForm.o $(INC)
$(OBJDIR)/SearchReqForm.o: $(SRCDIR)/SearchReqForm.cpp
	g++ -c $(SRCDIR)/SearchReqForm.cpp -o $(OBJDIR)/SearchReqForm.o $(INC)


$(OBJDIR)/MainForm.o: $(SRCDIR)/MainForm.cpp
	g++ -c $(SRCDIR)/MainForm.cpp -o $(OBJDIR)/MainForm.o $(INC)



clean:
	rm -f obj/*.o
	rm -f *.o
	rm -f apiserver
	rm -f mongotest
