from setuptools import setup, Extension
import sys
import os

python_include = os.path.join(sys.exec_prefix, 'include')
python_lib = os.path.join(sys.exec_prefix, 'libs')

module = Extension(
    'zeroArray',
    sources=['Source.cpp'],
    include_dirs=[python_include],
    library_dirs=[python_lib],
    libraries=['python' + sys.version[:3].replace('.', '')], 
    language='c++'
)

setup(
    name='zeroArray',
    version='1.0',
    ext_modules=[module]
)
