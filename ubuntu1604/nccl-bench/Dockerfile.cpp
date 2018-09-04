FROM cuda:9.2-dev

#include "../../reusables/nccl"

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        make && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists
