
FROM cuda:8.0

#include "../../reusables/xgboost-install"

CMD cd xgboost/plugin/updater_gpu && \\
    python -m nose test/python/ && \\
    python benchmark/benchmark.py --algorithm all
