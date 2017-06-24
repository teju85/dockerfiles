
default:
	@echo "make what? Available targets are:"
	@echo "  . cuda80       cuda v8.0 image"
	@echo "  . cudnn51      install cudnn v5.1"
	@echo "  . cudnn60      install cudnn v6.0"
	@echo "  . gunrock      latest version of gunrock from github"
	@echo "  . postgres     install latest version of postgres"
	@echo "  . pyml-env     install jupyter/pandas/... libraries commonly used for ML projects"
	@echo "  . python27     install python 2.7"
	@echo "  . pytorch      install pytorch"
	@echo "  . tensorflow10 install tensorflow 1.0"
	@echo "  . xgboost      install latest version of xgboost"

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

.PHONY: pyml-env
pyml-env: python27
	cd pyml-env && docker build -t pyml-env:2.7 .

.PHONY: python27
python27:
	cd python27 && docker build -t python:2.7 .

.PHONY: pytorch
pytorch: cudnn60
	cd pytorch && docker build -t pytorch:0.1.12 .

.PHONY: tensorflow10
tensorflow10: cudnn51 python27
	cd tensorflow10 && docker build -t tensorflow:1.0 .

.PHONY: xgboost
xgboost: cuda80
	cd xgboost && docker build -t xgboost:latest .
