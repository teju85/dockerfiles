FROM cudnn:6.0

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
        git \
        wget \
        libatlas-base-dev \
        libboost-all-dev \
        libgflags-dev \
        libgoogle-glog-dev \
        libhdf5-serial-dev \
        libleveldb-dev \
        liblmdb-dev \
        libopenblas-dev \
        libopencv-dev \
        libprotobuf-dev \
        libsnappy-dev \
        protobuf-compiler \
        python-dev \
        python-numpy \
        python-pip \
        python-setuptools \
        python-scipy && \
    rm -rf /var/lib/apt/lists/*

ENV CAFFE_ROOT /caffe

RUN git clone https://github.com/NVIDIA/caffe && \
    pip install --upgrade pip && \
    cd $CAFFE_ROOT/python && \
    for req in $(cat requirements.txt) pydot; do pip install $req; done

COPY Makefile.config $CAFFE_ROOT/Makefile.config

# TODO: -j option to make is causing wierd compilation failures!
RUN cd $CAFFE_ROOT && \
    make all && \
    make test && \
    make pycaffe && \
    echo "$CAFFE_ROOT/build/lib" >> /etc/ld.so.conf.d/caffe.conf && \
    ldconfig

# TODO: 'make runtest' somehow fails to find nvml lib!
# even tried nvidia-docker to build instead of just docker, but didn't help
#RUN cd $CAFFE_ROOT && \
#    make runtest

ENV PYCAFFE_ROOT $CAFFE_ROOT/python
ENV PYTHONPATH $PYCAFFE_ROOT:$PYTHONPATH
ENV PATH $CAFFE_ROOT/build/tools:$PYCAFFE_ROOT:$PATH

WORKDIR /
