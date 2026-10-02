clean:
	rm -r out/

test:
	./START.sh inp/test.bmp test_new

all: test clean
