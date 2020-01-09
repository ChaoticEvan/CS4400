#include "stdio.h"

// Needed this to be here for forward declaration. Fun stuff :)
void testFunc();

int main (void)
{
    printf("Hello world\n");
    testFunc();
    return 0;
}

void testFunc()
{
    printf("does this print?\n");
}