CC = g++
OBJS = main.o map.o player.o
CFILES = main.cpp

result: $(OBJS)
	$(CC) $(OBJS) -o $@
%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY: run
run:
	./result

.PHONY: clean
clean:
	rm -f $(OBJS) result