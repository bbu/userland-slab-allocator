#!/bin/sh

gcc -std=gnu11 -D_ISOC11_SOURCE -D_POSIX_C_SOURCE=200809L -D_BSD_SOURCE \
    -Wall -Wextra -pedantic slab.c -lm
