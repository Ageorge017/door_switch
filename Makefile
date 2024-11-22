# Define variables
BUILD_DIR = build

# Default target
all: build

# Custom build target
build:
	rm -rf $(BUILD_DIR)
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake -G Ninja ../ && cmake ../ && make
	cd ..

# Clean target
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all build clean