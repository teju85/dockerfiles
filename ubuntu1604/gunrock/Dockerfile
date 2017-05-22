FROM cuda:8.0

# install boost
RUN apt-get update && apt-get install -y --no-install-recommends wget libbz2-dev && \
    wget --no-check-certificate 'https://versaweb.dl.sourceforge.net/project/boost/boost/1.58.0/boost_1_58_0.tar.gz' && \
    tar xf boost_1_58_0.tar.gz && \
    cd boost_1_58_0 && ./bootstrap.sh && ./bjam && ./bjam install && \
    cd .. && rm -rf boost_1_58_0 && rm boost_1_58_0.tar.gz && \
    rm -rf /var/lib/apt/lists/*

# install gunrock
RUN apt-get update && apt-get install -y --no-install-recommends git cmake && \
    git config --global http.sslVerify false && \
    git clone --recursive https://github.com/gunrock/gunrock && \
    cd gunrock && mkdir build && cd build && \
    cmake .. -DGUNROCK_GENCODE_SM60=ON -DGUNROCK_GENCODE_SM30=OFF && make && \
    rm -rf /var/lib/apt/lists/*

# download large datasets as well for benchmarking
RUN apt-get update && apt-get install -y --no-install-recommends unzip && \
    cd gunrock/dataset/large && make WGET="wget --no-check-certificate" TOPC && \
    rm -rf /var/lib/apt/lists/*

