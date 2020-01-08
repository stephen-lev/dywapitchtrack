#include "../portaudio-lib/inlcude/portaudio.h"
#include "../include/portaudio_helper.h"
#include "../include/dywapitchtrack.h"
#include <stdio.h>

int Pa_version() {
    return Pa_GetVersion();
}


int init() {
    return Pa_Initialize();
}

int get_default_input_device(){
    return Pa_GetDefaultInputDevice();
}

int inputSamplesCallback(
    const void* input, void* output,
    unsigned long frameCount,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void* userData)
{
    double result = dywapitch_computepitch(userData, input, 0, frameCount);
    if (result != 0.0) {
        printf("\n%f", result);
    }

    return 0;
}

void start_receiving_input(int deviceIndex) {
    PaStreamParameters inputParameters;
    inputParameters.device = deviceIndex;
    PaDeviceInfo* inputInfo = Pa_GetDeviceInfo( inputParameters.device );
    PaStream* inputStream;
    inputParameters.channelCount = inputInfo->maxInputChannels;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = inputInfo->defaultHighInputLatency;
    inputParameters.hostApiSpecificStreamInfo = 0;
    dywapitchtracker pitch_tracker;
    dywapitch_inittracking(&pitch_tracker);

    PaError ret = Pa_OpenStream(&inputStream, &inputParameters, 0, inputInfo->defaultSampleRate, 1024, paClipOff, &inputSamplesCallback, &pitch_tracker);
    ret = Pa_StartStream(inputStream);
}
