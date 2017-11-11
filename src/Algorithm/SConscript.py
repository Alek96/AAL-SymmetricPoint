#!python
import SCons.Script
from SCons.Environment import Environment
# ---
import os

Import('env')

# Load and Compile all *.cpp file
srcFiles = ['brut.cpp']
objFiles = env.Object(srcFiles)

# Unit tests
Import('testEnv')
# Add file with unit tests
testEnv.addUnitTest(['test/brutTest.cpp'] + objFiles + testEnv['DATALIB'])

srcFiles = ['generator.cpp']
objGen = env.Object(srcFiles)
testEnv.addUnitTest(['test/generatorTest.cpp'] + objGen + testEnv['DATALIB'])
objFiles = objFiles + objGen;

srcFiles = ['heurystyka.cpp']
objHeur = env.Object(srcFiles)
testEnv.addUnitTest(['test/heurystykaTest.cpp'] + objHeur + testEnv['DATALIB'])
objFiles = objFiles + objHeur;

# Get the name of current directory, which will be the default name for the library
dirPath = os.getcwd()
dirName = os.path.basename(dirPath)

# Rename the new library if you do not want a default name
libFiles = env.Library(dirName, objFiles)

# Add this library to global values
testEnv.SetDefault(ALGOLIB = libFiles)

Return('libFiles')
