#!python

# These import lines are not really needed, but it helps intellisense within VS when editing the script
import SCons.Script
from SCons.Environment import Environment
# ---
from shutil import copyfile
import os.path
import os

env = Environment(TARGET_ARCH= 'x86')	# Create an environmnet for 32 bit version
# Make env global
Export('env')

# This will be shown with flag -h
Help('''
usage: scons [OPTION] ...

SCons Options (case insensitive):
  release=1             Build the release version
  verbose=1             Build with all information

 unit test:
  test                  Build all unit tests
  testName              Build single unit test called 'testName'
  test=on               Turns on building unit tests (default)
  test=off              Turns off building unit tests
  test=all              Run all unit tests
  test=testName         Run unit tests whose name contains 'testName'

''')

# Keys to lower case (for case insensitiveness)
ARGUMENTS = dict((k.lower(), v) for (k,v) in ARGUMENTS.items())
# Generator expressions, see: https://www.python.org/dev/peps/pep-0289/

class bcolors:
	CYAN = '\033[36m'
	LRED = '\033[91m'
	LGREEN = '\033[92m'
	LYELLOW = '\033[93m'
	LBLUE = '\033[94m'
	LMAGENTA = '\033[95m'
	LCYAN = '\033[96m'
	ENDC = '\033[0m'
	BOLD = '\033[1m'
	UNDERLINE = '\033[4m'

# Replace long comment for short version
if ARGUMENTS.get('verbose') != '1':
	env.Append(CCCOMSTR =   [bcolors.CYAN + 'Compiling '  + bcolors.ENDC + '$TARGET'])
	env.Append(CXXCOMSTR =  [bcolors.CYAN + 'Compiling '  + bcolors.ENDC + '$TARGET'])
	env.Append(ARCOMSTR =   [bcolors.LCYAN + 'Archiving ' + bcolors.ENDC + '$TARGET'])
	env.Append(LINKCOMSTR = [bcolors.LBLUE + 'Linking '   + bcolors.ENDC + '$TARGET'])

# Get current path
ProjectBase = [os.getcwd()]
env.Append(CPPPATH = ProjectBase)

# Detect the build mode
platform = ARGUMENTS.get('os', Platform())
if ARGUMENTS.get('release', '0') == '1':
	variant = 'Release'
else:
	variant = 'Debug'

# Add flags for detected platform and build mode
if platform.name == 'win32':
	if variant == 'Debug':
		env.Append(CPPDEFINES = ['DEBUG', '_DEBUG'])
		env.Append(CCFLAGS=['-W3', '-EHsc', '-D_DEBUG', '/MDd', '/Z7'])
		#env.Append(CCPDBFLAGS=['/Zi', '/Fd${TARGET}.pdb'])
		env.Append(LINKFLAGS = ['/DEBUG', '/INCREMENTAL:NO'])
	else:
		env.Append(CPPDEFINES = ['NDEBUG'])
		env.Append(CCFLAGS=['-O2', '-EHsc', '-DNDEBUG', '/MD'])
else:	#posix and linux
	env.Append(CCFLAGS=['-std=c++14'])
	env.Append(ARFLAGS=['-T'])
	if variant == 'Debug':
		env.Append(CCFLAGS=['-g'])


# Initial unit test
testEnv = env.Clone()
Export('testEnv')
testEnv.SConscript('src/UnitTest/SConscript.py', variant_dir='build/'+variant+'/UnitTest', duplicate=0)
# Save argument in testEnv
testEnv.SetDefault(test = [ARGUMENTS.get('test', 'on')])

# Hierarchical Builds
if not GetOption('help'):
	env.SConscript('src/SConscript.py', variant_dir='build/'+variant, duplicate=0)
