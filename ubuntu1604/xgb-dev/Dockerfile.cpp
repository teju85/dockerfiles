
// The assumption with this dockerfile is that one has to volume-mount
// the directory that contains a 'git clone --recursive'd xgboost repo
// and the build/test commands will be done through the nvidia-docker
// container running on this image!!
//
// Then use the scripts/xgb-dev.sh to launch a container on this image
//
// After this, inside this container, the usual xgboost build and test
// commands can be executed

#ifndef __CUDA_VERSION_SHORT
#define "__CUDA_VERSION_SHORT is a mandatory define! Eg: 8.0-dev"
#endif

FROM cuda:__CUDA_VERSION_SHORT

#include "../../reusables/xgb-dev"
