
#ifndef __CUDNN_VERSION_TAG
#error "__CUDNN_VERSION_TAG is a mandatory define! Eg: 8.0-6.0.21"
#endif

#define BASE_TAG __CUDNN_VERSION_TAG"-dev"
FROM cudnn:BASE_TAG

#include "../../reusables/pytorch"
#include "../../reusables/jupyter"
