#include "../headers/NeuralNet.h"



NeuralNet::NeuralNet(int nrOfLayers, int nrOfNeurons)
{
  //Making Layers
  for(int i = 0; i < nrOfLayers; i++)
  {
    this->layers.push_back(new Layer(nrOfNeurons));
  }

  //Making Weights matrices connecting layers
  for(int i = 0; i < (nrOfLayers-1); i++)
  {
    this->weights.push_back(new Matrice(this->layers.at(i)->getSize(),
                            this->layers.at(i+1)->getSize(),
                            true));
  }
}
