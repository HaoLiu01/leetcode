import os

env = Environment(CC='g++', CPPPATH = '.')

env.Append(CPPPATH = '/include')
env.Append(CCFLAGS = ['-O0', '-g'])


srcs = Glob('Source/*.cpp')
objs = env.Object(srcs) 
env.Program('test', objs)
