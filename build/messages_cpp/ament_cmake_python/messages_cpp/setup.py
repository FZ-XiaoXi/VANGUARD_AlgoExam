from setuptools import find_packages
from setuptools import setup

setup(
    name='messages_cpp',
    version='0.0.0',
    packages=find_packages(
        include=('messages_cpp', 'messages_cpp.*')),
)
