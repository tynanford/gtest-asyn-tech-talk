#include <iocsh.h>
#include <epicsExport.h>


#include "portDriver.h"


// UDP Driver to handle sending and receiving packets and writing and reading from PVs 
// Inherited from asynPortDriver 
// Parameters
//  portName
PortDriver::PortDriver(std::string portName)
  : asynPortDriver(portName.c_str(),
      1, // maxAddr 
      asynInt32Mask | asynUInt32DigitalMask | asynDrvUserMask, // interface mask
      asynInt32Mask | asynUInt32DigitalMask, // interrupt mask
      ASYN_CANBLOCK, // asyn flags
      1, // autoConnect
      0, //priority
      0 // stackSize
    )
{
  std::string message = "Hello from portName: " + portName;
  asynPrint(pasynUserSelf, ASYN_TRACE_ERROR, message.c_str());

}



// Configuration routine.  Called directly from st.cmd, or from the iocsh function below

extern "C" {
  // EPICS iocsh callable function to call constructor for the PortDriver class.
  //   param[in] portName The name of the asyn port driver to be created. 
  int portDriverConfigure(const char *portName)
  {
      new PortDriver(portName);

      return(asynSuccess);
  }

  // EPICS iocsh shell commands
  static const iocshArg initArg0 = { "portName", iocshArgString };

  static const iocshArg * const initArgs[] = { &initArg0 };
  static const iocshFuncDef initFuncDef = { "portDriverConfigure", 1, initArgs };
  static void initCallFunc(const iocshArgBuf *args)
  {
      portDriverConfigure(args[0].sval);
  }
  void portDriverRegister(void)
  {
      iocshRegister(&initFuncDef,initCallFunc);
  }
  epicsExportRegistrar(portDriverRegister);
}

