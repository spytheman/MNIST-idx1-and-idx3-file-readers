MNIST-idx1-and-idx3-file-readers
================================

Simple C reader functions for the MNIST database of handwritten digits


Usage:
===============

To download the mnist database files:
    make get_datasets ;

To build the C examples:
    make ;


Source structure:
==================

See the src/idx.h and src/idx.c for the IDX reader implementations.

See src/readimages.c for sample usage of the fread_idx3_file() function - the example just dumps the data from the given IDX3 file, as a stream of ASCII formatted pictures on stdout.

See src/readlabels.c for sample usage of the fread_idx1_file() function - it just dumps each of the labels in the given IDX1 label file, each label on its own line, on stdout.
