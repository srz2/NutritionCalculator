#include "MainProgram.h"

MainProgram * MainProgram::instance = NULL;

MainProgram * MainProgram::Instance()
{
  if(!instance)
    instance = new MainProgram();
  return instance;
}
MainProgram::MainProgram()
{

}
MainProgram::~MainProgram()
{

}
MainProgram::MainProgram(const MainProgram & other)
{

}
MainProgram & MainProgram::operator = (const MainProgram & other)
{
  return *this;
}
void MainProgram::showMainMenu()
{
  cout << "There are " << " " << " items in the database." << endl << endl;
  cout << "1 - Add Item" << endl;
  cout << "2 - Delete Item" << endl;
  cout << "3 - Search for Item" << endl;
  cout << "4 - Quit Program" << endl;
}
int MainProgram::getInput()
{
  int input = 0;

  cout << endl << "Option: ";
  cin >> input;

  return input;
}
void MainProgram::run()
{
  system("clear");
  showMainMenu();
  getInput();
}
void MainProgram::importFile(const char * fileName)
{

}
void MainProgram::exportFile(const char * fileName)
{

}

