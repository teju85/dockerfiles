FROM cuda:9.2-dev

#include "../../reusables/nccl"

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        make \\
        tar \\
        wget && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists

#include "../../reusables/openmpi"
#include "../../reusables/ssh"

RUN ldconfig && \\
    git clone "https://github.com/teju85/nccl-bench" /opt/nccl-bench && \   \
    cd /opt/nccl-bench && \\
    MPICXX=/usr/local/bin/mpiCC make build
