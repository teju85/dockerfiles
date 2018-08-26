FROM cuda:9.2-dev

#include "../../reusables/cmake-build"
#include "../../reusables/ssh"
#include "../../reusables/python-dev-2.7"

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        gzip \\
        tar \\
        unzip \\
        zlib1g-dev && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists
