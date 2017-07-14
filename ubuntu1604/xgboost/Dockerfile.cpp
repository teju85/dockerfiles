
FROM cuda:8.0

#include "../../reusables/xgb-dev"

ARG arch=35;50;52;60;61

RUN git config --global http.sslVerify false && \\
    git clone --recursive "https://github.com/teju85/xgboost"

RUN cd xgboost && \\
    mkdir build && \\
    cd build && \\
    cmake .. -DGPU_COMPUTE_VER=$arch -DPLUGIN_UPDATER_GPU=ON && \\
    make && \\
    cd ../python-package && \\
    python setup.py install

CMD cd xgboost/plugin/updater_gpu && \\
    python -m nose test/python/ && \\
    python benchmark/benchmark.py --algorithm all
