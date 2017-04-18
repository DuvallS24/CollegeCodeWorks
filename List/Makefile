# Makefile for Project 6
#****************************************************************

CPPOPTIONS = -I../StanfordCPPLib -fvisibility-inlines-hidden -std=c++11
LDOPTIONS = -L../StanfordCPPLib
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: list_test spl.jar

spl.jar:
	@ln -s ../StanfordCPPLib/spl.jar

list_test: list_test.o
	g++ $(LDOPTIONS) -o list_test list_test.o $(LIB)

list_test.o: list_test.cpp
	g++ $(CPPOPTIONS) -c list_test.cpp
	
#TemplateList.o: TemplateList.cpp TemplateList.h
#	g++ $(CPPOPTIONS) -c TemplateList.cpp
	
#time.o: time.cpp time.h
#	g++ $(CPPOPTIONS) -c time.cpp
	
#track.o: track.cpp track.h
#	g++ $(CPPOPTIONS) -c track.cpp

#time_test.o: time_test.cpp time.h
#	g++ $(CPPOPTIONS) -c time_test.cpp

#time_test: time_test.o time.o
#	g++ $(LDOPTIONS) -o time_test time_test.o time.o $(LIB)

#point_test.o: point_test.cpp point.h time.h
#	g++ $(CPPOPTIONS) -c point_test.cpp

#point_test: point_test.o point.o time.o
#	g++ $(LDOPTIONS) -o point_test point_test.o point.o time.o $(LIB)


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
