#include "IngredientAttribute.h"

IngredientAttribute::IngredientAttribute()
{
  this->name = NULL;
  this->weight = 0;

  this->childrenIndex = 0;
  this->children = NULL;
}
IngredientAttribute::IngredientAttribute(string name)
{
  this->name = new char[MAX_SIZE_INGREDIENT_ATTRIBUTE_NAME];
  strcpy(this->name, name.c_str());
  this->weight = 0;

  this->childrenIndex = 0;
  this->children = new IngredientAttribute*[MAX_SIZE_ATTRIBUTES_PER_INGREDIENT];
}
IngredientAttribute::IngredientAttribute(string name, unsigned int weight)
{
  this->name = new char[MAX_SIZE_INGREDIENT_ATTRIBUTE_NAME];
  strcpy(this->name, name.c_str());
  this->weight = weight;

  this->childrenIndex = 0;  
  this->children = new IngredientAttribute*[MAX_SIZE_ATTRIBUTES_PER_INGREDIENT];
}
IngredientAttribute::~IngredientAttribute()
{
  if(this->name){
    delete [] this->name;
    this->name = NULL;
  }
  this->weight = 0;

  if(this->children)
  {
	  for(unsigned int c = 0; c < this->childrenIndex; c++)
	  {
		if(&this->children[c])
		{
			delete this->children[c];
		}
	  }
	  delete [] children;
  }
  this->childrenIndex = 0;
}
IngredientAttribute::IngredientAttribute(const IngredientAttribute & other)
{
  this->name = other.name;
  this->weight = other.weight;

  this->childrenIndex = other.childrenIndex;
  this->children = other.children;
}
IngredientAttribute & IngredientAttribute::operator = (const IngredientAttribute & other)
{
  this->name = other.name;
  this->weight = other.weight;

  this->childrenIndex = other.childrenIndex;
  this->children = other.children;

  return *this;
}
void IngredientAttribute::setName(char * newName)
{
  if(this->name == NULL)
      this->name = new char[MAX_SIZE_INGREDIENT_ATTRIBUTE_NAME];
  strcpy(this->name, newName);
}
char * IngredientAttribute::getName()
{
  return this->name;
}
void IngredientAttribute::setWeight(unsigned int newWeight)
{
  this->weight = newWeight;
}
unsigned int IngredientAttribute::getWeight()
{
  return this->weight;
}
bool IngredientAttribute::hasAttributes()
{
  if(this->childrenIndex == 0)
    return false;
  return true;
}
unsigned int IngredientAttribute::getNumAttributes()
{
  return this->childrenIndex;
}
IngredientAttribute ** IngredientAttribute::getAttributes(unsigned int numChildren)
{
  numChildren = this->childrenIndex;
  return this->children;
}
IngredientAttribute * IngredientAttribute::getAttribute(unsigned int index)
{
  if(index >= this->childrenIndex)
    return NULL;
  return this->children[index];
}
bool IngredientAttribute::addAttribute(IngredientAttribute * newChild)
{
  if(this->childrenIndex >= MAX_SIZE_ATTRIBUTES_PER_INGREDIENT)
    return false;
  this->children[this->childrenIndex++] = newChild;
  return true;
}
bool IngredientAttribute::addAttribute(char * name, unsigned int weight)
{
  //TODO: Implementation
  return false;
}
