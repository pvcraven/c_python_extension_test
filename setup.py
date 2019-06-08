from distutils.core import setup, Extension

ext = Extension('arcade.native', ['native_object2.c'])

setup(name = 'arcade', version = '1.0', ext_modules = [ext])
