#!/bin/bash
g++ TreapTest.cpp
./a.out >tmp.out
if diff treap.out tmp.out
then
    echo "PASSED"
else
    echo "FAILED"
fi
