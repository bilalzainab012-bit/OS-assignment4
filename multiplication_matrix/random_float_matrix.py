#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# This script generates test matrices of the given dimensions and
# outputs them to stdout. Elements are separated by '\t'.
#
# Usage:
#   ./gen_matrices.py 4 4
#
# Author: Adapted from Philipp Böhm

import sys
import random

# Parse matrix dimensions from command line
try:
    dim_x, dim_y = int(sys.argv[1]), int(sys.argv[2])
except Exception:
    sys.stderr.write("Error parsing matrix dimensions.\n")
    sys.exit(1)

# Generate and print matrix
for _ in range(dim_x):
    row = "\t".join([str(random.uniform(0, 9999)) for _ in range(dim_y)])
    print(row)

