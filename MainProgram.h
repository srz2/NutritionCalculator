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

public:
  static MainProgram * Instance();
  virtual ~MainProgram();

  void run();

  void importFile(const char * fileName);
  void exportFile(const char * fileName);
};