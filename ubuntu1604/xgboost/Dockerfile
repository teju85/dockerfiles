
FROM xgboost-dev:latest

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
