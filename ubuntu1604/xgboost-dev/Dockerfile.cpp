
// The assumption with this dockerfile is that one has to volume-mount
// the directory that contains a 'git clone --recursive'd xgboost repo
// and the build/test commands will be done through the nvidia-docker
// container that runs this image!!
//
// Sample container launch command should be:
// nvidia-docker run --rm -ti -v /host/xgboost/path:/xgboost:rw xgboost-dev:latest /bin/bash
//
// After this, inside this container, the usual xgboost build and test
// commands can be executed

FROM cuda:8.0

#include "../../reusables/pyml-env-2.7"

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        git \\
        make \\
        tar \\
        unzip \\
        wget && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists

RUN wget "https://cmake.org/files/v3.8/cmake-3.8.2.tar.gz" && \\
    tar xf cmake-3.8.2.tar.gz && \\
    cd cmake-3.8.2 && \\
    ./bootstrap && \\
    make && \\
    make install && \\
    cd .. && \\
    rm -rf cmake-3.8.2.tar.gz cmake-3.8.2

VOLUME ["/xgboost"]
