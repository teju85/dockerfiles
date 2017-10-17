FROM cudnn:6.0

#define PT_COMMIT_ID a03e5cb40938b6b3f3e6dbddf9cff8afdff72d1b
#define EXTRA_TORCH_FLAGS NO_DISTRIBUTED=1
#include "../../reusables/pytorch"

#include "../../reusables/jupyter"

ENV LANG=C.UTF-8
COPY setup.sh /setup.sh
