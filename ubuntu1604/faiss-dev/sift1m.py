# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD+Patents license found in the
# LICENSE file in the root directory of this source tree.

#!/usr/bin/env python

import os
import time
import numpy as np
import pdb

import faiss

#################################################################
# I/O functions
#################################################################

def ivecs_read(fname):
    a = np.fromfile(fname, dtype='int32')
    d = a[0]
    return a.reshape(-1, d + 1)[:, 1:].copy()

def fvecs_read(fname):
    return ivecs_read(fname).view('float32')


#################################################################
#  Main program
#################################################################

print("load data")

xt = fvecs_read("sift1M/sift_learn.fvecs")
xb = fvecs_read("sift1M/sift_base.fvecs")
xq = fvecs_read("sift1M/sift_query.fvecs")

nq, d = xq.shape

print("load GT")
gt = ivecs_read("sift1M/sift_groundtruth.ivecs")

# gpu selection
# TODO: how to link this to the exact knn call below!?
ngpu = 1
gpu_resources = []
for i in range(ngpu):
    res = faiss.StandardGpuResources()
    gpu_resources.append(res)

def make_vres_vdev(i0=0, i1=-1):
    " return vectors of device ids and resources useful for gpu_multiple"
    vres = faiss.GpuResourcesVector()
    vdev = faiss.IntVector()
    if i1 == -1:
        i1 = ngpu
    for i in range(i0, i1):
        vdev.push_back(i)
        vres.push_back(gpu_resources[i])
    return vres, vdev

# we need only a StandardGpuResources per GPU
res = faiss.StandardGpuResources()


#################################################################
#  Exact search experiment
#################################################################

print("============ Exact search")

flat_config = faiss.GpuIndexFlatConfig()
flat_config.device = 0

index = faiss.GpuIndexFlatL2(res, d, flat_config)

print("add vectors to index")

index.add(xb)

print("warmup")

index.search(xq, 123)

print("benchmark")

for lk in range(11):
    k = 1 << lk
    t0 = time.time()
    D, I = index.search(xq, k)
    t1 = time.time()

    # the recall should be 1 at all times
    recall_at_1 = (I[:, :1] == gt[:, :1]).sum() / float(nq)
    print("k=%d %.3f s, R@1 %.4f" % (k, t1 - t0, recall_at_1))
