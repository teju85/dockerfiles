
SHARED      ?= example.so
CXX_SRCS    ?= 
CU_SRCS     ?= 
OBJS        := $(patsubst %.cpp,%.o,$(CXX_SRCS)) \
               $(patsubst %.cu,%.o,$(CU_SRCS))
INCLUDES    ?= -I$(PYBIND11)/include
PYFLAGS     ?= $(shell python-config --cflags)
CXX         := g++
CXXFLAGS    ?= -O3 -std=c++11 $(INCLUDES) $(PYFLAGS) -fPIC
LD          := g++
LDFLAGS     ?= -shared
LINKS       ?= $(shell python-config --ldflags)
ARCH        ?= 35 50 52 60 61
GENCODE     := $(foreach arch,$(ARCH),-gencode arch=compute_$(arch),code=sm_$(arch))
NVCC        := nvcc
NVCCFLAGS   ?= -lineinfo --std=c++11 $(INCLUDES) -Xcompiler="$(PYFLAGS) -fPIC" $(GENCODE)
NVCCLDFLAGS ?= $(LDFLAGS) $(GENCODE)


help:
	@echo "make what? Available targets are:"
	@echo "  . lib    - build the pybind11-integrated shared library"
	@echo "  . clean  - clean all the built files"

lib: $(SHARED)

ifeq (,$(CU_SRCS))
$(SHARED): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $< $(LINKER)
else
$(SHARED): $(OBJS)
	$(NVCC) $(NVCCLDFLAGS) -o $@ $^ $(LINKER)
endif

# this should come *before* all other rules to support CUDA compilation!
%.o: %.cu
	$(NVCC) $(NVCCFLAGS) -c -o $@ $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(SHARED)
