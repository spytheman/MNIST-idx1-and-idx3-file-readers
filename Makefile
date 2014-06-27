CPPFLAGS=-g

src/readlabels: src/readlabels.c

.PHONY: clean get_datasets

get_datasets:
	mkdir -p datasets/; cd datasets/; wget -i ../mnist.links; gunzip *.gz;

clean:
	rm -rf src/readlabels readlabels


test_readlabels_test: src/readlabels
	@src/readlabels datasets/t10k-labels-idx1-ubyte

test_readlabels_train: readlabels
	@src/readlabels datasets/train-labels-idx1-ubyte
	