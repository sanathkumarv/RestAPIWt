#this makefile runs on build
# all directories relative to build except include

all: mongowtst apiserver
Libs=-lpthread -lmongoclient -lboost_thread -lboost_system -lboost_regex -lstdc++ -lm -lpthread -lwt
#cli: cli.o
#	gcc -o cli cli.o $(Libs)
INSTDIR=/RestApiWt/restapi
SRCDIR=../src
OBJDIR=obj

INC= -I $(INSTDIR)/include
OBJLIST=$(OBJDIR)/mongowrapper.o $(OBJDIR)/ApiService.o $(OBJDIR)/main.o $(OBJDIR)/PublisherApi.o $(OBJDIR)/publisher.o $(OBJDIR)/jsonhelper.o $(OBJDIR)/ApiRouter.o $(OBJDIR)/book.o $(OBJDIR)/BookApi.o $(OBJDIR)/search.o $(OBJDIR)/SearchApi.o


apiserver: $(OBJLIST)

	gcc -o apiserver $(OBJLIST) -lwthttp -lwt $(Libs)

mongowtst: mongowtst.o $(OBJLIST)
	gcc -o mongotest mongowtst.o $(OBJDIR)/mongowrapper.o $(OBJDIR)/search.o $(OBJDIR)/jsonhelper.o $(Libs)

$(OBJDIR)/mongowrapper.o: $(SRCDIR)/db/mongowrapper.cpp
	gcc -c $(SRCDIR)/db/mongowrapper.cpp -o $(OBJDIR)/mongowrapper.o $(INC)
mongowtst.o: $(SRCDIR)/db/mongowtst.cpp
	gcc -c $(SRCDIR)/db/mongowtst.cpp  $(INC)

$(OBJDIR)/ApiService.o: $(SRCDIR)/rest/ApiService.cpp
	gcc -c $(SRCDIR)/rest/ApiService.cpp -o $(OBJDIR)/ApiService.o $(INC)

$(OBJDIR)/PublisherApi.o: $(SRCDIR)/rest/PublisherApi.cpp
	gcc -c $(SRCDIR)/rest/PublisherApi.cpp -o $(OBJDIR)/PublisherApi.o $(INC)
$(OBJDIR)/BookApi.o: $(SRCDIR)/rest/BookApi.cpp
	gcc -c $(SRCDIR)/rest/BookApi.cpp -o $(OBJDIR)/BookApi.o $(INC)
$(OBJDIR)/SearchApi.o: $(SRCDIR)/rest/SearchApi.cpp
	gcc -c $(SRCDIR)/rest/SearchApi.cpp -o $(OBJDIR)/SearchApi.o $(INC)

$(OBJDIR)/publisher.o: $(SRCDIR)/entity/publisher.cpp
	gcc -c $(SRCDIR)/entity/publisher.cpp -o $(OBJDIR)/publisher.o $(INC)

$(OBJDIR)/book.o: $(SRCDIR)/entity/book.cpp
	gcc -c $(SRCDIR)/entity/book.cpp -o $(OBJDIR)/book.o $(INC)

$(OBJDIR)/search.o: $(SRCDIR)/entity/search.cpp
	gcc -c $(SRCDIR)/entity/search.cpp -o $(OBJDIR)/search.o $(INC)

$(OBJDIR)/jsonhelper.o: $(SRCDIR)/util/jsonhelper.cpp
	gcc -c $(SRCDIR)/util/jsonhelper.cpp -o $(OBJDIR)/jsonhelper.o $(INC)

$(OBJDIR)/ApiRouter.o: $(SRCDIR)/rest/ApiRouter.cpp
	gcc -c $(SRCDIR)/rest/ApiRouter.cpp -o $(OBJDIR)/ApiRouter.o $(INC)

$(OBJDIR)/main.o: $(SRCDIR)/main/main.cpp
	gcc -c $(SRCDIR)/main/main.cpp -o $(OBJDIR)/main.o $(INC)


clean:
	rm -f obj/*.o
	rm -f *.o
	rm -f apiserver
	rm -f mongotest
