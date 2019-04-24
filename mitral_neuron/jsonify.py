#!/usr/bin/python

import sys
import os

#first argument is the time steps
#second argument is the voltage measurements
#third argument is the output json file

fout = open(sys.argv[3], "w")
fin0 = open(sys.argv[1], "r")
fin1 = open(sys.argv[2], "r")

fout.write("{\n  \"mitral_neuron_cell\": \"0\",\n  \"data\": {\n   \"time\": [\n")

t_lines = []
for line in fin0:
    newline = line.strip('\n')
    if newline:
        newline = newline + ',\n'
        t_lines.append(newline)

last_line = (t_lines[-1]).strip(',\n')
t_lines[-1] = last_line 
fout.writelines(t_lines)

fout.write("],\n\"voltage\": [\n")

v_lines = []
for line in fin1:
    newline = line.strip('\n')
    if newline:
        newline = newline + ',\n'
        v_lines.append(newline)

last_line = (v_lines[-1]).strip(',\n')
v_lines[-1] = last_line
fout.writelines(v_lines)

fout.write("]\n },\n \"units\": \"mV\",\n \"name\": \"neuron\"\n}")
