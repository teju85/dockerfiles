# Introduction
This is the development image for working with FAISS.
It currently hard-codes cuda v9.1 as its base image.

# Setup
```bash
$ git clone https://github.com/teju85/dockerfiles
$ cd dockerfiles/ubuntu1604
$ make faiss-dev92
$ cd ../..
$ git clone https://github.com/facebookresearch/faiss
```

# Build and runs
```bash
$ ./dockerfiles/scripts/launch -runas user faiss:dev-9.2 /bin/bash
# Building
container$ cd /work/faiss
container$ . /opt/faiss/clean
container$ . /opt/faiss/build
container$ export PYTHONPATH=`pwd`/python:$PYTHONPATH

# Running benchmarks
container$ mkdir -p tmp
# Replace with the below 2 lines inside faiss/demos/demo_auto_tune.py
# keys_to_test = keys_gpu
# use_gpu = True
container$ python demos/demo_auto_tune.py

# Running sift1M
container$ python benchs/bench_gpu_sift1m.py
```
