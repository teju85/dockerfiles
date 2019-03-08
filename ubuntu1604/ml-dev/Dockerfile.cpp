
#ifndef __CUDA_VERSION_SHORT
#define "__CUDA_VERSION_SHORT is a mandatory define! Eg: 8.0"
#endif

#define BASE_TAG "latest-"__CUDA_VERSION_SHORT
FROM rapids:BASE_TAG

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

#include "../../reusables/openmpi"
