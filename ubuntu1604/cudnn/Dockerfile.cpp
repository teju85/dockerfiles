
#ifndef __CUDA_VERSION_SHORT
#error "__CUDA_VERSION_SHORT is a mandatory define! Eg: 8.0"
#endif

FROM cuda:__CUDA_VERSION_SHORT

#include "../../reusables/cudnn"
