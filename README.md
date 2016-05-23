#Overview
This project  trains 3 layer feedforward neural network over a dataset of MovieLens-based user ratings to generate movie recommendations. This the code for 'Build a Movie Recommender' on [Youtube](https://youtu.be/eKmIVU8EUbw).

#Dependencies
[Just run this on the preconfigured AWS image, so you don't have to worry about this -- these dependencies aren't trivial]

* [GCC](https://gcc.gnu.org/install/)
* [CuBLAS](https://github.com/amznlabs/amazon-dsstne/blob/master/docs/getting_started/setup.md#cublas-setup)
* Cuda Toolkit (>= 7.0 is required) 
* [OpenMPI](https://github.com/amznlabs/amazon-dsstne/blob/master/docs/getting_started/setup.md#openmpi-setup)
* [NetCDF](https://github.com/amznlabs/amazon-dsstne/blob/master/docs/getting_started/setup.md#netcdf-setup)
* [JsonCPP](https://github.com/amznlabs/amazon-dsstne/blob/master/docs/getting_started/setup.md#jsoncpp-setup)
* [CUB](https://github.com/amznlabs/amazon-dsstne/blob/master/docs/getting_started/setup.md#cub-setup)


#Basic Usage

1. Create a GPU instance in the US East N. Virginia region using the preconfigured AMI [Amazon Machine Image] called 'ami-d6f2e6bc'
2. Download this repo, then upload it to the root directory of that instance via FileZilla
3. SSH into that instance and compile this project via the following commands
```bash
cd amazon-dsstne/src/amazon/dsstne
#Add the mpiCC and nvcc compiler in the path
export PATH=/usr/local/openmpi/bin:/usr/local/cuda/bin:$PATH
make
export PATH=`pwd`/bin:$PATH
cd samples
g++ commands.cpp demo.cpp 
./a.out
```
Demo.cpp is the code from the video tutorial. It'll generate a set of recommendations from the dataset in the recs file.

#Credits
Credit for this library goes to the DSSTNE team at Amazon. I've merely created a C++ wrapper around all of the important functions to get people started.
