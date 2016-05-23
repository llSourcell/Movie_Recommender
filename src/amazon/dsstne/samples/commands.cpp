#include <iostream>
#include "commands.h"

using namespace std;


void retrieveDataset(const char* input) 
{
	const char* command = "wget ";
	std::string buf(command);
	buf.append(input);
	const char * c = buf.c_str();
	system(c);
}

void generateInputLayer(const char* input)
{
	const char * start = "generateNetCDF -d gl_input -i ";
	std::string buf(start);
	buf.append(input);
	const char * end = " -o gl_input.nc -f features_input -s samples_input -c";
	buf.append(end);
	const char * c = buf.c_str();
    system(c);
}

void generateOutputLayer(const char * input)
{
	const char * start = "generateNetCDF -d gl_output -i ";
	std::string buf(start);
	buf.append(input);
	const char * end = " -o gl_output.nc -f features_output -s samples_input -c";
	buf.append(end);
	const char * c = buf.c_str();
    system(c);
}

void train(int batchSize, int num_epochs)
{
	const char * start = "train -c config.json -i gl_input.nc -o gl_output.nc -n gl.nc -b ";
	std::string buf(start);
	std::string batchString = std::to_string(batchSize);
	std::string epochString = std::to_string(num_epochs);
	char const *b = batchString.c_str();
	char const *e = epochString.c_str();
	buf.append(b);
	const char * middle =  " -e ";
	buf.append(middle);
	buf.append(e);
	const char * c = buf.c_str();
	std::cout << c;
    system(c);
}

void predict(int num_recommendations, const char * input) 
{
	const char * start = "predict -b 1024 -d gl -i features_input -o features_output -k ";
	std::string buf(start);
	std::string recString = std::to_string(num_recommendations);
	char const *r = recString.c_str();
	buf.append(r);
	const char * next = " -n gl.nc -f ";
	buf.append(next);
	buf.append(input);
	const char * last = " -s recs -r ";
	buf.append(last);
	buf.append(input);
	const char * c = buf.c_str();
	system(c);
}

