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


    // result of multiplication will be pointed at by layerRight
    Helper::matriceMultiplier(layerLeft, weightsBetween, layerRight);


    for(int rightIndex = 0; rightIndex < layerRight->getColCount() - 1; rightIndex++)
    {
      this->setNeuronInLayer(i + 1, rightIndex, layerRight->getSpecificValue(0, rightIndex));
    }
    delete layerLeft;
    delete weightsBetween;
    delete layerRight;
  }
}

void NeuralNet::backProp()
{
  int indexOutputLayer      = this->NNLayout.size() - 1;
  Matrice *gradients        = new Matrice(1, this->NNLayout.at(indexOutputLayer), false);
  Matrice *deltaweights     = new Matrice(
                                this->weights.at(indexOutputLayer - 1)->getRowCount(),
                                this->weights.at(indexOutputLayer - 1)->getColCount(),
                                false);
  Matrice *derivedValues    = this->layers.at(indexOutputLayer)->convertToMatrice(DERIVED);
  Layer *outputLayer        = this->layers.at(indexOutputLayer);


  for(int i = 0; i < this->NNLayout.at(indexOutputLayer); i++)
  {
    double e = this->derivedErrors.at(i);
    //double y = derivedValues->getActivatedValue(0,i);
    //double g = (e*y);
    //gradients->setSpecificValue(0,i,g);
  }

  delete derivedValues;
  delete deltaweights;
  delete gradients;





}
