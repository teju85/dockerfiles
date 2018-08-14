
#ifndef __CUDA_VERSION_SHORT
#define "__CUDA_VERSION_SHORT is a mandatory define! Eg: latest-8.0"
#endif

FROM xgboost:__CUDA_VERSION_SHORT

#include "../../reusables/dask-xgboost"
#include "../../reusables/ssh"
