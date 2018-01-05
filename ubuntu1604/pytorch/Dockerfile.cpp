
#ifndef __CUDNN_VERSION_TAG
#error "__CUDNN_VERSION_TAG is a mandatory define! Eg: 8.0-6.0.21-dev"
#endif

#define BASE_TAG __CUDNN_VERSION_TAG
FROM cudnn:BASE_TAG

#include "../../reusables/pytorch"
#include "../../reusables/jupyter"
