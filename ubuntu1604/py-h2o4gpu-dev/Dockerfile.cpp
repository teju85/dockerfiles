
#ifndef __CUDA_VERSION_SHORT
#error "__CUDA_VERSION_SHORT is a mandatory define! Eg: 8.0-dev"
#endif

#define BASE_TAG __CUDA_VERSION_SHORT
FROM cuda:BASE_TAG

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        apt-utils \\
        build-essential \\
        cpio \\
        curl \\
        dirmngr \\
        git \\
        iputils-ping \\
        libbz2-dev \\
        libncursesw5-dev \\
        libncurses5-dev \\
        libopenblas-dev \\
        libreadline-dev \\
        libsqlite3-dev \\
        libssl-dev \\
        llvm \\
        make \\
        net-tools \\
        pbzip2 \\
        python3 \\
        python3-dev \\
        python3-software-properties \\
        python3-dateutil \\
        python3-magic \\
        python3-pip \\
        software-properties-common \\
        swig \\
        tk-dev \\
        virtualenv \\
        wget \\
        xz-utils \\
        zip \\
        zlib1g-dev && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists && \\
    wget "http://launchpadlibrarian.net/326935544/s3cmd_2.0.0-1_all.deb" && \\
    dpkg -i s3cmd_2.0.0-1_all.deb && \\
    curl -sL "https://deb.nodesource.com/setup_7.x" | bash -

RUN virtualenv --python=python3.5 /opt/.venv && \\
    chmod 0777 -R /opt/.venv && \\
    . /opt/.venv/bin/activate && \\
    pip install --no-cache-dir setuptools

#include "../../reusables/pyml-env"
#include "../../reusables/jupyter"
#include "../../reusables/ssh"
