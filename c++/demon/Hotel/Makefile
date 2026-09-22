CC = g++
CCFLAGS= -Wall -pedantic
EXTC = cpp
EXTH = h
EXECUTABLE = tp1
SRC = $(wildcard *.$(EXTC))
HDR = $(wildcard *.$(EXTH))
OBJ = $(SRC:.$(EXTC)=.o)
all: $(EXECUTABLE)
$(Executable): $(OBJ)
@$(CC) -o $@ $^
%.o: %.$(EXTC) %.$(EXTH)
@$(CC) $(CCFLAGS) -o $@ -c $<
clean:
rm -rf *.o
rm -f $(EXECUTABLE)