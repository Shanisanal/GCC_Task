#!/bin/bash

# Checkout the develop branch
git checkout develop

# Pull the latest code
git pull origin develop

# Clean previous builds
make clean

# Build the project
make