
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
        python-setuptools \\
        python-software-properties \\
        python3-dateutil \\
        python3-magic \\
        software-properties-common \\
        swig \\
        tk-dev \\
        wget \\
        xz-utils \\
        zip \\
        zlib1g-dev && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists && \\
    wget "http://launchpadlibrarian.net/326935544/s3cmd_2.0.0-1_all.deb" && \\
    dpkg -i s3cmd_2.0.0-1_all.deb && \\
    curl -sL "https://deb.nodesource.com/setup_7.x" | bash -

#include "../../reusables/pyml-env"
RUN pip3 install --no-cache-dir \\
        apipkg \\
        attrs \\
        awscli \\
        cmake \\
        coverage \\
        Cython \\
        execnet \\
        feather-format \\
        future \\
        h2o \\
        ipykernel \\
        ipython \\
        ipython-genutils \\
        ipywidgets \\
        jupyter \\
        jupyter-client \\
        jupyter-console \\
        jupyter-core \\
        llvmlite \\
        matplotlib \\
        nbconvert \\
        nbformat \\
        notebook \\
        numba \\
        numpy \\
        pandas \\
        pillow \\
        pluggy \\
        psutil \\
        py \\
        pylint \\
        pytest \\
        pytest-forked \\
        pytest-xdist \\
        pytest-cov \\
        python-dateutil \\
        pytz \\
        scikit-learn \\
        scipy \\
        seaborn \\
        six \\
        sklearn \\
        sphinx \\
        sphinx_rtd_theme \\
        tabulate \\
        wheel \\
        yapf

#include "../../reusables/jupyter"
#include "../../reusables/ssh"
