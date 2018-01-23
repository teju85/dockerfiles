
help:
	@echo "make what? Available targets are:"
	@echo "  cuda(80|90|91)"
	@echo "    cuda v8.0/v.9.0/v9.1 runtimes. These, in addition, come"
	@echo "    with 'runas' ability."
	@echo "  cuda(80|90|91)-dev"
	@echo "    cuda v8.0/v.9.0/v9.1 devels. These, in addition, come with"
	@echo "    'runas' ability."
	@echo "  cudnn(51|60|80_70|90_70)"
	@echo "    cudnn v5.1/v6.0/v7.0-with-v8.0/v7.0-with-9.0 runtimes."
	@echo "  cudnn(51|60|80_70|90_70)-dev"
	@echo "    cudnn v5.1/v6.0/v7.0-with-v8.0/v7.0-with-9.0 devels."
	@echo
	@echo "  pytorch(60|80_70|90_70)"
	@echo "    gpu enabled pytorch (with pyml-env). Some flags to customize"
	@echo "    behavior:"
	@echo "    . PT_PORT - Jupyter port to be exposed [$(PT_PORT)]"
	@echo
	@echo "  xgboost(80|90|91)"
	@echo "    install latest version of xgboost. Some flags to customize"
	@echo "    behavior:"
	@echo "    . XG_ARCH   - cuda arch(s) to build. [$(XG_ARCH)]"
	@echo "    . XG_COMMIT - commit ID to sync. [$(XG_COMMIT)]"
	@echo "    . XG_REPO   - repo to sync. [$(XG_REPO)]"
	@echo "  xgb-dev(80|90|91)"
	@echo "    install development env for xgboost. Assumes that user will"
	@echo "    mount xgboost repo while launching container on this image."
	@echo "  gbm(80|90|91)"
	@echo "    gbm benchmarking images. Some flags to customize behavior:"
	@echo "    . XG_ARCH        - cuda arch(s) to build. [$(XG_ARCH)]"
	@echo "    . GBM_XG_COMMIT  - xgboost commit ID. [$(GBM_XG_COMMIT)]"
	@echo "    . GBM_LG_COMMIT  - lightgbm commit ID. [$(GBM_LG_COMMIT)]"
	@echo "    . GBM_CAT_COMMIT - catboost commit ID. [$(GBM_CAT_COMMIT)]"
	@echo
	@echo "  . gunrock      latest version of gunrock from github"
	@echo "  . postgres     install latest version of postgres"
	@echo "  . tensorflow10 install tensorflow 1.0"
	@echo "  . kaldi        install kaldi framework (shared lib version)"
	@echo "  . nvcaffe      install nv-caffe and its dependencies"
	@echo "  . pix2pix      pytorch implementation of pix2pix and cycle-gan works"
	@echo "  . mxnet        gpu enabled mxnet + keras (on top of pyml-env libs)"
	@echo "                 Some flags to customize behavior:"
	@echo "                   MX_PORT - Jupyter port to be exposed [$(MX_PORT)]"
	@echo "  . tf-keras     tensorflow + keras (on top of pyml-env libs)"
	@echo "                 Some flags to customize behavior:"
	@echo "                   TF_PORT - Jupyter port to be exposed [$(TF_PORT)]"
	@echo "  . pybind11     install pybind11 env"
	@echo "  . fairseq-py   intall pytorch version of conv NMT from faceboook."
	@echo "                 Some flags to customize behavior:"
	@echo "                   FS_PORT - Jupyter port to be exposed [$(FS_PORT)]"
	@echo "  . fairseq-py-dev intall dev env for pytorch version of conv NMT from faceboook."
	@echo "                   Some flags to customize behavior:"
	@echo "                   FS_PORT - Jupyter port to be exposed [$(FS_PORT)]"


## helper targets begin ##
# for the below targets, the pwd has to be inside the directory containing Dockerfile.cpp!
.PHONY: genContext
genContext:
	cpp -o Dockerfile Dockerfile.cpp && \
	make -f ../Makefile genContextOnly

.PHONY: genContextOnly
genContextOnly:
	grep -v -e '^#' -e '^# ' -e '^$$' Dockerfile > tmp && \
	mv tmp Dockerfile && \
	rm -rf contexts && \
	cp -r ../../shared-contexts contexts

.PHONY: delContext
delContext:
	rm -rf contexts Dockerfile
## help targets end ##


## cuda env related targets begin ##
.PHONY: cuda
cuda:
	cd $@ && \
	cpp -o Dockerfile \
	    -D__CUDA_VERSION_FULL="$(__FULL)" \
	    -D__CUDA_VERSION_PKG="$(__PKG)" \
	    -D__CUDA_VERSION_SHORT="$(__SHORT)" \
	    Dockerfile.cpp && \
	make -f ../Makefile genContextOnly && \
	docker build -t cuda:$(__SHORT) . && \
	make -f ../Makefile delContext

.PHONY: cuda-dev
cuda-dev:
	cd $@ && \
	cpp -o Dockerfile \
	    -D__CUDA_VERSION_FULL="$(__FULL)" \
	    -D__CUDA_VERSION_PKG="$(__PKG)" \
	    -D__CUDA_VERSION_SHORT="$(__SHORT)" \
	    Dockerfile.cpp && \
	make -f ../Makefile genContextOnly && \
	docker build -t cuda:$(__SHORT)-dev . && \
	make -f ../Makefile delContext

.PHONY: cuda80
cuda80:
	$(MAKE) __FULL="8.0.61" __PKG="8-0=8.0.61-1" __SHORT="8.0" cuda

.PHONY: cuda80-dev
cuda80-dev:
	$(MAKE) __FULL="8.0.61" __PKG="8-0=8.0.61-1" __SHORT="8.0" cuda-dev

.PHONY: cuda90
cuda90:
	$(MAKE) __FULL="9.0.176" __PKG="9-0=9.0.176-1" __SHORT="9.0" cuda

.PHONY: cuda90-dev
cuda90-dev:
	$(MAKE) __FULL="9.0.176" __PKG="9-0=9.0.176-1" __SHORT="9.0" cuda-dev

.PHONY: cuda91
cuda91:
	$(MAKE) __FULL="9.1.85" __PKG="9-1=9.1.85-1" __SHORT="9.1" cuda

.PHONY: cuda91-dev
cuda91-dev:
	$(MAKE) __FULL="9.1.85" __PKG="9-1=9.1.85-1" __SHORT="9.1" cuda-dev
## cuda env related targets end ##


## cudnn env related core targets begin ##
.PHONY: cudnn
cudnn: cuda$(__CUDA_MINIFIED)
	cd $@ && \
	cpp -o Dockerfile \
	    -D__CUDA_VERSION_SHORT="$(__SHORT)" \
	    -D__CUDNN_VERSION="$(__CUDNN)" \
	    -D__CUDNN_VERSION_SHORT="$(__CUDNN_SHORT)" \
	    Dockerfile.cpp && \
	make -f ../Makefile genContextOnly && \
	docker build -t cudnn:$(__SHORT)-$(__CUDNN) . && \
	make -f ../Makefile delContext

.PHONY: cudnn-dev
cudnn-dev: cuda$(__CUDA_MINIFIED)-dev
	cd $@ && \
	cpp -o Dockerfile \
	    -D__CUDA_VERSION_SHORT="$(__SHORT)-dev" \
	    -D__CUDNN_VERSION="$(__CUDNN)" \
	    -D__CUDNN_VERSION_SHORT="$(__CUDNN_SHORT)" \
	    Dockerfile.cpp && \
	make -f ../Makefile genContextOnly && \
	docker build -t cudnn:$(__SHORT)-$(__CUDNN)-dev . && \
	make -f ../Makefile delContext
## cudnn env related core targets end ##


## cudnn with v8.0 env related targets end ##
.PHONY: cudnn51
cudnn51:
	$(MAKE) __CUDNN="5.1.10" __CUDNN_SHORT="5" __SHORT="8.0" __CUDA_MINIFIED="80" cudnn

.PHONY: cudnn60
cudnn60:
	$(MAKE) __CUDNN="6.0.21" __CUDNN_SHORT="6" __SHORT="8.0" __CUDA_MINIFIED="80" cudnn

.PHONY: cudnn80_70
cudnn80_70:
	$(MAKE) __CUDNN="7.0.5.15" __CUDNN_SHORT="7" __SHORT="8.0" __CUDA_MINIFIED="80" cudnn

.PHONY: cudnn51-dev
cudnn51-dev:
	$(MAKE) __CUDNN="5.1.10" __CUDNN_SHORT="5" __SHORT="8.0" __CUDA_MINIFIED="80" cudnn-dev

.PHONY: cudnn60-dev
cudnn60-dev:
	$(MAKE) __CUDNN="6.0.21" __CUDNN_SHORT="6" __SHORT="8.0" __CUDA_MINIFIED="80" cudnn-dev

.PHONY: cudnn80_70-dev
cudnn80_70-dev:
	$(MAKE) __CUDNN="7.0.5.15" __CUDNN_SHORT="7" __SHORT="8.0" __CUDA_MINIFIED="80" cudnn-dev
## cudnn with v8.0 env related targets end ##


## cudnn with v9.0 env related targets begin ##
.PHONY: cudnn90_70
cudnn90_70:
	$(MAKE) __CUDNN="7.0.5.15" __CUDNN_SHORT="7" __SHORT="9.0" __CUDA_MINIFIED="90" cudnn

.PHONY: cudnn90_70-dev
cudnn90_70-dev:
	$(MAKE) __CUDNN="7.0.5.15" __CUDNN_SHORT="7" __SHORT="9.0" __CUDA_MINIFIED="90" cudnn-dev
## cudnn with v9.0 env related targets end ##


## pytorch env's start ##
PT_PORT ?= 8888
.PHONY: pytorch
pytorch: cudnn$(__CUDNN_MINIFIED)-dev
	cd $@ && \
	cpp -o Dockerfile \
	    -D__CUDNN_VERSION_TAG="$(__CUDNN_TAG)-dev" \
	    Dockerfile.cpp && \
	make -f ../Makefile genContextOnly && \
	docker build -t pytorch:latest-$(__CUDNN_MINIFIED) \
	    --build-arg port=$(PT_PORT) . && \
	make -f ../Makefile delContext

.PHONY: pytorch60
pytorch60:
	$(MAKE) __CUDNN_MINIFIED="60" __CUDNN_TAG="8.0-6.0.21" pytorch

.PHONY: pytorch80_70
pytorch80_70:
	$(MAKE) __CUDNN_MINIFIED="80_70" __CUDNN_TAG="8.0-7.0.5.15" pytorch

.PHONY: pytorch90_70
pytorch90_70:
	$(MAKE) __CUDNN_MINIFIED="90_70" __CUDNN_TAG="9.0-7.0.5.15" pytorch
## pytorch env's end ##


## xgboost env's start ##
XG_ARCH   ?= 35;50;52;60;61
XG_COMMIT ?= 14c6392381c3b63996af4bd9bb13840dd20e78bf
XG_REPO   ?= "dmlc/xgboost"
.PHONY: xgboost
xgboost: cuda$(__CUDA_MINIFIED)-dev
	cd $@ && \
	cpp -o Dockerfile \
	    -D__CUDA_VERSION_SHORT="$(__SHORT)" \
	    -DXGB_REPO="$(XG_REPO)" \
	    -DXGB_ARCH="$(XG_ARCH)" \
	    -DXGB_COMMIT="$(XG_COMMIT)" \
	    Dockerfile.cpp && \
	make -f ../Makefile genContextOnly && \
	docker build -t xgboost:latest-$(__SHORT) . && \
	make -f ../Makefile delContext

.PHONY: xgb-dev
xgb-dev: cuda$(__CUDA_MINIFIED)-dev
	cd $@ && \
	cpp -o Dockerfile \
	    -D__CUDA_VERSION_SHORT="$(__SHORT)" \
	    Dockerfile.cpp && \
	docker build -t xgb:dev-$(__SHORT) . && \
	rm -f Dockerfile

.PHONY: xgboost80
xgboost80:
	$(MAKE) __CUDA_MINIFIED="80" __SHORT="8.0" xgboost

.PHONY: xgboost90
xgboost90:
	$(MAKE) __CUDA_MINIFIED="90" __SHORT="9.0" xgboost

.PHONY: xgboost91
xgboost91:
	$(MAKE) __CUDA_MINIFIED="91" __SHORT="9.1" xgboost

.PHONY: xgb-dev80
xgb-dev80:
	$(MAKE) __CUDA_MINIFIED="80" __SHORT="8.0" xgb-dev

.PHONY: xgb-dev90
xgb-dev90:
	$(MAKE) __CUDA_MINIFIED="90" __SHORT="9.0" xgb-dev

.PHONY: xgb-dev91
xgb-dev91:
	$(MAKE) __CUDA_MINIFIED="91" __SHORT="9.1" xgb-dev
## xgboost env's end ##


## gbm env's start ##
GBM_XG_COMMIT  ?= f87802f00c087b96f74799bc3e2f60e490ccfdb7
GBM_LG_COMMIT  ?= 9323758696f7cfb217cf9939d0bb97dc512008f3
GBM_CAT_COMMIT ?= 81848d19d3469d9d5345120bb3c365298a4a9b38
.PHONY: gbm
gbm: cuda$(__CUDA_MINIFIED)-dev
	cd $@ && \
	cpp -o Dockerfile \
	    -D__CUDA_VERSION_SHORT="$(__SHORT)" \
	    -DXGB_ARCH="$(XG_ARCH)" \
	    -DXGB_COMMIT="$(GBM_XG_COMMIT)" \
	    -DLG_COMMIT="$(GBM_LG_COMMIT)" \
	    -DCAT_COMMIT="$(GBM_CAT_COMMIT)" \
	    Dockerfile.cpp && \
	docker build -t gbm:latest-$(__SHORT) . && \
	rm -f Dockerfile

.PHONY: gbm80
gbm80:
	$(MAKE) __CUDA_MINIFIED="80" __SHORT="8.0" gbm

.PHONY: gbm90
gbm90:
	$(MAKE) __CUDA_MINIFIED="90" __SHORT="9.0" gbm

.PHONY: gbm91
gbm91:
	$(MAKE) __CUDA_MINIFIED="91" __SHORT="9.1" gbm
## gbm env's end ##



.PHONY: postgres
postgres:
	cd postgres && docker build -t postgres:latest .



## what targets follow hereafterwards are the ones which are built
## using a specific version of the above base images!
## (hence the parent image tags are being hard-coded!)
.PHONY: pix2pix
pix2pix: pytorch90_70
	cd pix2pix && \
	    cpp -o Dockerfile \
	        -D__PYTORCH_VERSION_TAG="latest-90_70" \
	        Dockerfile.cpp && \
	    docker build -t pix2pix:latest . && \
	    rm -f Dockerfile


.PHONY: gunrock
gunrock: cuda80
	cd gunrock && docker build -t gunrock:latest .

.PHONY: kaldi
kaldi: cudnn60
	cd kaldi && docker build -t kaldi:latest .

.PHONY: tensorflow10
tensorflow10: cudnn51
	cd tensorflow10 && \
	    cpp -o Dockerfile Dockerfile.cpp && \
	    docker build -t tensorflow:1.0 . && \
	    rm -f Dockerfile

.PHONY: nvcaffe
nvcaffe: cudnn60
	cd nvcaffe && docker build -t nvcaffe:latest .

MX_PORT ?= 8888
.PHONY: mxnet
mxnet: cudnn60
	cd mxnet && \
	    cpp -o Dockerfile Dockerfile.cpp && \
	    cp -r ../../shared-contexts contexts && \
	    docker build -t mxnet:keras \
	        --build-arg port=$(MX_PORT) . && \
	    rm -rf contexts Dockerfile

TF_PORT ?= 8888
.PHONY: tf-keras
tf-keras: cudnn60
	cd tf-keras && \
	    cpp -o Dockerfile Dockerfile.cpp && \
	    cp -r ../../shared-contexts contexts && \
	    docker build -t tensorflow:keras \
	        --build-arg port=$(TF_PORT) . && \
	    rm -rf contexts Dockerfile

.PHONY: pybind11
pybind11: cudnn60
	cd pybind11 && \
	    cpp -o Dockerfile Dockerfile.cpp && \
	    docker build -t pybind11:dev . && \
	    rm -f Dockerfile

FS_PORT ?= 8888
.PHONY: fairseq-py
fairseq-py: cudnn60
	cd $@ && \
	make -f ../Makefile genContext && \
	docker build -t fairseq-py:latest \
	    --build-arg port=$(FS_PORT) . && \
	make -f ../Makefile delContext

.PHONY: fairseq-py-dev
fairseq-py-dev: cudnn60
	cd $@ && \
	make -f ../Makefile genContext && \
	docker build -t fairseq-py-dev:latest \
	    --build-arg port=$(FS_PORT) . && \
	make -f ../Makefile delContext
