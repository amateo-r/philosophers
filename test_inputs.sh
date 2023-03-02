#!/bin/bash

echo Incorrect input arguments
./philosophers
./philosophers 400
./philosophers 400 400
./philosophers 400 400 400
./philosophers 400 400 400 400 400 400

echo BIG number uwu
./philosophers 400000000000000000000000000000 400 400 400
./philosophers 400 400000000000000000000000000000 400 400
./philosophers 400 400 400000000000000000000000000000 400
./philosophers 400 400 400 400000000000000000000000000000
./philosophers 400 400 400 400 400000000000000000000000000000

echo Negative numbers
./philosophers -400 400 400 400
./philosophers 400 -400 400 400
./philosophers 400 400 400 -400
./philosophers 400 400 400 400 -400
./philosophers -400 -400 -400 -400
./philosophers -400 -400 -400 -400 -400

echo Not numeric arguments
./philosophers 1a32 400 400 400
./philosophers 400 -50f.34 400 400
./philosophers 400 400 0.4 400
./philosophers 400 400 400 .
./philosophers 400 400 . 400
./philosophers aaa 400 400 400
