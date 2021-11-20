#!/bin/sh
make -C ex00 address
make -C ex00 leak
make -C ex00 thread
make -C ex00 memory

make -C ex01 address
make -C ex01 leak
make -C ex01 thread
make -C ex01 memory
