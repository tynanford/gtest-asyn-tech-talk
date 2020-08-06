#ifndef PORTDRIVER
#define PORTDRIVER

#include <vector>
#include <unordered_map>
#include <string>
#include "asynPortDriver.h"

class PortDriver: public asynPortDriver 
{
  public:
    //FpgaPortDriver(std::string portName, std::string cmdPortName, std::string writePortName, std::string cmdString);
    PortDriver(std::string portName);
                   
};

#endif
