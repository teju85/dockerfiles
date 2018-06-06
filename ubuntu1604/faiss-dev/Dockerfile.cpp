FROM cuda:9.1-dev

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        build-essential \\
        cmake \\
        curl \\
        git \\
        libopenblas-base \\
        libopenblas-dev \\
        python-dev \\
        python-numpy \\
        python-pip \\
        python-setuptools \\
        swig \\
        wget && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists

RUN pip install --no-cache-dir \\
    matplotlib

ENV BLASLDFLAGS /usr/lib/libopenblas.so.0

RUN mkdir /opt/faiss

COPY build /opt/faiss
COPY clean /opt/faiss
COPY makefile.inc /opt/faiss

RUN chmod 0777 -R /opt/faiss

#include "../../reusables/ssh"
