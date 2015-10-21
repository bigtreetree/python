example:example.o
	gcc -shared -fpic -o example.so $^ 
%.o:%.c
	gcc -fPIC -c $^ -I/usr/include/python2.6/

clean:
	rm -rf hello.so hello.o
