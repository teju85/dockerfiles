
FROM cuda:8.0

RUN apt-get update && apt-get install -y --no-install-recommends \
        wget \
        libbz2-dev \
        git \
        python-pip \
        python-dev \
        python-setuptools \
        libblas-dev \
        liblapack-dev \
        tar \
        unzip && \
    pip install --upgrade pip && \
    pip install nose numpy scipy sklearn && \
    rm -rf /var/lib/apt/lists/*

RUN wget https://cmake.org/files/v3.8/cmake-3.8.2.tar.gz && \
    tar xf cmake-3.8.2.tar.gz && \
    cd cmake-3.8.2 && \
    ./bootstrap && \
    make && \
    make install && \
    cd .. && \
    rm -rf cmake-3.8.2.tar.gz cmake-3.8.2

RUN git config --global http.sslVerify false && \
    git clone --recursive https://github.com/teju85/xgboost

RUN cd xgboost && \
    mkdir build && \
    cd build && \
    cmake .. -DCUDA_ARCH_NAME=Pascal -DPLUGIN_UPDATER_GPU=ON && \
    make && \
    cd ../python-package && \
    python setup.py install

CMD cd xgboost/plugin/updater_gpu && \
    python -m nose test/python/ && \
    python benchmark/benchmark.py --algorithm all
