# CVMH15-1-Basins (cvmhbn)

<a href="https://github.com/sceccode/cvmhbn.git"><img src="https://github.com/sceccode/cvmhbn/wiki/images/cvmhbn_logo.png"></a>

[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
![GitHub repo size](https://img.shields.io/github/repo-size/sceccode/cvmhbn)
[![cvmhbn-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhbn-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)
[![cvmhbn-ucvm-ci Actions Status](https://github.com/SCECcode/cvmhbn/workflows/cvmhbn-ucvm-ci/badge.svg)](https://github.com/SCECcode/cvmhbn/actions)


## Description

CVMH Basin is the templated base code for generate basin model access code for various CVMH basins.   

## Table of Contents
1. [Software Documentation](https://github.com/SCECcode/cvmhbn/wiki)
2. [Installation](#installation)
4. [Contributing](#contributing)
5. [Credits](#credit)
6. [License](#license)

## Installation

The base code is included as a git submodule in each target CVMH basin model git repo
(https://www.w3docs.com/learn-git/git-submodule.html)

To push updated base code from basin model,

<pre>
  git submodule update --remote
</pre>


### UCVM

As part of [UCVM](https://github.com/SCECcode/ucvm) installation, use basin label as the model.

1. cvmhlabn (Los Angeles)
2. cvmhsgbn (San Gabriel)
3. cvmhvbn  (Ventura)
4. cvmhibbn (Inner Borderland)
5. cvmhrbn  (Ridge Basin)
6. cvmhssbn (Salton Sea)
7. cvmhsbbn (San Bernadino)
8. cvmhsbcbn (Santa Barbara Channel)
9. cvmhsmbn (Santa Maria)



## Support
Support for CVMHBN is provided by the Southern California Earthquake Center
(SCEC) Research Computing Group.  Users can report issues and feature requests 
using CVMHBN's github-based issue tracking link below. Developers will also 
respond to emails sent to the SCEC software contact listed below.
1. [CVMHBN Github Issue Tracker](https://github.com/SCECcode/cvmhbn/issues)
2. Email Contact: software@scec.usc.edu

## Contributing
We welcome contributions to the CVMHBN, please contact us at software@scec.usc.edu.

## Credits
* Andreas Plesch <andreas_plesch@harvard.edu>
* John Shaw <shaw@eps.harvard.edu>

## License
This software is distributed under the BSD 3-Clause open-source license.
Please see the [LICENSE.txt](LICENSE.txt) file for more information.

