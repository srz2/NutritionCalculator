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
  cout << "There are " << ingredient_index << " items in the database." << endl << endl;
  cout << OptionKeyAdd    << " - Add Item" << endl;
  cout << OptionKeyDelete << " - Delete Item" << endl;
  cout << OptionKeySearch << " - Search for Item" << endl;
  cout << OptionKeyQuit   << " - Quit Program" << endl;
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

  //Import Database from backup file
  importDatabase(Database_Path);

  int option = OptionKeyInvalid;
  do{
    showMainMenu();
    option = getInput();

    //Initiate Action
    switch(option)
    {
      case OptionKeyAdd:
      {
        addItem();
        break;
      }
      case OptionKeyDelete:
      {
        break;
      }
      case OptionKeySearch:
      {
        break;
      }
      case OptionKeyQuit:
      {
        //This will stop the loop
        break;
      }
      default:
      {
        cout << "Unknown Option \'" << option << "\'" << endl;
      }
    }
  }while(option != OptionKeyQuit);

  //At this point, the program is ending, so do clean up
  exportDatabase(Database_Path);
}

}

void MainProgram::importDatabase(const char * fileName)
{
  Log::Instance()->write("Importing Database from %s", fileName);

  unsigned int importCounter = 0;
  ifstream inFile(Database_Path);
  string line = "";

  while(getline(inFile, line))
  {
    ingredients[ingredient_index++] = new Ingredient(line.c_str());
    cout << "Imported " << line << endl;
    importCounter++;
  }

  Log::Instance()->write("Imported %d Items", importCounter);
}

void MainProgram::exportDatabase(const char * fileName)
{
  Log::Instance()->write("Exporting Database Items");

  unsigned int exportCounter = 0;
  ofstream outFile(Database_Path);
  for(unsigned int c = 0; c < ingredient_index; c++)
  {
    Ingredient * item = ingredients[c];
    outFile << item->getName() << endl;
    cout << "Exporting " << item->getName() << endl;

    exportCounter++;
  }
  outFile.close();

  Log::Instance()->write("Exported %d Items", exportCounter);
}
