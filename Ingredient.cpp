#include "Ingredient.h"

Ingredient::Ingredient()
{
  this->name = nullptr;
  this->calories = 0;
  this->caloriesFromFat = 0;

  this->attributeIndex = 0;
  this->attributes = nullptr;
}
Ingredient::Ingredient(string name)
{
  this->name = new char[MAX_SIZE_INGREDIENT_NAME];
  strcpy(this->name, name.c_str());
  this->calories = 0;
  this->caloriesFromFat = 0;

  this->attributeIndex = 0;
  this->attributes = new IngredientAttribute[MAX_SIZE_ATTRIBUTES_PER_INGREDIENT];
}
Ingredient::Ingredient(string name, unsigned int calories, unsigned, int caloriesFromFat)
{
  this->name = new char[MAX_SIZE_INGREDIENT_NAME];
  strcpy(this->name, name.c_str());
  this->calories = calories;
  this->caloriesFromFat = caloriesFromFat;

  this->attributeIndex = 0;
  this->attributes = new IngredientAttribute[MAX_SIZE_ATTRIBUTES_PER_INGREDIENT];
}

Ingredient::~Ingredient()
{
  if(this->name)
    delete [] this->name;
  this->calories = 0;
  this->caloriesFromFat = 0;

  if(this->attributes)
    delete [] this->attributes;
  attributeIndex = 0;
}
Ingredient::Ingredient(const Ingredient & other)
{
  this->name = other.name;
  this->calories = other.calories;
  this->caloriesFromFat = other.caloriesFromFat;
  this->attributes = other.attributes;
  this->attributeIndex = other.attributeIndex;
}
Ingredient & Ingredient::operator = (const Ingredient & other)
{
  this->name = other.name;
  this->calories = other.calories;
  this->caloriesFromFat = other.caloriesFromFat;
  this->attributes = other.attributes;
  this->attributeIndex = other.attributeIndex;

  return *this;
} 

void Ingredient::setName(char * name)
{
  if(this->name == NULL)
    this->name = new char[MAX_SIZE_INGREDIENT_NAME];
  strcpy(this->name, name);
}
char * Ingredient::getName()
{
  return this->name;
}

void Ingredient::setCalories(unsigned int calories)
{
  this->calories = calories;
}
unsigned int Ingredient::getCalories()
{
  return this->calories;
}

void Ingredient::setCaloriesFromFat(unsigned int caloriesFromFat)
{
  this->caloriesFromFat = caloriesFromFat;
}
unsigned int Ingredient::getCaloriesFromFat()
{
  return this->caloriesFromFat;
}

unsigned int Ingredient::getNumAttributes()
{
  return this->attributeIndex;
}
IngredientAttribute * Ingredient::getAttributes(unsigned int & numAttributes)
{
  numAttributes = this->attributeIndex;
  return this->attributes;
}
IngredientAttribute * Ingredient::getAttribute(unsigned int index)
{
  if(index >= this->attributeIndex)
    return nullptr;
  return &attributes[index];
}
IngredientAttribute * Ingredient::getAttribute(char * name)
{
  //TODO: Implement
  return nullptr;
}     
bool Ingredient::addAttribute(IngredientAttribute * newAttribute)
{
  if(this->attributeIndex >= MAX_SIZE_ATTRIBUTES_PER_INGREDIENT)
    return false;

  this->attributes[this->attributeIndex++] = *newAttribute;
  return true;
}
