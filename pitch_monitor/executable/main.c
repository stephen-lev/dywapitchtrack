#include "../include/portaudio_helper.h"
#include <stdio.h>

int main()
{
    printf("\n%d\n", Pa_version());
    int ret = init();
    int deviceId = get_default_input_device();
    start_receiving_input(deviceId);

    getchar();

    return 0;
}