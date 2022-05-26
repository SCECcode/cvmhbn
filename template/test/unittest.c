#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include "unittest_defs.h"
#include "test_vx_lite_%%cvmhbn%_exec.h"
#include "test_vx_%%cvmhbn%_exec.h"
#include "test_%%cvmhbn%_exec.h"


int main (int argc, char *argv[])
{
  char *xmldir;

  if (argc == 2) {  
    xmldir = argv[1];
  } else {
    xmldir = NULL;
  }

  /* Run test suites */
  suite_%%cvmhbn%_exec(xmldir);
  suite_vx_%%cvmhbn%_exec(xmldir);
  suite_vx_lite_%%cvmhbn%_exec(xmldir);

  return 0;
}
