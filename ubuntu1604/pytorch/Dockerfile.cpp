FROM cudnn:6.0

ARG port=8888

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        build-essential \\
        cmake \\
        git \\
        curl \\
        ca-certificates \\
        libjpeg-dev \\
        libpng-dev \\
        curl \\
        wget && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists

RUN curl -o /miniconda.sh -O "https://repo.continuum.io/miniconda/Miniconda3-4.2.12-Linux-x86_64.sh" && \\
    chmod +x /miniconda.sh && \\
    /miniconda.sh -b -p /opt/conda && \\
    rm /miniconda.sh && \\
    git clone "https://github.com/pytorch/pytorch" /opt/pytorch

ENV PATH /opt/conda/bin:$PATH
WORKDIR /opt/pytorch

RUN conda install \\
        conda-build \\
        python=3.5.2 \\
        ipython \\
        jupyter \\
        matplotlib \\
        mkl \\
        numpy \\
        pandas \\
        pyyaml \\
        scikit-learn \\
        scipy \\
        urllib3 && \\
    conda install -c soumith magma-cuda80 && \\
    conda clean -ya

RUN cd /opt/pytorch && \\
    TORCH_CUDA_ARCH_LIST="3.5 5.2 6.0 6.1+PTX" \\
        TORCH_NVCC_FLAGS="-Xfatbin -compress-all" \\
        pip install -v .

COPY contexts/jupyter.sh /jupyter.sh
#include "../../reusables/runas"

EXPOSE $port
ENV NB_PORT $port
CMD ["/jupyter.sh"]
