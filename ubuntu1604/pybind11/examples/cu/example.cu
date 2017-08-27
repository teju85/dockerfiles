#include <stdio.h>

__global__ void helloKernel() {
    printf("Hello world from GPU!\n");
}

void hello() {
    helloKernel<<<1,1>>>();
    cudaDeviceSynchronize();
}
