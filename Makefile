mww:
	cc main.c -O3 -o mww
install: mww
	mv ./mww /usr/bin/mww
clean:
	rm mww
