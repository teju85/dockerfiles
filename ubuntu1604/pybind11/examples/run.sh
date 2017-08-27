#!/bin/bash

echo "--------------------------------"
cd $PYBIND11/examples/cpp && \
    make lib && \
    python test.py && \
    make clean
echo "--------------------------------"
cd $PYBIND11/examples/cu && \
    make lib && \
    python test.py && \
    make clean
echo "--------------------------------"
