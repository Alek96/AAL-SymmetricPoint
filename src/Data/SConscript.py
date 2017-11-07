#!python
import SCons.Script
from SCons.Environment import Environment
# ---
import os

Import('env')

# Load and Compile all *.cpp file
#srcFiles = Glob('*.cpp')
srcFiles = ['pointData.cpp']
objFiles = env.Object(srcFiles)

# Unit tests
Import('testEnv')
# Add file with unit tests
testEnv.addUnitTest(['test/pointDataTest.cpp'] + objFiles)


srcFiles = ['rectangle.cpp']
objRec = env.Object(srcFiles)
testEnv.addUnitTest(['test/rectangleTest.cpp'] + objRec)
objFiles = objFiles + objRec;


srcFiles = ['rectangleData.cpp']
objFiles = env.Object(srcFiles) + objFiles
testEnv.addUnitTest(['test/rectangleDataTest.cpp'] + objFiles)




# Get the name of current directory, which will be the default name for the library
dirPath = os.getcwd()
dirName = os.path.basename(dirPath)

# Rename the new library if you do not want a default name
libFiles = env.Library(dirName, objFiles)

# Add this library to global values
testEnv.SetDefault(DATALIB = libFiles)

Return('libFiles')
