#include "../portaudio-lib/inlcude/portaudio.h"
#include "../include/portaudio_helper.h"

int Pa_version() {

    return Pa_GetVersion();
}



PaDeviceIndex Pa_GetDefaultInputDevice( void );
