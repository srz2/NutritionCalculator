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
  //Initialize Variables
  ingredient_index = 0;

  //Check for Database
  ifstream inFile(Database_Path);
  if(!inFile)
  {
    cout << "Database missing..." << endl;
  }
  inFile.close();
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
  char * input = new char[kINPUT_BUFFER_SIZE_INT];
  memset(input, '\0', kINPUT_BUFFER_SIZE_INT);

  cout << endl << "Option: ";
  int val = scanf("%s", input);

  //Assure the last char isn't overwritten
  input[kINPUT_BUFFER_SIZE_INT - 1] = '\0';
  int value = atoi(input);

  delete [] input;

  return value;
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

bool MainProgram::addItem()
{
  Log::Instance()->write("Begin Add Item");

  //Get Name of Food
  char name[kINPUT_BUFFER_SIZE_STR];
  memset(name, '\0', kINPUT_BUFFER_SIZE_STR);
  cout << "Enter new food item: ";
  scanf("%s", name);

  //Get Weight of Food
  char weight[kINPUT_BUFFER_SIZE_INT];
  memset(weight, '\0', kINPUT_BUFFER_SIZE_INT);
  cout << "Enter weight of a single serving of \'" << name << "\': ";
  scanf("%s", weight);

  //Get Calories of food
  char calories[kINPUT_BUFFER_SIZE_INT];
  memset(calories, '\0', kINPUT_BUFFER_SIZE_INT);
  cout << "Enter the amount of calories: ";
  scanf("%s", calories);

  //Get Calories from Fat of food
  char caloriesFat[kINPUT_BUFFER_SIZE_INT];
  memset(caloriesFat, '\0', kINPUT_BUFFER_SIZE_INT);
  cout << "Enter the amount of calories from fat: ";
  scanf("%s", caloriesFat);

  Ingredient * newFood = new Ingredient(name);//, atoi(calories), atoi(caloriesFat));
  ingredients[ingredient_index++] = newFood;
  Log::Instance()->write("Added %s", name);

  return false;
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
