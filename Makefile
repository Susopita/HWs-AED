.DEFAULT_GOAL := help

.PHONY: help buildimage clean shell test-example test-hw1 test-hw2 test-hw3 test-hw4 test-hw5

O_EXAMPLE=example-list/list
CC_EXAMPLE=example-list/list.cc example-list/list-test.cc

O_HW1=hw1/hw1
CC_HW1=hw1/hw1-test.cc

O_HW2=hw2/hw2
CC_HW2=hw2/hw2-test.cc

O_HW3=hw3/hw3
CC_HW3=hw3/hw3-test.cc

O_HW4=hw4/hw4
CC_HW4=hw4/hw4-test.cc

O_HW5=hw5/hw5
CC_HW5=hw5/hw5-test.cc

# Detectar si estamos en Windows
ifeq ($(OS),Windows_NT)
    UID = 1000
    GID = 1000
    PWD = $(CURDIR)
else
    UID = $(shell id -u)
    GID = $(shell id -g)
    PWD = $(shell pwd)
endif

help: ## Display available commands in Makefile
	@grep -hE '^[a-zA-Z_0-9-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

buildimage: ## Build the docker image that will be used to compile and test the files
	docker build . -f Dockerfile-aed -t ubuntu-aed:1 --build-arg uid=$(UID) --build-arg gid=$(GID) --build-arg user=dockeruser --build-arg group=dockergroup

shell: ## Launch a bash attached to the docker image that already contains GTest and the tools needed to build the code
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 bash

test-example: ## Compile and test the example present in the directory list
	docker build . -f Dockerfile-aed -t ubuntu-aed:1 --build-arg uid=$(UID) --build-arg gid=$(GID) --build-arg user=dockeruser --build-arg group=dockergroup
	echo "compiling..."
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 g++ -o $(O_EXAMPLE) $(CC_EXAMPLE) -lgtest -lgtest_main -pthread
	echo "testing"
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 ./$(O_EXAMPLE)

test-hw1: ## Compile and test the hw1
	docker build . -f Dockerfile-aed -t ubuntu-aed:1 --build-arg uid=$(UID) --build-arg gid=$(GID) --build-arg user=dockeruser --build-arg group=dockergroup
	echo "compiling..."
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 g++ -o $(O_HW1) $(CC_HW1) -lgtest -lgtest_main -pthread
	echo "testing"
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 ./$(O_HW1)
	echo "cleaning"
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 rm ./$(O_HW1)

test-hw2: ## Compile and test the hw2
	docker build . -f Dockerfile-aed -t ubuntu-aed:1 --build-arg uid=$(UID) --build-arg gid=$(GID) --build-arg user=dockeruser --build-arg group=dockergroup
	echo "compiling..."
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 g++ -o $(O_HW2) $(CC_HW2) -lgtest -lgtest_main -pthread
	echo "testing"
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 ./$(O_HW2)
	echo "cleaning"
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 rm ./$(O_HW2)

test-hw3: ## Compile and test the hw3
	docker build . -f Dockerfile-aed -t ubuntu-aed:1 --build-arg uid=$(UID) --build-arg gid=$(GID) --build-arg user=dockeruser --build-arg group=dockergroup
	echo "compiling..."
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 g++ -o $(O_HW3) $(CC_HW3) -lgtest -lgtest_main -pthread
	echo "testing"
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 ./$(O_HW3)
	echo "cleaning"
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 rm ./$(O_HW3)

test-hw4: ## Compile and test the hw4
	docker build . -f Dockerfile-aed -t ubuntu-aed:1 --build-arg uid=$(UID) --build-arg gid=$(GID) --build-arg user=dockeruser --build-arg group=dockergroup
	echo "compiling..."
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 g++ -o $(O_HW4) $(CC_HW4) -lgtest -lgtest_main -pthread
	echo "testing"
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 ./$(O_HW4)
	echo "cleaning"
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 rm ./$(O_HW4)

test-hw5: ## Compile and test the hw5
	docker build . -f Dockerfile-aed -t ubuntu-aed:1 --build-arg uid=$(UID) --build-arg gid=$(GID) --build-arg user=dockeruser --build-arg group=dockergroup
	echo "compiling..."
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 g++ -o $(O_HW5) $(CC_HW5) -lgtest -lgtest_main -pthread
	echo "testing"
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 ./$(O_HW5)
	echo "cleaning"
	docker run -v $(PWD):/workdir -w /workdir -it ubuntu-aed:1 rm ./$(O_HW5)

clean: ## Clean compiled files
	rm -rf $(O_EXAMPLE) $(O_HW1) $(O_HW2) $(O_HW3) $(O_HW4) $(O_HW5)
