
default:
	@echo "make what? Available targets are:"
	@echo "  . cuda80      cuda v8.0 image"
	@echo "  . gunrock     latest version of gunrock from github"

.PHONY: cuda80
cuda80:
	cd cuda80 && docker build -t cuda:8.0 .

.PHONY: gunrock
gunrock: cuda80
	cd gunrock && docker build -t gunrock:latest .

