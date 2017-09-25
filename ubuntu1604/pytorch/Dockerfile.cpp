FROM cudnn:6.0

ARG port=8888

#include "../../reusables/pytorch"
WORKDIR /opt/pytorch

COPY contexts/jupyter.sh /jupyter.sh
EXPOSE $port
ENV NBPORT $port
CMD /jupyter.sh
