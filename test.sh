#!/bin/bash
# Shell script to demonstrate the converter program

echo ""
echo "========== Base Converter Test =========="
echo ""

# Create test input
echo "Testing with values: 5, -5, 255, -128, 1024"

# Run tests
echo "1" | ./bin/converter.exe << EOF
5
1
-5
1
255
1
-128
1
1024
4
EOF
