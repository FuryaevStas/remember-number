#!/bin/bash

OUTPUT=game
LIBS=ncurses
SRC="core.cpp render.cpp"

echo g++ $SRC -o $OUTPUT -l $LIBS; g++ $SRC -o $OUTPUT -l $LIBS