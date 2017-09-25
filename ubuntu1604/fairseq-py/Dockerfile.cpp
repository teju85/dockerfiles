FROM cudnn:6.0

ARG port=8888

#define PT_COMMIT_ID a03e5cb40938b6b3f3e6dbddf9cff8afdff72d1b
#include "../../reusables/pytorch"

RUN git clone "https://github.com/facebookresearch/fairseq-py" /opt/fairseq-py

RUN pip install -r requirements.txt && \\
    python setup.py build && \\
    python setup.py develop

WORKDIR /opt/fairseq-py

COPY contexts/jupyter.sh /jupyter.sh
EXPOSE $port
ENV NBPORT $port
CMD /jupyter.sh
