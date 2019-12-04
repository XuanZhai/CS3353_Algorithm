#ifndef ALGORITHM_H
#define ALGORITHM_H



#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

 class Algorithm{

 public:
     virtual void Load(std::string) = 0;
     virtual void Execute() = 0;
     virtual void Select(int) = 0;
 };


 #endif
