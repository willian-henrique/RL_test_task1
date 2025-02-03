src = $(wildcard src/*.c)  \
		$(wildcard test/*.c)

obj = $(src:.c=.o)
CC ?= gcc
LDFLAGS = 
CFLAGS = -Wall -O2 -Werror

all: app

app: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(obj) app
