import setuptools
from distutils.core import setup, Extension

ext = Extension('arcade_native', ['sprite_list.c', 'sprite.c', 'register.c'])

setup(name='arcade_native', version='1.0', ext_modules=[ext])
