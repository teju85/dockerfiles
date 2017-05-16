
default:
	@echo "make what? Available targets are:"
	@echo "  . cuda80      cuda v8.0 image"
	@echo "  . gunrock     latest version of gunrock from github"
	@echo "  . python27    install python 2.7"
	@echo "  . postgres    install latest version of postgres"

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
