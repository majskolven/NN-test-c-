#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
#include <math.h>
#include <vector>
#include <random>


using namespace std;


class Matrice
{

public:
  Matrice(int rows, int cols, bool initRandom);

  Matrice *tranposeMatrice();
  double initRandomValue();
  //sett/gett
  void setSpecificValue(int row, int cols, double value);
  double getSpecificValue(int row, int cols);
  int getRowCount();
  int getColCount();

  string toString();

private:
  vector<vector<double>> values;

  int rows;
  int cols;
};






#endif
