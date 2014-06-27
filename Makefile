CPPFLAGS=-g

.PHONY: all clean get_datasets test_readlabels_test test_readlabels_train test_readimages test_readimages_test test_readimages_train

all: src/readlabels src/readimages

src/readlabels: src/readlabels.o src/idx.o
src/readimages: src/readimages.o src/idx.o

src/idx.o: src/idx.c src/idx.h
src/readimages.o: src/readimages.c src/idx.h
src/readlabels.o: src/readlabels.c src/idx.h


clean:
	rm -rf src/readimages src/readlabels src/*.o


get_datasets:
	mkdir -p datasets/; cd datasets/; wget -i ../mnist.links; gunzip *.gz;


test_readlabels_test: src/readlabels
	@src/readlabels datasets/t10k-labels-idx1-ubyte

test_readlabels_train: src/readlabels
	@src/readlabels datasets/train-labels-idx1-ubyte


test_readimages: test_readimages_test test_readimages_train

test_readimages_test: src/readimages
	@src/readimages datasets/t10k-images-idx3-ubyte |head -n 30

test_readimages_train: src/readimages
	@src/readimages datasets/train-images-idx3-ubyte |head -n 30
