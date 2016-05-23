#include <stdio.h>
#include <iostream>

void retrieveDataset(const char* input);
void generateInputLayer(const char* input);
void generateOutputLayer(const char * input);
void train(int batchSize, int num_epochs);
void predict(int num_recommendations, const char * input);
