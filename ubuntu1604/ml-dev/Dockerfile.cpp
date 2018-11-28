FROM rapids:latest-9.2

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
