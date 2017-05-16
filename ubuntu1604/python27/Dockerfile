
FROM ubuntu:16.04

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        python-pip \
        python-dev \
        python-setuptools && \
    pip install --upgrade pip && \
    rm -rf /var/lib/apt/lists/*
