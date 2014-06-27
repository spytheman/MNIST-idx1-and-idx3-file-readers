CPPFLAGS=-g

all: src/readlabels src/readimages

src/readlabels: src/readlabels.o src/idx.o
src/readimages: src/readimages.o src/idx.o

src/readimages.o: src/readimages.c src/idx.h
src/readlabels.o: src/readlabels.c src/idx.h
src/idx.o: src/idx.c src/idx.h

.PHONY: clean get_datasets all

get_datasets:
	mkdir -p datasets/; cd datasets/; wget -i ../mnist.links; gunzip *.gz;

clean:
	rm -rf src/readlabels src/*.o


test_readlabels_test: src/readlabels
	@src/readlabels datasets/t10k-labels-idx1-ubyte

test_readlabels_train: readlabels
	@src/readlabels datasets/train-labels-idx1-ubyte
	