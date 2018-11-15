FROM cuda:10.0-dev

#include "../../reusables/cmake-build"
#include "../../reusables/ssh"
#include "../../reusables/conda-ml-env"

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
