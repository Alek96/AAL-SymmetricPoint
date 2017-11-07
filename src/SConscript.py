#!python
import SCons.Script
from SCons.Environment import Environment
# ---

Import('env')

# Run SConscript files
libFiles = SConscript(Split('''
    Data/SConscript.py
    Algorithm/SConscript.py
	'''))

#Load and Compile main
objFiles = env.Object('main.cpp')

#Make new library
#libFiles = env.Library('Project', libFiles)

#Link program
env.Program(target = '#bin/Project', source = objFiles + libFiles)
