FROM cuda:9.2-dev

#include "../../reusables/cmake-build"
#include "../../reusables/ssh"


RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        zlib1g-dev && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists
