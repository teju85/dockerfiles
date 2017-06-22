FROM python:2.7

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential && \
    rm -rf /var/lib/apt/lists/*

RUN pip install --upgrade pip && \
    pip install --no-cache-dir \
        ipython[all] \
        jupyter \
        matplotlib \
        numpy \
        pandas \
        scikit-learn
