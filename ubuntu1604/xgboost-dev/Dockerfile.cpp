
// The assumption with this dockerfile is that one has to volume-mount
// the directory that contains a 'git clone --recursive'd xgboost repo
// and the build/test commands will be done through the nvidia-docker
// container that runs this image!!
//
// Sample container launch command should be:
// nvidia-docker run --rm -ti -v /host/xgboost/path:/xgboost:rw xgboost-dev:latest /bin/bash
//
// After this, inside this container, the usual xgboost build and test
// commands can be executed

FROM cuda:8.0

#include "../../reusables/xgb-dev"

VOLUME ["/xgboost"]
