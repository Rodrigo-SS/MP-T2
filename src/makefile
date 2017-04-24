IDIR =../include
CXX=g++
CXXFLAGS= -ftest-coverage -fprofile-arcs -I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS= -lgtest -lpthread -lgtest_main

_DEPS= romano.h
DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ= testa_romano.o romano.o 
OBJ= $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LIBS)

teste.exe: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 