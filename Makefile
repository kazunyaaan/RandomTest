# Makefile

CC     = g++

CFLAG    = -O3 -std=c++11 -Wall
CFLAG_MT = -mavx -DDSFMT_MEXP=19937 -DHAVE_SSE2

DSFMT    = dSFMT-src-2.2.3/

all:
	$(CC) $(CFLAG) $(CFLAG_MT) -I $(DSFMT) $(DSFMT)dSFMT.c test.cpp -o test
run:
	./test
