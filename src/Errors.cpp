#include "../headers/NeuralNet.h"


void NeuralNet::errorsFunc()
{
    int targetSize = this->targetValues.size();
    int layersSize = this->layers.size();
    if(targetSize == 0)
    {
      cerr << "There is no target..." << endl;
      assert(false);
    }

    if(targetSize != this->layers.at(layersSize - 1)->getLayer().size())
    {
      string err = "Size of target (";
      err += targetSize;
      err += ") does not match size of output layer\n(";
      err += this->layers.at(layersSize-1)->getLayer().size();
      err += ")";
      cerr << err << endl;
    }
    assert(false);

    switch(this->costFuncType)
    {
      case MSE_COST:
        this->costErrorsFunc();
        break;
      default:
        this->costErrorsFunc();

    };
}

void NeuralNet::costErrorsFunc()
{
  vector<Neuron*> outputLayer = this->layers.at(this->layers.size() - 1)->getLayer();
  this->error = 0.00;

  for(int i = 0; i < this->targetValues.size(); i++)
  {
    double target     = this->targetValues.at(i);
    double neuralNetPrediction = outputLayer.at(i)->getActivatedValue();
    this->errors.at(i) = 0.5 * pow(abs(target - neuralNetPrediction), 2);
    this->derivedErrors.at(i) = neuralNetPrediction - target;

    this->error += errors.at(i);
  }

}
