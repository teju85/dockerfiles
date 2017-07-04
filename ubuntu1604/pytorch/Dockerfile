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
        wget && \
    rm -rf /var/lib/apt/lists/*

RUN curl -o miniconda.sh -O  https://repo.continuum.io/miniconda/Miniconda3-4.2.12-Linux-x86_64.sh  && \
    chmod +x miniconda.sh && \
    ./miniconda.sh -b -p /opt/conda && \
    rm miniconda.sh

ENV PATH=/opt/conda/bin:$PATH
ENV CMAKE_PREFIX_PATH=/opt/conda
ENV PATH /opt/conda/envs/pytorch-py35/bin:$PATH

RUN conda install conda-build && \
    conda create --name pytorch-py35 && \
    conda install --name pytorch-py35 \
        cffi \
        cmake \
        gcc \
        ipython \
        jupyter \
        matplotlib \
        mkl \
        numpy \
        pandas \
        python=3.5.2 \
        py-xgboost \
        pyyaml \
        scikit-learn \
        scipy \
        setuptools \
        urllib3 && \
    conda install --name pytorch-py35 -c creditx scikit-optimize && \
    conda install --name pytorch-py35 -c soumith magma-cuda80 && \
    conda clean -ya

RUN git clone https://github.com/pytorch/pytorch /opt/pytorch && \
    cd /opt/pytorch && \
    TORCH_CUDA_ARCH_LIST="3.5 5.2 6.0 6.1+PTX" \
        TORCH_NVCC_FLAGS="-Xfatbin -compress-all" \
        pip install -v .

WORKDIR /workspace
RUN chmod -R a+w /workspace

# Add a notebook profile.
RUN mkdir -p -m 700 /root/.jupyter/ && \
    echo "c.NotebookApp.ip = '*'" >> /root/.jupyter/jupyter_notebook_config.py

EXPOSE 8888
CMD jupyter notebook --allow-root --no-browser
