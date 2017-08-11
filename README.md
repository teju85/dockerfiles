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

# Running containers on these images
Use the 'scripts/launch' wrapper to do so. This wrapper has ability to:
1. Run as current user
2. Mount pwd as /work and set this as pwd in the container
For example, in order to run the pytorch container as current user and inside
it start a terminal:
```bash
$ ./scripts/launch -user pytorch:0.1.12 /bin/bash
```
The script will also print out the raw commandline it uses to launch such a
container to the terminal. If need be, one can also directly use this command.

Note: some of the ideas are inspired from ryanolson/luda (Thanks!).

# Pre-reqs
The main goal behind this setup is to have as minimal dependencies as possible.
That way, users can start with bare-minimal host OS installation and express
complexities inside their docker images.
* C pre-processor (to support '#include'ing dockerfiles for reusability!)
* python (for the wrapper to launch the containers. Basic install is sufficient)
* GNU-make
* docker
* gpu-enabled system (preferrably >= Maxwell arch)
* nvidia-docker
* latest cuda driver
