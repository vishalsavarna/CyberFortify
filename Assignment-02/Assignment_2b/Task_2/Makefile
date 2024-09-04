FLAGS    = -z execstack -fno-stack-protector
TARGET   = vul-L2 vul-L2-dbg
 
all: $(TARGET)

vul-L2: vulnerable.c
	gcc $(FLAGS) -o $@ vulnerable.c
	gcc $(FLAGS) -g -o $@-dbg vulnerable.c
	sudo chown root $@ && sudo chmod 4755 $@

clean:
	rm -f badfile $(TARGET) peda-session-vul*.txt .gdb_history

