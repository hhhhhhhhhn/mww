compile:
	cc main.c -O3 -o mww
install:
	mv ./mww /bin/mww
debug:
	cc main.c -g -O0 -o mww
clean:
	rm mww
