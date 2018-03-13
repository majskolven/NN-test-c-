#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <vector>
#include "Neuron.h"
#include "Matrice.h"


using namespace std;

enum ValueType
{
   ACTIVATED,
   DERIVED,
   NORMAL
};


class Layer
{

public:
  Layer(int size);
  Layer(int size, ActivationType type);


  Matrice* convertToMatrice(ValueType type);

  int getSize();
  Neuron* getNeuron(int index);
  vector<double> getActivatedValues();
  vector<Neuron *> getLayer();

  void setLayer(vector<Neuron *> layer);
  void setNeuronValue(int index, double value);

  ~Layer();
private:
  int size;
  vector<Neuron *> layer;


};






#endif
