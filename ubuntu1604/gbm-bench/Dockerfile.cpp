
#ifndef __CUDA_VERSION_SHORT
#define "__CUDA_VERSION_SHORT is a mandatory define! Eg: 8.0"
#endif

#define BASE_TAG __CUDA_VERSION_SHORT"-dev"
FROM cuda:BASE_TAG

#include "../../reusables/lightgbm-install"
#include "../../reusables/catboost-install"
// always pick from dmlc (the main repo)
#define XGB_REPO "dmlc/xgboost"
#include "../../reusables/xgboost-install"
#include "../../reusables/dask-xgboost"
#include "../../reusables/libgdf"

// TODO:
//  . install extra dependencies for the comparison library
//  . clone and install the comparison library
