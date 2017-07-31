# Intro
All dockerfiles that I created for various learning/work purposes.
In order to build images, first go to the relevant base image version
and then just use the Makefile inside that folder.

## Example
Currently, the only supported docker base image is from Ubuntu 16.04.
If you want to setup a cuda SDK v8.0 image on your system:
```bash
$ cd ubuntu1604
$ make cuda80
```
Just typing a 'make' with no targets will print usage info. Check it out
to know other images which can be built using this flow.

# Pre-reqs
The main goal behind this setup is to have as minimal dependencies as possible.
That way, users can start with bare-minimal host OS installation and express
complexities inside their docker images.
* C pre-processor (to support '#include'ing dockerfiles for reusability!)
* GNU-make
* docker
* gpu-enabled system (preferrably >= Maxwell arch)
* nvidia-docker
* latest cuda driver
