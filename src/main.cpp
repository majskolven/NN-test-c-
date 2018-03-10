#include <iostream>
#include <string>

#include "../headers/Layer.h"

#include "../headers/Neuron.h"

#include "../headers/Matrice.h"

using namespace std;


int main ()
{

  Matrice *m = new Matrice(3,2,true);
  cout << m->toString() << endl;


  //In
  /*Neuron *n = new Neuron(5.9);
  Layer *l = new Layer(10);
  cout << "Val: " << n->getValue() << endl;
  cout << "Val Activated: " << n->getActivatedValue() << endl;
  cout << "Val Derived: " << n->getDerivedValue() << endl;
  delete n;*/

  return 0;
}
