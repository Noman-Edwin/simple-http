main: main.o accept_socked.o build_socked.o send_socked.o get_line.o bad_requst.o head.o
	gcc -o main main.o accept_socked.o build_socked.o send_socked.o get_line.o  bad_requst.o head.o 
clean:
	rm -f main main.o accept_socked.o build_socked.o send_socked.o get_line.o bad_requst.o head.o
