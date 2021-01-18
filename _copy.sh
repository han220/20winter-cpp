#!/bin/bash

for ((i = 1; i <= $2; i++ )); do
 cp "prob_template.cpp" "prob$1_$i.cpp"
done