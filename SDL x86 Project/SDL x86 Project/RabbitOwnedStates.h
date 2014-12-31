#pragma once
#include "State.h"
class Rabbit;

//------------------------------------------------------------------------
//
//  Koe zal achter de haas aan gaan om deze proberen te vangen
//  
//------------------------------------------------------------------------
class FleeFromCow : public State<Rabbit>
{
private:
  
  FleeFromCow(){}

  //copy ctor and assignment should be private
  FleeFromCow(const FleeFromCow&);
  FleeFromCow& operator=(const FleeFromCow&);
 
public:

  //this is a singleton
  static FleeFromCow* Instance();

  virtual void Enter(Rabbit* rabbit);

  virtual void Execute(Rabbit* rabbit);

  virtual void Exit(Rabbit* rabbit);
};


