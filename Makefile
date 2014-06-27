
readlabels: src/readlabels
	cp src/readlabels readlabels

src/readlabels: src/readlabels.c

.PHONY: clean get_datasets

get_datasets:
	mkdir -p datasets/; cd datasets/; wget -i ../mnist.links; gunzip *.gz;

clean:
	rm -rf src/readlabels readlabels

