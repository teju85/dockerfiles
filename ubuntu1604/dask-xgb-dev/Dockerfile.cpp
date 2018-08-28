
#ifndef __CUDA_VERSION_SHORT
#define "__CUDA_VERSION_SHORT is a mandatory define! Eg: dev-8.0"
#endif

FROM xgb:__CUDA_VERSION_SHORT

#include "../../reusables/dask-xgboost"
#include "../../reusables/ssh"
