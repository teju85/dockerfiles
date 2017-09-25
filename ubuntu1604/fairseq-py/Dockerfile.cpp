FROM cudnn:6.0

#define PT_COMMIT_ID a03e5cb40938b6b3f3e6dbddf9cff8afdff72d1b
#include "../../reusables/pytorch"
#include "../../reusables/jupyter"

RUN git clone "https://github.com/facebookresearch/fairseq-py" /opt/fairseq-py

RUN cd /opt/fairseq-py && \\
    pip install --no-cache-dir -r requirements.txt && \\
    LANG=C.UTF-8 python setup.py build && \\
    LANG=C.UTF-8 python setup.py develop

RUN cd /opt/fairseq-py/data && \\
    bash ./prepare-iwslt14.sh && \\
    cd .. && \\
    export INTEXT=data/iwslt14.tokenized.de-en && \\
    export OUTTEXT=data-bin/iwslt14.tokenized.de-en && \\
    export LANG=C.UTF-8 && \\
    python preprocess.py --source-lang de --target-lang en \\
        --trainpref $INTEXT/train --validpref $INTEXT/valid \\
        --testpref $INTEXT/test --thresholdtgt 3 --thresholdsrc 3 \\
        --destdir $OUTTEXT

WORKDIR /opt/fairseq-py
