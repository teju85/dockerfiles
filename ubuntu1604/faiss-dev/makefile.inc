# -*- makefile -*-
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD+Patents license found in the
# LICENSE file in the root directory of this source tree.

# tested on CentOS 7, Ubuntu 16 and Ubuntu 14, see below to adjust flags to distribution.


CXX          = g++ -std=c++11
CXXCPP       = g++ -std=c++11 -E
# NOTE: Change to `-DFINTEGER=long` if using MKL.
# TODO: Investigate the LAPACKE wrapper for LAPACK, which defines the correct
#   type for FORTRAN integers.
CPPFLAGS     = -DFINTEGER=int
CXXFLAGS     = -fPIC -fopenmp -m64 -Wno-sign-compare -O3 -Wall -Wextra
CXXFLAGS    += -I$(includedir) $(CUDACFLAGS)
CPUFLAGS     = -mavx -msse4 -mpopcnt
LDFLAGS      = -fPIC -fopenmp
LIBS         = -lblas -L/usr/lib/openblas-base -llapack
PYTHONCFLAGS = -I/usr/include/python2.7 -I/usr/include/x86_64-linux-gnu/python2.7 -I/usr/lib/python2.7/dist-packages/numpy/core/include
PYTHONLIB    = -lpython

CUDAROOT     = /usr/local/cuda
NVCC         = $(CUDAROOT)/bin/nvcc
NVCCLDFLAGS  = -L$(CUDAROOT)/lib64
NVCCLIBS     = -lcudart -lcublas -lcuda
CUDACFLAGS   = -I$(CUDAROOT)/include
NVCCFLAGS    = -I $(CUDAROOT)/targets/x86_64-linux/include/ \
	       -Xcompiler -fPIC \
	       -Xcudafe --diag_suppress=unrecognized_attribute \
	       -gencode arch=compute_35,code="compute_35" \
	       -gencode arch=compute_52,code="compute_52" \
	       -gencode arch=compute_60,code="compute_60" \
	       -gencode arch=compute_61,code="compute_61" \
	       -gencode arch=compute_70,code="compute_70" \
	       -lineinfo \
	       -ccbin $(CXX) -DFAISS_USE_FLOAT16

OS = $(shell uname -s)

# common linux flags
SHAREDEXT    = so
SHAREDFLAGS  = -shared
MKDIR_P      = mkdir -p
PYTHON       = python
SWIG         = swig

ifeq ($(OS),Darwin)
	SHAREDEXT   = dylib
	SHAREDFLAGS = -dynamiclib -undefined dynamic_lookup
endif

prefix      ?= /usr/local
exec_prefix ?= ${prefix}
libdir       = ${exec_prefix}/lib
includedir   = ${prefix}/include
