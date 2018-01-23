
#ifndef __CUDA_VERSION_SHORT
#define "__CUDA_VERSION_SHORT is a mandatory define! Eg: 8.0"
#endif

#define BASE_TAG __CUDA_VERSION_SHORT"-dev"
FROM cuda:BASE_TAG

// always pick from dmlc (the main repo)
#define XGB_REPO "dmlc/xgboost"
#include "../../reusables/xgboost-install"
#include "../../reusables/catboost-install"
#include "../../reusables/lightgbm-install"

// TODO:
//  . install extra dependencies for the comparison library
//  . clone and install the comparison library
