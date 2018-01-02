
#ifndef __CUDA_VERSION_SHORT
#define "__CUDA_VERSION_SHORT is a mandatory define! Eg: 8.0"
#endif

#define BASE_TAG __CUDA_VERSION_SHORT"-dev"
FROM cuda:BASE_TAG

#include "../../reusables/xgboost-install"

CMD cd xgboost/plugin/updater_gpu && \\
    python -m nose test/python/ && \\
    python benchmark/benchmark.py --algorithm all
