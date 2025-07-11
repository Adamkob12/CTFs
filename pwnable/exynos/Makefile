all: exploit/exploit.c
	gcc exploit/exploit.c
	./a.out

search: exploit/exploit.c
	gcc -DSEARCH exploit/exploit.c
	./a.out

clean:
	rm a.out

code:
	base64 exploit/exploit.c


