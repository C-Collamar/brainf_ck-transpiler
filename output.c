/**
 * This code is generated by our Brainf*** compiler.
 * You can edit this file however you like, perhaps
 * modify the BUFFER_SIZE to your needs in case you
 * need to for some reason.
 */

#include<stdio.h>

#define BUFFER_SIZE 1024

void main(void) {
    char array[BUFFER_SIZE] = { 0 };
    char *ptr = array;

    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    while(*ptr) {
        ++ptr;
        ++*ptr;
        ++*ptr;
        ++*ptr;
        ++*ptr;
        while(*ptr) {
            ++ptr;
            ++*ptr;
            ++*ptr;
            ++ptr;
            ++*ptr;
            ++*ptr;
            ++*ptr;
            ++ptr;
            ++*ptr;
            ++*ptr;
            ++*ptr;
            ++ptr;
            ++*ptr;
            --ptr;
            --ptr;
            --ptr;
            --ptr;
            --*ptr;
        }
        ++ptr;
        ++*ptr;
        ++ptr;
        ++*ptr;
        ++ptr;
        --*ptr;
        ++ptr;
        ++ptr;
        ++*ptr;
        while(*ptr) {
            --ptr;
        }
        --ptr;
        --*ptr;
    }
    ++ptr;
    ++ptr;
    putchar(*ptr);
    ++ptr;
    --*ptr;
    --*ptr;
    --*ptr;
    putchar(*ptr);
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    putchar(*ptr);
    putchar(*ptr);
    ++*ptr;
    ++*ptr;
    ++*ptr;
    putchar(*ptr);
    ++ptr;
    ++ptr;
    putchar(*ptr);
    --ptr;
    --*ptr;
    putchar(*ptr);
    --ptr;
    putchar(*ptr);
    ++*ptr;
    ++*ptr;
    ++*ptr;
    putchar(*ptr);
    --*ptr;
    --*ptr;
    --*ptr;
    --*ptr;
    --*ptr;
    --*ptr;
    putchar(*ptr);
    --*ptr;
    --*ptr;
    --*ptr;
    --*ptr;
    --*ptr;
    --*ptr;
    --*ptr;
    --*ptr;
    putchar(*ptr);
    ++ptr;
    ++ptr;
    ++*ptr;
    putchar(*ptr);
    ++ptr;
    ++*ptr;
    ++*ptr;
    putchar(*ptr);
}