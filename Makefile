# config
CC=gcc
OUTPUTDIR=bin
TARGET=irisviel
SOURCEDIR=src

# creates the output directory
# compile all the source files in SOURCE/
all:
	mkdir -p $(OUTPUTDIR)
	$(CC) -g -Wall -o $(OUTPUTDIR)/$(TARGET) $(SOURCEDIR)/*.c

clean:
	rm $(OUTPUTDIR)/$(TARGET)
