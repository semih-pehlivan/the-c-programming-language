
BUILDDIR=build

SRCS=$(wildcard *.c)
PROGRAMS=$(patsubst %.c,$(BUILDDIR)/%, $(SRCS) )

CFLAGS= -Wall -Werror -pedantic -ansi

all: ${PROGRAMS}

$(BUILDDIR)/%: %.c $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILDDIR):
	mkdir $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)
