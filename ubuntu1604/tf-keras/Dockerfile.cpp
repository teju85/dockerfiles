FROM cudnn:6.0

ARG port=8888

#include "../../reusables/pyml-env-2.7"

RUN pip install --upgrade pip && \\
    pip install --no-cache-dir \\
        keras

COPY contexts/jupyter.sh /jupyter.sh

EXPOSE $port
ENV NBPORT $port
CMD /jupyter.sh
