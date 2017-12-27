
help:
	@echo "make what? Available targets are:"
	@echo "  . cuda(80|90|91)     - cuda v8.0/v.9.0/v9.1 runtimes. These, in"
	@echo "                         addition, come with 'runas' ability."
	@echo "  . cuda(80|90|91)-dev - cuda v8.0/v.9.0/v9.1 devels. These, in"
	@echo "                         addition, come with 'runas' ability."
	@echo "  . cudnn(51|60|80_70|90_70)     - cudnn v5.1/v6.0/v7.0-with-v8.0/"
	@echo "                                   v7.0-with-9.0 runtimes."
	@echo "  . cudnn(51|60|80_70|90_70)-dev - cudnn v5.1/v6.0/v7.0-with-v8.0/"
	@echo "                                    v7.0-with-9.0 devels."
	@echo
	@echo "  . gunrock      latest version of gunrock from github"
	@echo "  . postgres     install latest version of postgres"
	@echo "  . pytorch      gpu enabled pytorch (on top of pyml-env libs)"
	@echo "                 Some flags to customize behavior:"
	@echo "                   PT_PORT - Jupyter port to be exposed [$(PT_PORT)]"
	@echo "  . tensorflow10 install tensorflow 1.0"
	@echo "  . xgboost      install latest version of xgboost"
	@echo "                 Some flags to customize behavior:"
	@echo "                   XG_ARCH - cuda arch(s) to build for [$(XG_ARCH)]"
	@echo "                   XG_COMMIT - commit ID to which to sync [$(XG_COMMIT)]"
	@echo "  . xgb-dev      Starts vnc server with env for xgboost development"
	@echo "                 Some flags to customize behavior:"
	@echo "                   XGB_DEV_VNC_PORT - vnc port [$(XGB_DEV_VNC_PORT)]"
	@echo "  . kaldi        install kaldi framework (shared lib version)"
	@echo "  . nvcaffe      install nv-caffe and its dependencies"
	@echo "  . gbm          gbm benchmarking images"
	@echo "                 Some flags to customize behavior:"
	@echo "                   XG_ARCH - cuda arch(s) to build for [$(XG_ARCH)]"
	@echo "                   GBM_XG_COMMIT - xgboost commit ID to sync to [$(GBM_XG_COMMIT)]"
	@echo "                   GBM_LG_COMMIT - lightgbm commit ID to sync to [$(GBM_LG_COMMIT)]"
	@echo "                   GBM_CAT_COMMIT - catboost commit ID to sync to [$(GBM_CAT_COMMIT)]"
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
	@echo "  . dbscan-dev   dbscan developmental image"


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
	$(MAKE) __CUDNN="5.1.10" __CUDNN_SHORT="5" __SHORT="8.0" __CUDA_MINIFIED=80 cudnn

.PHONY: cudnn60
cudnn60:
	$(MAKE) __CUDNN="6.0.21" __CUDNN_SHORT="6" __SHORT="8.0" __CUDA_MINIFIED=80 cudnn

.PHONY: cudnn80_70
cudnn80_70:
	$(MAKE) __CUDNN="7.0.5.15" __CUDNN_SHORT="7" __SHORT="8.0" __CUDA_MINIFIED=80 cudnn

.PHONY: cudnn51-dev
cudnn51-dev:
	$(MAKE) __CUDNN="5.1.10" __CUDNN_SHORT="5" __SHORT="8.0" __CUDA_MINIFIED=80 cudnn-dev

.PHONY: cudnn60-dev
cudnn60-dev:
	$(MAKE) __CUDNN="6.0.21" __CUDNN_SHORT="6" __SHORT="8.0" __CUDA_MINIFIED=80 cudnn-dev

.PHONY: cudnn80_70-dev
cudnn80_70-dev:
	$(MAKE) __CUDNN="7.0.5.15" __CUDNN_SHORT="7" __SHORT="8.0" __CUDA_MINIFIED=80 cudnn-dev
## cudnn with v8.0 env related targets end ##


## cudnn with v9.0 env related targets begin ##
.PHONY: cudnn90_70
cudnn90_70:
	$(MAKE) __CUDNN="7.0.5.15" __CUDNN_SHORT="7" __SHORT="9.0" __CUDA_MINIFIED=90 cudnn

.PHONY: cudnn90_70-dev
cudnn90_70-dev:
	$(MAKE) __CUDNN="7.0.5.15" __CUDNN_SHORT="7" __SHORT="9.0" __CUDA_MINIFIED=90 cudnn-dev
## cudnn with v9.0 env related targets end ##


.PHONY: gunrock
gunrock: cuda80
	cd gunrock && docker build -t gunrock:latest .

.PHONY: kaldi
kaldi: cudnn60
	cd kaldi && docker build -t kaldi:latest .

.PHONY: postgres
postgres:
	cd postgres && docker build -t postgres:latest .

PT_PORT ?= 8888
.PHONY: pytorch
pytorch: cudnn60
	cd pytorch && \
	    cpp -o Dockerfile Dockerfile.cpp && \
	    cp -r ../../shared-contexts contexts && \
	    docker build -t pytorch:0.1.12 \
	        --build-arg port=$(PT_PORT) . && \
	    rm -rf contexts Dockerfile

.PHONY: tensorflow10
tensorflow10: cudnn51
	cd tensorflow10 && \
	    cpp -o Dockerfile Dockerfile.cpp && \
	    docker build -t tensorflow:1.0 . && \
	    rm -f Dockerfile

XG_ARCH ?= 35;50;52;60;61
XG_COMMIT ?= 998ac6e27107af6d5e73022f1bcbbf5e5dd10d72
.PHONY: xgboost
xgboost: cuda80
	cd xgboost && \
	    cpp -o Dockerfile Dockerfile.cpp && \
	    docker build -t xgboost:8.0 \
	        --build-arg arch="$(XG_ARCH)" \
	        --build-arg xgCommit=$(XG_COMMIT) . && \
	    rm -f Dockerfile

XGB_DEV_VNC_PORT ?= 5900
.PHONY: xgb-vnc
xgb-dev: cuda80-dev
	cd xgb-dev && \
	    cpp -o Dockerfile Dockerfile.cpp && \
	    rm -rf contexts && \
	    cp -r ../../shared-contexts contexts && \
	    docker build -t xgb-dev:8.0 \
	        --build-arg port=$(XGB_DEV_VNC_PORT) . && \
	    rm -rf contexts Dockerfile

.PHONY: nvcaffe
nvcaffe: cudnn60
	cd nvcaffe && docker build -t nvcaffe:latest .

GBM_XG_COMMIT ?= 4d36036fe6fdc30ba4d72c84f3957a39a29ab23f
GBM_LG_COMMIT ?= 72b549561ff42239dffdcce231a46791ec59c35c
GBM_CAT_COMMIT ?= f28154d8b0d4ca8e4d1baed2260656ba1223a75d
.PHONY: gbm
gbm: cuda80-dev
	cd $@ && \
	make -f ../Makefile genContext && \
	docker build -t gbm:latest \
	    --build-arg arch="$(XG_ARCH)" \
	    --build-arg xgCommit=$(GBM_XG_COMMIT) \
	    --build-arg lgCommit=$(GBM_LG_COMMIT) \
	    --build-arg catCommit=$(GBM_CAT_COMMIT) . && \
	make -f ../Makefile delContext

.PHONY: pix2pix
pix2pix: pytorch
	cd pix2pix && \
	    cpp -o Dockerfile Dockerfile.cpp && \
	    docker build -t pix2pix:latest . && \
	    rm -f Dockerfile

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
