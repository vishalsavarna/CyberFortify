
all: 
	gcc -m32 -z execstack -o a32.out shellcode.c
	gcc -z execstack -o a64.out shellcode.c

setuid:
	gcc -m32 -z execstack -o a32.out shellcode.c
	gcc -z execstack -o a64.out shellcode.c
	sudo chown root a32.out a64.out
	sudo chmod 4755 a32.out a64.out

clean:
	rm -f a32.out a64.out *.o

