
#ifndef __PYTORCH_VERSION_TAG
#error "__PYTORCH_VERSION_TAG is a mandatory define! Eg: latest-90_70"
#endif

#define BASE_TAG __PYTORCH_VERSION_TAG
FROM pytorch:BASE_TAG

#include "../../reusables/visdom"

RUN mkdir -p /opt/conda/lib/python3.5/site-packages/visdom/static && \\
    chmod -R 0777 /opt/conda/lib/python3.5/site-packages/visdom/static

RUN pip install --no-cache-dir \\
        scikit-image

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        unzip && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists
