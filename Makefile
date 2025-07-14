
test:
	#gcc -c -Wall -Werror -fpic html2c.c
	#gcc -shared -o libhtml2c.so html2c.o
	#gcc -Wall -o main main.c -lhtml2c
	gcc -c main.c
	gcc -c html2c.c
	gcc -o execs main.o html2c.o
	./execs

main:	main.c
	gcc -Wall -o main main.c -lhtml2c

libhtml2c: html2c.o
	gcc -shared -o libhtml2c.so html2c.o


html2c.o: html2c.c
	gcc -c -Wall -Werror -fpic html2c.c

clear:
	rm *.so *.o
	rm execs