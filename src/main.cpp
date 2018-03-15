#include <iostream>
#include <string>
#include <vector>

#include "../headers/Layer.h"

#include "../headers/utils/utils.h"


#include "../headers/Neuron.h"

#include "../headers/Matrice.h"

#include "../headers/NeuralNet.h"

using namespace std;


int main ()
{

  /*Matrice *a = new Matrice(3, 3, true);
  cout << a->toString() << endl;
  Matrice *b = new Matrice(3, 3, true);
  cout << "===================================" << endl;
  cout << b->toString() << endl;
  cout << "===================================" << endl<<endl<<endl;
  Matrice *c = new Matrice(a->getColCount(), b->getRowCount(), false);

  utils::Helper::matriceMultiplier(a,b,c);

  cout << c->toString() << endl;*/


  vector<int> layout;
  layout.push_back(4);
  layout.push_back(5);
  layout.push_back(5);
  layout.push_back(5);
  layout.push_back(5);
  layout.push_back(5);
  layout.push_back(5);
  layout.push_back(3);


  NeuralNet *net = new NeuralNet(layout, 1.345, SIGMOID, SIGMOID, 1);
  vector<double> v;
  v.push_back(4.5);
  v.push_back(2.5);
  v.push_back(3.7);
  v.push_back(1.2);
  net->setInputLayer(v);
  net->forwardProp();

  cout << net->toString() << endl<<endl<<endl;

  return 0;
}
