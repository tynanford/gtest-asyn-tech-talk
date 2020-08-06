TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = portDriver
# portDriver.dbd will be created and installed
DBD += portDriver.dbd

LIBRARY_IOC += portDriverSupport
portDriverSupport_SRCS += portDriver.cpp

# portDriver.dbd will be made up from these files:
portDriver_DBD += base.dbd

USR_CXXFLAGS += -std=c++11

# Include dbd files from all support applications:
#portDriver_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
portDriver_LIBS += asyn 
portDriver_LIBS += portDriverSupport 

# portDriver_registerRecordDeviceDriver.cpp derives from portDriver.dbd
portDriver_SRCS += portDriver_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
portDriver_SRCS_DEFAULT += portDriverMain.cpp
portDriver_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#portDriver_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
portDriver_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

