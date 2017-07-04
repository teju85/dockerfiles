FROM cudnn:6.0

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        autoconf \
        automake \
        bzip2 \
        g++ \
        git \
        libatlas3-base \
        libtool-bin \
        make \
        python2.7 \
        subversion \
        wget \
        zlib1g-dev && \
    rm -rf /var/lib/apt/lists/*

RUN git config --global http.sslVerify false && \
    git clone https://github.com/kaldi-asr/kaldi

RUN ln -s /usr/bin/python2.7 /usr/bin/python && \
    cd kaldi/tools && \
    ./extras/check_dependencies.sh && \
    make -j8 && \
    cd ../src && \
    ./configure --shared && \
    make depend && \
    make -j8
