ifeq ($(NAME),)
$(error No name found)
endif

TMP_SUFFIX := $(shell echo $$$$)

$(NAME): obj/ft_branch.o
	mkdir -p tmp
	ar cr tmp/libft_branch.$(TMP_SUFFIX).a $^
	rm -f $@
	mkdir -p $(@D)
	mv tmp/libft_branch.$(TMP_SUFFIX).a $@

obj/ft_branch.o: src/ft_branch.c
	rm -f $@.tmp $@
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) -I include $(CFLAGS) -c -o $@.tmp $<
	mv $@.tmp $@
