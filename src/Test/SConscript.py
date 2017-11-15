#!python
import SCons.Script
from SCons.Environment import Environment
# ---
import os

Import('env')

# Load and Compile all *.cpp file
srcFiles = ['outputTest.cpp']
objFiles = env.Object(srcFiles)

# Unit tests
Import('testEnv')
# Add file with unit tests
#testEnv.addUnitTest(['test/TestTest.cpp'] + objFiles + testEnv['DATALIB'] + testEnv['ALGOLIB'])

srcFiles = ['test.cpp']
objFiles = env.Object(srcFiles) + objFiles


# Get the name of current directory, which will be the default name for the library
dirPath = os.getcwd()
dirName = os.path.basename(dirPath)

# Rename the new library if you do not want a default name
libFiles = env.Library(dirName, objFiles)
Return('libFiles')
