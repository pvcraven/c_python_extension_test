from distutils.core import setup, Extension

ext = Extension('arcade.native', ['sprite_list.c', 'sprite.c', 'register.c'])

setup(name='arcade', version='1.0', ext_modules=[ext])
