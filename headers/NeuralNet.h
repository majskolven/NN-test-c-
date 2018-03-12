#ifndef NEURALNET_H
#define NEURALNET_H

#include <iostream>
#include <math.h>
#include <vector>
#include "Layer.h"
#include "Matrice.h"


using namespace std;


class NeuralNet
{

public:
  NeuralNet(vector<int> NNLayout);
  NeuralNet(vector<int> NNLayout, vector<double> inputValues);


  void setInputLayer(vector<double> inputValues);
  string toString();

  ~NeuralNet();
private:
  //The number of Layers and Neurons in each Layer
  vector<int>       NNLayout;
  vector<Layer*>    layers;
  vector<Matrice*>  weights;
  vector<double>    inputValues;
};






#endif
