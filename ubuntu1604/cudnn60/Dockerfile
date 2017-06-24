FROM cuda:8.0

# shamelessly copied over from nvidia's dockerfiles on github!

# cudnn 6.0 runtime and devel
RUN apt-get update && \
    apt-get install -y --no-install-recommends curl && \
    rm -rf /var/lib/apt/lists/*
ENV CUDNN_VERSION 6.0.21
RUN CUDNN_DOWNLOAD_SUM=9b09110af48c9a4d7b6344eb4b3e344daa84987ed6177d5c44319732f3bb7f9c && \
    curl -fsSL http://developer.download.nvidia.com/compute/redist/cudnn/v6.0/cudnn-8.0-linux-x64-v6.0.tgz -O && \
    echo "$CUDNN_DOWNLOAD_SUM  cudnn-8.0-linux-x64-v6.0.tgz" | sha256sum -c --strict - && \
    tar -xzf cudnn-8.0-linux-x64-v6.0.tgz -C /usr/local && \
    rm cudnn-8.0-linux-x64-v6.0.tgz && \
    ldconfig
