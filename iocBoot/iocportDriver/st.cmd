#!../../bin/linux-x86_64/portDriver

#- You may have to change portDriver to something else
#- everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/portDriver.dbd"
portDriver_registerRecordDeviceDriver pdbbase

portDriverConfigure("asynPortTestMe!!")

## Load record instances
dbLoadRecords("db/main.db", "P=IOCPREFIX")

cd "${TOP}/iocBoot/${IOC}"
iocInit
