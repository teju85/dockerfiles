FROM cudnn:6.0

#define PT_COMMIT_ID a03e5cb40938b6b3f3e6dbddf9cff8afdff72d1b
#define EXTRA_TORCH_FLAGS NO_DISTRIBUTED=1
#include "../../reusables/pytorch"

#include "../../reusables/jupyter"

RUN git clone "https://github.com/facebookresearch/fairseq-py" /opt/fairseq-py

ENV LANG=C.UTF-8
ENV INTEXT=/opt/fairseq-py/data/iwslt14.tokenized.de-en
ENV OUTTEXT=/opt/fairseq-py/data-bin/iwslt14.tokenized.de-en

RUN cd /opt/fairseq-py && \\
    pip install --no-cache-dir -r requirements.txt && \\
    python setup.py build && \\
    python setup.py develop

RUN cd /opt/fairseq-py/data && \\
    bash ./prepare-iwslt14.sh && \\
    cd .. && \\
    python preprocess.py --source-lang de --target-lang en \\
        --trainpref $INTEXT/train --validpref $INTEXT/valid \\
        --testpref $INTEXT/test --thresholdtgt 3 --thresholdsrc 3 \\
        --destdir $OUTTEXT

WORKDIR /opt/fairseq-py
