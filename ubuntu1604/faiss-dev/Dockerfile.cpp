
#ifndef __CUDA_VERSION_SHORT
#define "__CUDA_VERSION_SHORT is a mandatory define! Eg: 8.0-dev"
#endif

#define BASE_TAG __CUDA_VERSION_SHORT
FROM cuda:BASE_TAG

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        build-essential \\
        cmake \\
        curl \\
        git \\
        libopenblas-base \\
        libopenblas-dev \\
        python3-dev \\
        python3-numpy \\
        python3-pip \\
        python3-setuptools \\
        swig \\
        wget && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists

RUN pip3 install --no-cache-dir \\
    matplotlib

RUN ln -s /usr/bin/python3 /usr/bin/python && \\
    ln -s /usr/bin/python3-config /usr/bin/python-config

ENV BLASLDFLAGS /usr/lib/libopenblas.so.0

RUN mkdir /opt/faiss

COPY build /opt/faiss
COPY benchmark /opt/faiss
COPY clean /opt/faiss
COPY makefile.inc,in /opt/faiss
COPY sift1m.py /opt/faiss

RUN chmod 0777 -R /opt/faiss

#include "../../reusables/ssh"
