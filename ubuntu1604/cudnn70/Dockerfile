FROM cuda:9.0-dev

# shamelessly copied over from nvidia's dockerfiles on github!

# cudnn 7.0 runtime and devel
RUN apt-get update && \
    apt-get install -y --no-install-recommends curl && \
    rm -rf /var/lib/apt/lists/*
ENV CUDNN_VERSION 7.0.5
RUN CUDNN_DOWNLOAD_SUM=1a3e076447d5b9860c73d9bebe7087ffcb7b0c8814fd1e506096435a2ad9ab0e && \
    curl -fsSL http://developer.download.nvidia.com/compute/redist/cudnn/v7.0.5/cudnn-9.0-linux-x64-v7.tgz -O && \
    echo "$CUDNN_DOWNLOAD_SUM  cudnn-9.0-linux-x64-v7.tgz" | sha256sum -c --strict - && \
    tar -xzf cudnn-9.0-linux-x64-v7.tgz -C /usr/local && \
    rm cudnn-9.0-linux-x64-v7.tgz && \
    ldconfig
