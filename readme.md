# Mitral Cell Example
This repository contains the Neuron and Arbor implementation of a model of two electrically connected mitral cells based on the work of Migliore M, Hines ML, Shepherd GM (2005)[1].

The original Neuron code can be found [here](https://senselab.med.yale.edu/ModelDB/showmodel.cshtml?model=43039#tabs-1)  

The Neuron code has been extended to allow:
1) Moving the stimulus from the tuft to the soma.
2) Printing the voltages measured at the soma to file.

The hillocks of the cells have been changed to cylindrical segments instead of a tapering segments. This was done to allow a more faithful comparison between Neuron and Arbor's results as they implement tapering segments differently. 

## Running the examples

### Arbor:
**Installing Arbor**: 
* Install Arbor from the following branch: 
https://github.com/noraabiakar/arbor/tree/mitral
* For help installing Arbor refer to:
https://arbor.readthedocs.io/en/latest/install.html

**Compiling the example**: 
```
$ cd mitral_arbor
$ mkdir build && cd build
$ cmake .. -DCMAKE_INSTALL_PREFIX=/path/to/arbor/installation -DCMAKE_BUILD_TYPE=release
$ make mitral
``` 

**Running the example**: 

* Stim at the soma - with no GJ
```
$ ./arbor-mitral ../inputs/no_gj.json
```

* Stim at the soma - with GJ
```
$ ./arbor-mitral ../inputs/reg_gj.json
```

* Stim at the soma - with GJ & Na+ block
```
$ ./arbor-mitral ../inputs/tweak_gj.json
```

* Stim at the tuft - with no GJ
```
$ ./arbor-mitral ../inputs/tuft_no_gj.json
```

* Stim at the tuft - with GJ
```
$ ./arbor-mitral ../inputs/tuft_reg_gj.json
```

* Stim at the tuft - with GJ & Na+ block
```
$ ./arbor-mitral ../inputs/tuft_tweak_gj.json
```

**Plotting the results**: 

* Running the examples will generate two .json files: *arb_cell0_v.json* and *arb_cell1_v.json*. To plot the results, you can use the provided **tsplot** script:
```
python2 tsplot /path/to/arb_cell0_v.json /path/to/arb_cell1_v.json -g units
```

### Neuron:

**Running the example**:
```
$ cd mitral_neuron
$ nrnivmodl
$ nrngui forfig6-modeldb.hoc
```

Select one of the 6 available options: 
* Stim at the soma - with no GJ
* Stim at the soma - with GJ
* Stim at the soma - with GJ & Na+ block
* Stim at the tuft - with no GJ
* Stim at the tuft - with GJ
* Stim at the tuft - with GJ & Na+ block

These 6 options correspond to the 6 previously mentioned arbor options 

**Plotting the results**:

Running the examples will generate four .dat files: *nrn_cell0_t.dat* and *nrn_cell0_v.dat* corresponding to the time and voltage measurements of the first cell;
and *nrn_cell1_t.dat* and *nrn_cell1_v.dat* corresponding to the time and voltage measurements of the second cell.
The files need to be modified to be plotted by tsplot. For this, the jsonify.py script is used. (First argument is the time measurements, second argument is the voltage measurements and third argument is the output .json file)
```
$ python jsonify.py nrn_cell0_t.dat nrn_cell0_v.dat nrn_cell0_v.json
$ python jsonify.py nrn_cell1_t.dat nrn_cell1_v.dat nrn_cell1_v.json
```

To plot the results, you can use the provided **tsplot** script:
```
$ python2 tsplot /path/to/nrn_cell0_v.json /path/to/nrn_cell1_v.json -g units
```

All 6 plots of the Arbor and Neuron results can be found in the plots directory
 
*1 . Migliore M, Hines ML, Shepherd GM (2005) The role of distal dendritic gap junctions in synchronization of mitral cell axonal output. J Comput Neurosci 18:151-61*