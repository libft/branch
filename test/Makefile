test: test.exe
	./test.exe | cmp -s - expected.txt
.PHONY: test

test.exe:
	$(CC) $(CPPFLAGS) -I ../include $(CFLAGS) ../src/ft_branch.c main.c -o $@

.PHONY: clean
clean:
	rm -f test.exe

.PHONY: fclean
fclean: clean
