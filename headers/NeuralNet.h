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
  NeuralNet(int nrOfLayers, int nrOfNeurons);


private:
  //The number of Layers and Neurons in each Layer
  vector<Layer*> layers;
  vector<Matrice*> weights;
};






#endif
