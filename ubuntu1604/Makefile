
help:
	@echo "make what? Available targets are:"
	@echo "  . cuda80       cuda v8.0 image"
	@echo "  . cuda80-dev   cuda v8.0 image suited for development through VNC"
	@echo "                 Some flags to customize behavior:"
	@echo "                   VNC_PORT - vnc port [$(VNC_PORT)]"
	@echo "  . cuda90       cuda v9.0 image"
	@echo "  . cuda90-dev   cuda v9.0 image suited for development through VNC"
	@echo "                 Some flags to customize behavior:"
	@echo "                   VNC_PORT - vnc port [$(VNC_PORT)]"
	@echo "  . cuda91       cuda v9.1 image"
	@echo "  . cuda91-dev   cuda v9.1 image suited for development through VNC"
	@echo "                 Some flags to customize behavior:"
	@echo "                   VNC_PORT - vnc port [$(VNC_PORT)]"
	@echo "  . cudnn51      install cudnn v5.1 (cuda v8.0)"
	@echo "  . cudnn60      install cudnn v6.0 (cuda v8.0)"
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

.PHONY: cuda80
cuda80:
	cd $@ && \
	make -f ../Makefile genContext && \
	docker build -t cuda:8.0 . && \
	make -f ../Makefile delContext

VNC_PORT ?= 5900
.PHONY: cuda80-dev
cuda80-dev:
	cd $@ && \
	make -f ../Makefile genContext && \
	docker build -t cuda:8.0-dev \
	    --build-arg port=$(VNC_PORT) . && \
	make -f ../Makefile delContext

.PHONY: cuda90
cuda90:
	cd $@ && \
	make -f ../Makefile genContext && \
	docker build -t cuda:9.0 . && \
	make -f ../Makefile delContext

.PHONY: cuda90-dev
cuda90-dev:
	cd $@ && \
	make -f ../Makefile genContext && \
	docker build -t cuda:9.0-dev \
	    --build-arg port=$(VNC_PORT) . && \
	make -f ../Makefile delContext

.PHONY: cuda91
cuda91:
	cd $@ && \
	make -f ../Makefile genContext && \
	docker build -t cuda:9.1 . && \
	make -f ../Makefile delContext

.PHONY: cuda91-dev
cuda91-dev:
	cd $@ && \
	make -f ../Makefile genContext && \
	docker build -t cuda:9.1-dev \
	    --build-arg port=$(VNC_PORT) . && \
	make -f ../Makefile delContext

.PHONY: dbscan
dbscan-dev: cuda90-dev
	cd $@ && \
	make -f ../Makefile genContext && \
	docker build -t dbscan:dev . && \
	make -f ../Makefile delContext

.PHONY: cudnn51
cudnn51: cuda80
	cd cudnn51 && docker build -t cudnn:5.1 .

.PHONY: cudnn60
cudnn60: cuda80
	cd cudnn60 && docker build -t cudnn:6.0 .

.PHONY: gunrock
gunrock: cuda80
	cd gunrock && docker build -t gunrock:latest .

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

.PHONY: kaldi
kaldi: cudnn60
	cd kaldi && docker build -t kaldi:latest .

.PHONY: nvcaffe
nvcaffe: cudnn60
	cd nvcaffe && docker build -t nvcaffe:latest .

GBM_XG_COMMIT ?= 77ae4c870178be3c4dbe5331ec7966cec93fee33
GBM_LG_COMMIT ?= 04d4811b4e6d51542bd2e2e23d0e608a9732ea30
GBM_CAT_COMMIT ?= f28154d8b0d4ca8e4d1baed2260656ba1223a75d
.PHONY: gbm
gbm: cuda80
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


# for the below 2 targets, the pwd has to be inside the directory containing Dockerfile.cpp!
.PHONY: genContext
genContext:
	cpp -o Dockerfile Dockerfile.cpp && \
	    grep -v -e '^#' -e '^# ' -e '^$$' Dockerfile > tmp && \
	    mv tmp Dockerfile && \
	    rm -rf contexts && \
	    cp -r ../../shared-contexts contexts

.PHONY: delContext
delContext:
	rm -rf contexts Dockerfile
