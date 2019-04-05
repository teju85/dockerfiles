
#ifndef __CUDA_VERSION_SHORT
#define "__CUDA_VERSION_SHORT is a mandatory define! Eg: 8.0"
#endif

#define BASE_TAG __CUDA_VERSION_SHORT"-dev"
FROM cuda:BASE_TAG

#include "../../reusables/cudf"
#include "../../reusables/cuml-dev"
#include "../../reusables/jupyter"
#include "../../reusables/ssh"

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        clang \\
        clang-format \\
        gzip \\
        libpthread-stubs0-dev \\
        tar \\
        unzip \\
        zlib1g-dev && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists

#define OPENMPI_DEV_BUILD
#include "../../reusables/openmpi"
