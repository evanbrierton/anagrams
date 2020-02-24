#! /bin/bash

# Create a build folder if it doesn't exist
mkdir -p build

# Change the current directory to "build"
cd build || exit

# Create all the build files needed
cmake -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Debug ..

# Build
make

# Execute

/Users/evanbrierton/Desktop/Computer\ Science/Stage\ 1/Spring/Software\ Engineering\ Project\ 1/assignment1/build/assignment1