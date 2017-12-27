
// define's expected
// . __CUDA_VERSION_SHORT (cudnn version can be built with a specific sdk)

FROM cuda:__CUDA_VERSION_SHORT

#include "../../reusables/cudnn-dev"
