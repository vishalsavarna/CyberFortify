FLAGS    = -z execstack -fno-stack-protector
FLAGS_32 = -m32
TARGET   = vul-L1 vul-L1-dbg
 
all: $(TARGET)

vul-L1: vulnerable.c
	gcc $(FLAGS) $(FLAGS_32) -o $@ vulnerable.c
	gcc $(FLAGS) $(FLAGS_32) -g -o $@-dbg vulnerable.c
	sudo chown root $@ && sudo chmod 4755 $@

clean:
	rm -f badfile $(TARGET) peda-session-vul*.txt .gdb_history

