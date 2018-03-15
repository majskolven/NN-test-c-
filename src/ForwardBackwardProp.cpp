#include "../headers/NeuralNet.h"


//Feedforward
void NeuralNet::forwardProp()
{
  Matrice *layerLeft        = nullptr;
  Matrice *weightsBetween   = nullptr;
  Matrice  *layerRight      = nullptr;
  for(int i = 0; i < this->NNLayout.size() - 1; i++)
  {
    if(i == 0)
      layerLeft       = this->getConvertedLayer(i, NORMAL);
    else
      layerLeft       = this->getConvertedLayer(i, ACTIVATED);


    weightsBetween  = this->getWeights(i);
    layerRight = new Matrice(layerLeft->getRowCount(), weightsBetween->getColCount(), false);


    // result of multiplication will pointed at by layerRight
    Helper::matriceMultiplier(layerLeft, weightsBetween, layerRight);
    

    for(int rightIndex = 0; rightIndex < layerRight->getColCount(); rightIndex++)
    {
      this->setNeuronInLayer(i + 1, rightIndex, layerRight->getSpecificValue(0, rightIndex) + this->bias);
    }
    delete layerLeft;
    delete weightsBetween;
    delete layerRight;
  }
}

void NeuralNet::backProp()
{

}
