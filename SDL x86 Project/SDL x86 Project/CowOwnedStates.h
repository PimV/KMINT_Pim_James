#pragma once
#include "State.h"
class Cow;

//------------------------------------------------------------------------
//
//  Koe zal achter de haas aan gaan om deze proberen te vangen
//  
//------------------------------------------------------------------------
class ChaseRabbit : public State<Cow>
{
private:
  
  ChaseRabbit(){}

  //copy ctor and assignment should be private
  ChaseRabbit(const ChaseRabbit&);
  ChaseRabbit& operator=(const ChaseRabbit&);
 
public:

  //this is a singleton
  static ChaseRabbit* Instance();

  virtual void Enter(Cow* Cow);

  virtual void Execute(Cow* Cow);

  virtual void Exit(Cow* Cow);
};

//------------------------------------------------------------------------
//
//  De koe zal doelloos rondlopen
//  
//------------------------------------------------------------------------
class WanderAround : public State<Cow>
{
private:
  
  WanderAround(){}

  //copy ctor and assignment should be private
  WanderAround(const WanderAround&);
  WanderAround& operator=(const WanderAround&);

  int updateDelay;
  int updatesSince;
 
public:

  //this is a singleton
  static WanderAround* Instance();

  virtual void Enter(Cow* Cow);

  virtual void Execute(Cow* Cow);

  virtual void Exit(Cow* Cow);
};

//------------------------------------------------------------------------
//
//  De koe zal vertouwen gaan zoeken door de pil proberen te bemachtigen
//  
//------------------------------------------------------------------------
class FindPill : public State<Cow>
{
private:
  
  FindPill(){}

  //copy ctor and assignment should be private
  FindPill(const FindPill&);
  FindPill& operator=(const FindPill&);
 
public:

  //this is a singleton
  static FindPill* Instance();

  virtual void Enter(Cow* Cow);

  virtual void Execute(Cow* Cow);

  virtual void Exit(Cow* Cow);
};

