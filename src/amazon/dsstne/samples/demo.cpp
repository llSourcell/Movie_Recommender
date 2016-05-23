#include <iostream>
#include "commands.h"

using namespace std;
int main()
{
    //Collect the dataset
    retrieveDataset("https://s3-us-west-2.amazonaws.com/amazon-dsstne-samples/data/ml20m-all");
    //Generate input and output layer of our neural network (netcdf files are generated)
    generateInputLayer("ml20m-all");
    generateOutputLayer("ml20m-all");
    //Train our model, 256 batch size and 10 epochs
    train(256, 10);
    //Generate 10 recommendations from our newly trained model
    predict(10, "ml20m-all");
    return 0;
}
