
// The assumption with this dockerfile is that one has to volume-mount
// the directory that contains a 'git clone --recursive'd xgboost repo
// and the build/test commands will be done through the nvidia-docker
// container running on this image!!
//
// Then use the scripts/xgb-dev.sh to launch a container on this image
//
// After this, inside this container, the usual xgboost build and test
// commands can be executed

FROM cuda:8.0

#include "../../reusables/xgb-dev"
VOLUME ["/xgboost"]
#include "../../reusables/runas"
#include "../../reusables/vnc"
