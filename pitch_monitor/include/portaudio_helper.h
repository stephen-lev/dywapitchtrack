#ifndef posrtaudio_helper__H
#define posrtaudio_helper__H

#include "libpitcher_exports.h"

LIBPITCHER_EXPORTS int Pa_version();

LIBPITCHER_EXPORTS int init();

LIBPITCHER_EXPORTS int get_default_input_device();

LIBPITCHER_EXPORTS void start_receiving_input(int deviceIndex);

#endif