
#ifndef __CUDA_VERSION_SHORT
#define "__CUDA_VERSION_SHORT is a mandatory define! Eg: 8.0"
#endif

#define BASE_TAG __CUDA_VERSION_SHORT"-dev"
FROM cuda:BASE_TAG

#include "../../reusables/rapids"
#include "../../reusables/jupyter"
#include "../../reusables/ssh"

RUN conda install cudatoolkit && conda clean -ya
