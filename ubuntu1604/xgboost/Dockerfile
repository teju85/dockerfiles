
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
        unzip && \
    pip install --upgrade pip && \
    pip install nose numpy scipy sklearn && \
    rm -rf /var/lib/apt/lists/*

RUN git config --global http.sslVerify false && \
    git clone --recursive https://github.com/teju85/xgboost && \
    mkdir -p xgboost/.gtest xgboost/.gtest/include xgboost/.gtest/lib && \
    cd xgboost/.gtest && \
    git clone https://github.com/google/googletest

RUN cd xgboost/.gtest/googletest/googletest && \
    g++ -Iinclude -I. -pthread -c src/gtest-all.cc -o ../../lib/gtest-all.o && \
    cd ../../lib && \
    ar -rv libgtest.a gtest-all.o && \
    cd ../ && \
    cp -r googletest/googletest/include/gtest include

RUN cd xgboost && \
    make PLUGIN_UPDATER_GPU=ON COMPUTE="60 61" GTEST_PATH=./.gtest -j4 && \
    make PLUGIN_UPDATER_GPU=ON COMPUTE="60 61" GTEST_PATH=./.gtest -j4 tests/cpp/xgboost_test && \ 
    cd python-package && \
    python setup.py install

CMD cd xgboost && \
    ./tests/cpp/xgboost_test && \
    cd plugin/updater_gpu && \
    python -m nose test/ && \
    python benchmark/benchmark.py --algorithm all
