#!/bin/bash
# Assumption:
#   /work volume mount contains the 'fairseq-py' github local repo!

cp -r /work/fairseq-py /opt

export INTEXT=/opt/fairseq-py/data/iwslt14.tokenized.de-en
export OUTTEXT=/opt/fairseq-py/data-bin/iwslt14.tokenized.de-en

cd /opt/fairseq-py &&
    pip install --no-cache-dir -r requirements.txt &&
    python setup.py build &&
    python setup.py develop &&
    cd data &&
    bash ./prepare-iwslt14.sh &&
    cd .. &&
    python preprocess.py --source-lang de --target-lang en \
           --trainpref $INTEXT/train --validpref $INTEXT/valid \
           --testpref $INTEXT/test --thresholdtgt 3 --thresholdsrc 3 \
           --destdir $OUTTEXT
