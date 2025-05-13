# CVMH15-1-Basins (cvmhbn)

<a href="https://github.com/sceccode/cvmhbn.git"><img src="https://github.com/sceccode/cvmhbn/wiki/images/cvmhbn_plot.png"></a>

[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
![GitHub repo size](https://img.shields.io/github/repo-size/sceccode/cvmhbn)

[![cvmhlabn-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhlabn-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhlabn-ucvm-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhlabn-ucvm-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhsgbn-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhsgbn-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhsgbn-ucvm-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhsgbn-ucvm-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhvbn-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhvbn-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhvbn-ucvm-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhvbn-ucvm-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhibbn-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhibbn-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhibbn-ucvm-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhibbn-ucvm-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhrbn-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhrbn-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhrbn-ucvm-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhrbn-ucvm-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhstbn-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhstbn-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhstbn-ucvm-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhstbn-ucvm-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhsbbn-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhsbbn-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhsbbn-ucvm-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhsbbn-ucvm-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhsbcbn-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhsbcbn-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhsbcbn-ucvm-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhsbcbn-ucvm-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhsmbn-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhsmbn-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhsmbn-ucvm-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhsmbn-ucvm-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)


## Description

CVMH Basin is the templated base code for generate basin model access code for various CVMH basins.

The CVM-H basin models describe seismic P- and S-wave velocities, and densities in sedimentary basins,
based on sonic logs in wells, stacking velocities in seismic reflection surveys, and calibrated 
age-depth relationships in some basins. The base of models is the top of crystalline or metamorphic
rocks below the basins.

## Installation

After download the cvmhbn with github, to create each basin model 

<pre>
./setup/setup.sh basin_name
cd basin_name/data
./make_data_files.py
</pre>

To build each basin as a standalone installation or as part of UCVM, please follow the README within
each basin model 

### UCVM

As part of [UCVM](https://github.com/SCECcode/ucvm) installation, use basin label as the model.

1. cvmhlabn (Los Angeles)
2. cvmhsgbn (San Gabriel)
3. cvmhvbn  (Ventura)
4. cvmhibbn (Inner Borderland)
5. cvmhrbn  (Ridge Basin)
6. cvmhstbn (Salton Trough)
7. cvmhsbbn (San Bernardino)
8. cvmhsbcbn (Santa Barbara Channel)
9. cvmhsmbn (Santa Maria)


## Contact the authors

If you would like to contact the authors regarding this software,
please e-mail software@scec.org. Note this e-mail address should
be used for questions regarding the software itself (e.g. how
do I link the library properly?). Questions regarding the model's
science (e.g. on what paper is the CVMH basin models based?) should be directed
to the model's authors, located in the AUTHORS file.


