FROM cuda:8.0

#define XGB_REPO "dmlc"
#define XGB_COMMIT 0e06d1805d06fab063ee5f39563a6c6ad7510345
#include "../../reusables/xgboost-install"
#include "../../reusables/lightgbm-install"

// TODO:
//  . install extra dependencies for the comparison library
//  . clone and install the comparison library
