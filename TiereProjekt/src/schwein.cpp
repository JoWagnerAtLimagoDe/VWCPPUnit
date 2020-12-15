#include "schwein.h"

using namespace tiere;

schwein::schwein(std::string name) : gewicht(10)
{
    this->setName(name);
}

void schwein::fressen(){
    ++gewicht;
}

void schwein::setName(std::string &name){
    if (name == "Elsa") throw std::exception();
    this->name = name;
}

std::string schwein::getName() const {
    return name;
}

int schwein::getGewicht() const{
    return gewicht;
}
