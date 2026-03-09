#!/bin/bash

# Checkout the develop branch
git checkout develop

# Pull the latest code
git pull origin develop

#do static analysis
cppcheck -I /usr/include --std=c99 --quiet --enable=warning --error-exitcode=1 --suppress=toomanyconfigs .

# Clean previous builds
make clean

# Build the project
make



