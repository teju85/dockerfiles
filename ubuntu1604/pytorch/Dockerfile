FROM cudnn:6.0

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
        git \
        ca-certificates \
        libjpeg-dev \
        libpng-dev \
        curl \
        python-dev \
        python-pip \
        python-setuptools \
        wget

RUN curl -o miniconda.sh -O  https://repo.continuum.io/miniconda/Miniconda3-4.2.12-Linux-x86_64.sh  && \
    chmod +x miniconda.sh && \
    ./miniconda.sh -b -p /opt/conda && \     
    rm miniconda.sh && \
    /opt/conda/bin/conda install conda-build && \
    /opt/conda/bin/conda create -y --name pytorch-py35 python=3.5.2 numpy pyyaml scipy ipython mkl && \
    /opt/conda/bin/conda clean -ya 

# install optional dependencies
ENV PATH=/opt/conda/bin:$PATH
ENV CMAKE_PREFIX_PATH=/opt/conda
RUN conda install numpy pyyaml mkl setuptools cmake gcc cffi

ENV PATH /opt/conda/envs/pytorch-py35/bin:$PATH

RUN conda install --name pytorch-py35 -c soumith magma-cuda80

RUN git clone https://github.com/pytorch/pytorch /opt/pytorch && \
    cd /opt/pytorch && \
    TORCH_CUDA_ARCH_LIST="3.5 5.2 6.0 6.1+PTX" \
        TORCH_NVCC_FLAGS="-Xfatbin -compress-all" \
        pip install -v .

WORKDIR /workspace
RUN chmod -R a+w /workspace
