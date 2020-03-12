# Bloom filter password checker.

I have tested this project and confirmed that it works on the CS linux lab machines with the 
 following dependency versions.

 gcc 8.1.0
 g++ 8.1.0
 cmake 3.5.1

Project source files are located in the directory labeled `src`
Project tests are located in the directory labeled `tests`
Project external dependencies are in `external`

## How to build the project

First, make sure the current working directory is at the root of the project. (This README is at
 the project root)

From the root of the project, execute the following commands.

```
export CC=gcc
export CXX=g++
mkdir build
cd build
cmake .. -G "Unix Makefiles"
make
```

This generates the source binaries at the following location from the project root, ./build/src

## How to run the project

First, make sure the project has been built using the steps above.

From the root of the project, navigate to the built binaries.

```
cd ./build/src
```

Place the dictionary file that you want to use in this directory with the name "dictionary.txt"
NOTE: DICTIONARY FILE MUST BE NAMED "dictionary.txt" AND MUST BE IN THE DIRECTORY LISTED ABOVE 
  RELATIVE TO PROJECT ROOT

Once you have placed the dictionary in the directory, execute the program by running the following
 command:

```
./bloom_filter
```
