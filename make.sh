#!/bin/bash

OUTPUT="game"
LIBS="-lncurses"
SRC="core.cpp loop.cpp"

echo g++ $SRC -o $OUTPUT $LIBS; g++ $SRC -o $OUTPUT $LIBS