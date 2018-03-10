#include "../headers/Matrice.h"



Matrice::Matrice(int rows, int cols, bool initRandom)
{
  this->rows = rows;
  this->cols = cols;
  for(int m = 0; m < rows; m++)
  {
    vector<double> colValues;
    for(int n = 0; n < cols; n++)
    {
      double rand = 0.00;
      if(initRandom)
        rand = initRandomValue();
      colValues.push_back(rand);
    }
    this->values.push_back(colValues);
  }
}


Matrice *Matrice::tranposeMatrice()
{

  Matrice *result = new Matrice(this->cols, this->rows, false);
  for(int m = 0; m < this->rows; m++)
  {
    for(int n = 0; n < this->cols; n++)
    {
        result->setSpecificValue(n, m, this->getSpecificValue(m, n));
    }
  }
  cout << to_string(result->getRowCount())<< "    "  << to_string(result->getColCount()) << endl << endl;

  return result;
}

double Matrice::initRandomValue()
{
  random_device randomDevice;
  mt19937 gen(randomDevice());
  uniform_real_distribution<> dis(0, 1);

  return dis(gen);
}

void Matrice::setSpecificValue(int row, int col, double value)
{
  this->values.at(row).at(col) = value;
}

double Matrice::getSpecificValue(int row, int col)
{
  return this->values.at(row).at(col);
}

int Matrice::getRowCount()
{
  return this->rows;
}

int Matrice::getColCount()
{
  return this->cols;
}

string Matrice::toString()
{
  string result = "";
  for(int m = 0; m < this->rows; m++)
  {
    for(int n = 0; n < this->cols; n++)
    {
      result += to_string(this->values.at(m).at(n)) + "\t\t";
    }
    result += "\n";
  }
  return result;
}
