
#ifndef __PYTORCH_VERSION_TAG
#error "__PYTORCH_VERSION_TAG is a mandatory define! Eg: latest-90_70"
#endif

#define BASE_TAG __PYTORCH_VERSION_TAG
FROM pytorch:BASE_TAG


RUN pip install --upgrade pip && \\
    pip install --no-cache-dir \\
        dominate \\
        visdom

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        unzip && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists

// for visdom
EXPOSE 8097
