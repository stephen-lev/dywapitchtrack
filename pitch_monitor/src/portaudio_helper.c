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
    //TODO: portaudio does not recommend to do the heavylifting inside the stream callback because it needs to be 'on time'
    //refactoring pitch detection around an instance based model is suggested: doing all the necessary allocations during initialization based on more init parameters
    double result = dywapitch_computepitch(userData, input, 0, frameCount);
    if (result != 0.0) {
        printf("\n%f", result);
    }

    return 0;
}

//TODO: implement callback for pitch value
void start_continous_pitch_detection(int deviceIndex) {
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
