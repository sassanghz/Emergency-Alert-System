# Variables
CC = gcc
CFLAGS = -Iinclude # search for header files in include directory
DEPS = include/contact.h include/alert.h include/utils.h
OBJ = main.o contact.o alert.o utils.o

%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

emergency_alert_system: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lcurl

clean:
	rm -f *.o emergency_alert_system
