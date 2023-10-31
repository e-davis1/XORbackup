#include <stdio.h>
#include "stringXorToBinString.h"

int main() {
    char hello[] = "hello";
    char world[] = "world";
    char result[41] = "";
    int resLength = stringXorToBinString(&hello, &world, &result);
    printf("The length is %d, the string is %s", resLength, result);
    return 0;
}
