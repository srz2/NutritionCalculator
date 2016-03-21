//#include "Ingredient.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "Log/Log.h"
using namespace std;

class MainProgram{
private:
  static MainProgram * instance;

  MainProgram();
  MainProgram(const MainProgram & other);
  MainProgram & operator = (const MainProgram & other);

  void showMainMenu();
  int getInput();

  bool addItem();

protected:
  //Root Ingredient Array
  Ingredient * ingredients[kDefaultFoodArray];
  unsigned int ingredient_index;

public:
  static MainProgram * Instance();
  virtual ~MainProgram();

  void run();

  void importDatabase(const char * fileName);
  void exportDatabase(const char * fileName);
};