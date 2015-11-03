#this makefile runs on build
# all directories relative to build except include

Libs=-lpthread -lmongoclient -lboost_thread -lboost_system -lboost_regex -lstdc++ -lm -lpthread -lwt -lssl -lcrypto
Libs1= -lwt -lmongoclient  -lstdc++ -lm -lpthread -lssl -lcrypto -lwt
#cli: cli.o
#	gcc -o cli cli.o $(Libs)
INSTDIR=/RestAPIWt/restapi
SRCDIR=$(INSTDIR)/src
OBJDIR=obj

INC= -I $(INSTDIR)/include -DLINUX -D__linux__
ENTITYOBJ= $(OBJDIR)/mongowrapper.o $(OBJDIR)/publisher.o $(OBJDIR)/jsonhelper.o $(OBJDIR)/book.o $(OBJDIR)/search.o  $(OBJDIR)/base64.o $(OBJDIR)/CSmtp.o $(OBJDIR)/md5.o 
OBJLIST=$(OBJDIR)/mongowrapper.o $(OBJDIR)/ApiService.o $(OBJDIR)/main.o $(OBJDIR)/PublisherApi.o $(OBJDIR)/publisher.o $(OBJDIR)/jsonhelper.o $(OBJDIR)/ApiRouter.o $(OBJDIR)/book.o $(OBJDIR)/BookApi.o $(OBJDIR)/search.o $(OBJDIR)/SearchApi.o $(OBJDIR)/base64.o $(OBJDIR)/CSmtp.o $(OBJDIR)/md5.o 


all: mongowtst apiserver tstmail reqproc
apiserver: $(OBJLIST)

	gcc -o apiserver $(OBJLIST) -lwthttp -lwt $(Libs)
reqproc: $(ENTITYOBJ) reqproc.o

	gcc -o reqproc reqproc.o $(ENTITYOBJ)  $(Libs)

reqproc.o: reqproc.cpp
	gcc -c reqproc.cpp $(INC)

mongowtst: mongowtst.o $(OBJLIST)
	gcc -o mongotest mongowtst.o $(OBJDIR)/mongowrapper.o $(OBJDIR)/search.o $(OBJDIR)/jsonhelper.o $(Libs)

tstmail: tstmail.o $(OBJLIST)
	gcc -o tstmail tstmail.o $(OBJDIR)/mongowrapper.o $(OBJDIR)/search.o $(OBJDIR)/jsonhelper.o $(OBJDIR)/base64.o $(OBJDIR)/CSmtp.o  $(OBJDIR)/md5.o $(Libs) 

tstmail.o: $(SRCDIR)/main/tstmail.cpp
	gcc -c $(SRCDIR)/main/tstmail.cpp  $(INC)

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

$(OBJDIR)/CSmtp.o: $(SRCDIR)/util/CSmtp.cpp
	gcc -c $(SRCDIR)/util/CSmtp.cpp -o $(OBJDIR)/CSmtp.o $(INC)
$(OBJDIR)/base64.o: $(SRCDIR)/util/base64.cpp
	gcc -c $(SRCDIR)/util/base64.cpp -o $(OBJDIR)/base64.o $(INC)
$(OBJDIR)/md5.o: $(SRCDIR)/util/md5.cpp
	gcc -c $(SRCDIR)/util/md5.cpp -o $(OBJDIR)/md5.o $(INC)

$(OBJDIR)/ApiRouter.o: $(SRCDIR)/rest/ApiRouter.cpp
	gcc -c $(SRCDIR)/rest/ApiRouter.cpp -o $(OBJDIR)/ApiRouter.o $(INC)

$(OBJDIR)/main.o: $(SRCDIR)/main/main.cpp
	gcc -c $(SRCDIR)/main/main.cpp -o $(OBJDIR)/main.o $(INC)


clean:
	rm -f obj/*.o
	rm -f *.o
	rm -f apiserver
	rm -f mongotest
