FROM cudnn:6.0

#define PT_COMMIT_ID a03e5cb40938b6b3f3e6dbddf9cff8afdff72d1b
#include "../../reusables/pytorch"
#include "../../reusables/jupyter"

RUN git clone "https://github.com/facebookresearch/fairseq-py" /opt/fairseq-py

RUN cd /opt/fairseq-py && \\
    pip install --no-cache-dir -r requirements.txt && \\
    grep -v Pourquoi README.md > README.md.bak && \\
    mv README.md.bak README.md && \\
    python setup.py build && \\
    python setup.py develop

WORKDIR /opt/fairseq-py
