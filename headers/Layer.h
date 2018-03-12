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

  void setValues(int index, double value);
  int getSize();

  Neuron* getNeuron(int index);
  Matrice* convertToMatrice(ValueType type);
  ~Layer();
private:
  int size;
  vector<Neuron *> layer;


};






#endif
