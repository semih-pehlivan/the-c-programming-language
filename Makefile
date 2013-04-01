
BUILDDIR=build

SRCS=$(wildcard *.c)

PROG_SRCS=$(wildcard exercises/exercise*.c)
PROGRAMS=$(patsubst exercises/%.c,$(BUILDDIR)/exercises/%, $(PROG_SRCS) )

SHARED_SRCS=$(wildcard shared/*.c)
SHARED_OBJS=$(patsubst shared/%.c,$(BUILDDIR)/shared/%.o, $(SHARED_SRCS) )


CFLAGS+= -Wall -Wextra -Werror -pedantic-errors -std=c89

CFLAGS+= -I./shared


all: ${PROGRAMS}

foo:
	echo $(PROG_SRCS)
	echo $(PROGRAMS)
	echo $(SHARED_OBJS)

$(BUILDDIR)/%: %.c $(SHARED_OBJS) $(BUILDDIR)
	$(CC) -g $(CFLAGS) $(INCLUDES) $(SHARED_OBJS) $< -o $@

$(BUILDDIR)/%.o: %.c
	$(CC) -g $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR) $(BUILDDIR)/utils $(BUILDDIR)/exercises $(BUILDDIR)/shared

clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean
