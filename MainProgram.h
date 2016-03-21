#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "Log/Log.h"
#include "Ingredient.h"
using namespace std;

#ifndef Database_File
#define Database_File     ".nutritioncalculator.xml"
#endif

#ifndef Database_Location
#define Database_Location "./"
#endif

#ifndef Database_Path
#define Database_Path     Database_Location Database_File
#endif

#ifndef kDefaultFoodArray
#define kDefaultFoodArray       100
#endif

#ifndef kINPUT_BUFFER_SIZE_STR
#define kINPUT_BUFFER_SIZE_STR  255
#endif

#ifndef kINPUT_BUFFER_SIZE_INT
#define kINPUT_BUFFER_SIZE_INT  10
#endif

enum OptionKey{
  OptionKeyInvalid,
  OptionKeyAdd,
  OptionKeyDelete,
  OptionKeySearch,
  OptionKeyQuit
};

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