
default:
	@echo "make what? Available targets are:"
	@echo "  . cuda80       cuda v8.0 image"
	@echo "  . gunrock      latest version of gunrock from github"
	@echo "  . python27     install python 2.7"
	@echo "  . postgres     install latest version of postgres"
	@echo "  . pyml-env     install jupyter/pandas/... libraries commonly used for ML projects"
	@echo "  . cudnn51      install cudnn v5.1"
	@echo "  . tensorflow10 install tensorflow 1.0"

.PHONY: cuda80
cuda80:
	cd cuda80 && docker build -t cuda:8.0 .

.PHONY: gunrock
gunrock: cuda80
	cd gunrock && docker build -t gunrock:latest .

.PHONY: python27
python27:
	cd python27 && docker build -t python:2.7 .

.PHONY: postgres
postgres: python27
	cd postgres && docker build -t postgres:latest .

.PHONY: pyml-env
pyml-env: python27
	cd pyml-env && docker build -t pyml-env:2.7 .

.PHONY: cudnn51
cudnn51: cuda80
	cd cudnn51 && docker build -t cudnn:5.1 .

.PHONY: tensorflow10
tensorflow10: cudnn51 python27
	cd tensorflow10 && docker build -t tensorflow:1.0 .
