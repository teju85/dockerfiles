
help:
	@echo "make what? Available targets are:"
	@echo "  . cuda80       cuda v8.0 image"
	@echo "  . cudnn51      install cudnn v5.1"
	@echo "  . cudnn60      install cudnn v6.0"
	@echo "  . gunrock      latest version of gunrock from github"
	@echo "  . postgres     install latest version of postgres"
	@echo "  . pytorch      gpu enabled pytorch (on top of pyml-env libs)"
	@echo "                 Some flags to customize behavior:"
	@echo "                   PT_PORT - Jupyter port to be exposed [8888]"
	@echo "  . tensorflow10 install tensorflow 1.0"
	@echo "  . xgboost      install latest version of xgboost"
	@echo "                 Some flags to customize behavior:"
	@echo "                   XG_ARCH - cuda arch(s) to build for [35;50;52;60;61]"
	@echo "  . xgb-dev      Starts vnc server with env for xgboost development"
	@echo "                 Some flags to customize behavior:"
	@echo "                   XGB_DEV_VNC_PORT - vnc port [5900]"
	@echo "  . kaldi        install kaldi framework (shared lib version)"
	@echo "  . nvcaffe      install nv-caffe and its dependencies"

.PHONY: cuda80
cuda80:
	cd cuda80 && docker build -t cuda:8.0 .

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
.PHONY: xgboost
xgboost: cuda80
	cd xgboost && \
	    cpp -o Dockerfile Dockerfile.cpp && \
	    docker build -t xgboost:8.0 \
	        --build-arg arch="$(XG_ARCH)" . && \
	    rm -f Dockerfile

XGB_DEV_VNC_PORT ?= 5900
.PHONY: xgb-vnc
xgb-dev: cuda80
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
