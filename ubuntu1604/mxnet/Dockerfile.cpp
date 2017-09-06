FROM cudnn:6.0

#include "../../reusables/pyml-env-2.7"

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        build-essential \\
        git \\
        libatlas-base-dev \\
        libopencv-dev && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists

RUN git clone --recursive "https://github.com/dmlc/mxnet" /mxnet && \\
    cd /mxnet && \\
    make -j2 \\
        USE_BLAS=atlas \\
        USE_CUDA=1 \\
        USE_CUDA_PATH=/usr/local/cuda \\
        USE_CUDNN=1 \\
        USE_OPENCV=1 \\
        USE_CPP_PACKAGE=1 \\
        USE_OPENMP=1

RUN git clone "https://github.com/NVIDIA/keras" /keras && \\
    cd /keras && \\
    python setup.py install

RUN cd /mxnet/python && \\
    python setup.py install

#include "../../reusables/jupyter"
