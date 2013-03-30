
BUILDDIR=build

SRCS=$(wildcard *.c)
PROGRAMS=$(patsubst %.c,$(BUILDDIR)/%, $(SRCS) )

CFLAGS= -Wall -Wextra -Werror -pedantic-errors -std=c89

all: ${PROGRAMS}

$(BUILDDIR)/%: %.c $(BUILDDIR)
	$(CC) -g $(CFLAGS) $< -o $@

$(BUILDDIR):
	mkdir $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)
