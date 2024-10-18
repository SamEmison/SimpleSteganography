#/**
#* @file Makefile
#* @author Sam Emison and Cole Belew
#* @date 2024-10-17
#* @brief Makefile for the Steganography assignment
#*
#* Cleans up everything and creates an executable

CC = g++ # The compiler
TARGET = test # Makes "test" the executable
CFLAGS = -c -Wall -Wextra -g # Compile with all errors and warnings

#Object Files
OBJS = main.o Steganography.o

all: $(TARGET)

# Links object files to create an executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

#Compiles main.o from source
main.o: main.cpp Steganography.h
	$(CC) $(CFLAGS) main.cpp -o main.o

#Compiles Steganography.o from source
Steganography.o: Steganography.cpp Steganography.h
	$(CC) $(CFLAGS) Steganography.cpp -o Steganography.o

clean: #Cleans everything up
	rm -f *.o *~ $(TARGET)


