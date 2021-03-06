#!python
import SCons.Script
from SCons.Environment import Environment
# ---
import os

Import('env')

srcFiles = ['rectangle.cpp']
objFiles = env.Object(srcFiles)
# Unit tests
Import('testEnv')
# Add file with unit tests
testEnv.addUnitTest(['test/rectangleTest.cpp'] + objFiles)

srcFiles = ['pointData.cpp']
objFiles = env.Object(srcFiles) + objFiles
testEnv.addUnitTest(['test/pointDataTest.cpp'] + objFiles)

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
