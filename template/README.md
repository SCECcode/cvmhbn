# %%CVMHBN_MODEL% (%%cvmhbn%)

<a href="https://github.com/SCECcode/%%cvmhbn%.git"><img src="https://github.com/SCECcode/cvmhbn/wiki/images/%%cvmhbn%_logo.png"></a>

[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)


## Description

%%CVMHBN_MODEL%

## Table of Contents
1. [Software Documentation](https://github.com/SCECcode/cvmhbn/wiki)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Contributing](#contributing)
5. [Credits](#credit)
6. [License](#license)

## Installation
This package is intended to be installed as part of the UCVM framework,
version 22.7 or higher. 

This package can also be build as a standalone program

<pre>
aclocal
automake --add-missing
autoconf
./configure --prefix=/path/to/install
cd data; ./make_data_files.py 
make
make install
</pre>

## Usage

### UCVM

As part of [UCVM](https://github.com/SCECcode/ucvm) installation, use '%%cvmhbn%' as the model.

### vx_lite_%%cvmhbn%

A command line program accepts Geographic Coordinates or UTM Zone 11 to extract velocity values
from %%CVMHBN%.

## Support
Support for %%CVMHBN% is provided by the Southern California Earthquake Center
(SCEC) Research Computing Group.  Users can report issues and feature requests 
using %%CVMHBN%'s github-based issue tracking link below. Developers will also 
respond to emails sent to the SCEC software contact listed below.
1. [%%CVMHBN% Github Issue Tracker](https://github.com/SCECcode/cvmhbn/issues)
2. Email Contact: software@scec.usc.edu

## Contributing
We welcome contributions to the %%CVMHBN%, please contact us at software@scec.usc.edu.

## Credits
* Andreas Plesch <andreas_plesch@harvard.edu>
* John Shaw <shaw@eps.harvard.edu>

## License
This software is distributed under the BSD 3-Clause open-source license.
Please see the [LICENSE.txt](LICENSE.txt) file for more information.

