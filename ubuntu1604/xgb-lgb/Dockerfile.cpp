FROM cuda:8.0

#define XGB_REPO "dmlc"
#include "../../reusables/xgboost-install"
#include "../../reusables/lightgbm-install"
#include "../../reusables/runas"

// TODO:
//  . install extra dependencies for the comparison library
//  . clone and install the comparison library
