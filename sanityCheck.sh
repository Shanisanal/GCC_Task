#!/bin/bash

REPORT="report.txt"
TARGET="./appTimer.exe"

echo "===== Sanity Check Report =====" > $REPORT
echo "Generated on: $(date +%F)" >> $REPORT
echo "------------------------------" >> $REPORT

# Checkout the develop branch
echo ">>> Pulling latest code..." | tee -a $REPORT
git checkout develop >> $REPORT 2>&1

# Pull the latest code
git pull origin develop >> $REPORT 2>&1
echo "" >> $REPORT

#do static analysis
echo ">>> Running static analysis (cppcheck)..." | tee -a $REPORT
cppcheck -I /usr/include --std=c99 --quiet --enable=warning \
    --error-exitcode=1 --suppress=toomanyconfigs . >> $REPORT 2>&1
echo "" >> $REPORT

# Clean previous builds
echo ">>> Building project..." | tee -a $REPORT
make clean >> $REPORT 2>&1

# Build the project
make >> $REPORT 2>&1
BUILD_STATUS=$?

if [ $BUILD_STATUS -ne 0 ]; then
    echo "Build failed" | tee -a $REPORT
    echo "Check report.txt for details" 
    exit 1
else
    echo "Build succeeded." | tee -a $REPORT
fi
echo "" >> $REPORT

#Do Dynamic analysis
echo ">>> Running Dynamic Analysis (Valgrind)..." | tee -a $REPORT
if [ -f "$TARGET" ]; then
    timeout 5s valgrind --leak-check=full --show-leak-kinds=all \
     --errors-for-leak-kinds=definite --error-exitcode=1 \
    $TARGET >> $REPORT 2>&1
    
    VALGRIND_RESULT=$?
    if [ $VALGRIND_RESULT -eq 0 ]; then
        echo "No memory leaks detected." | tee -a $REPORT
    elif [ $VALGRIND_RESULT -eq 124 ]; then
        echo "Test timed out " | tee -a $REPORT
        echo "Check report.txt for valgrind result summary" 
    else
        echo "Memory leaks or errors detected!" | tee -a $REPORT
        echo "Check report.txt for leak summary " 
    fi
else
    echo "Error: $TARGET not found. Build may have failed." | tee -a $REPORT
fi
echo "" >> $REPORT

echo "===== End of Report =====" | tee -a $REPORT





