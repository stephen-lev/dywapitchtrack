#include "../include/portaudio_helper.h"
#include <stdio.h>

int main()
{
    printf("\n%d\n", Pa_version());
    return 0;
}