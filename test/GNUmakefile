test: test.exe
	./test.exe | cmp -s - expected.txt
.PHONY: test

test.exe: main.c libft_branch.a
	$(CC) $(CPPFLAGS) -I ../include $(CFLAGS) -L . main.c -l ft_branch -o $@

.PHONY: libft_branch.a
libft_branch.a:
	NAME=test/libft_branch.a $(MAKE) -C ..

.PHONY: clean
clean:
	rm -f test.exe

.PHONY: fclean
fclean: clean
