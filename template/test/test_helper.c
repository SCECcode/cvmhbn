/** 
   test_helper.c
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "unittest_defs.h"
#include "test_helper.h"

int debug_mode=0;

double get_preset_ucvm_surface(double y, double x) {
   if(y == -118.1 && x == 34.0) {
      return 55.827;
   }
   return 0;
}

/*************************************************************************/
int run%%CVMHBN%(const char *bindir, const char *cvmdir, 
	  const char *infile, const char *outfile, int mode)
{
  %%cvmhbn%_point_t pt;
  %%cvmhbn%_properties_t ret;

  FILE *infp, *outfp;
  char line[1000];

  char *envstr=getenv("UCVM_INSTALL_PATH");
  if(envstr != NULL) {
    if (test_assert_int(model_init(envstr, "%%cvmhbn%"), 0) != 0) {
      return(1);
    }
  } else if (test_assert_int(model_init("..", "%%cvmhbn%"), 0) != 0) {
    return(1);
  }

  int zmode = UCVM_COORD_GEO_ELEV;
  switch (mode) {
    case MODE_ELEVATION:
      zmode = UCVM_COORD_GEO_ELEV;
      break;
    case MODE_DEPTH:
      zmode = UCVM_COORD_GEO_DEPTH;
      break;
    case MODE_NONE:
      break; // default
  }

  if (test_assert_int(model_setparam(0, UCVM_PARAM_QUERY_MODE, zmode), 0) != 0) {
      return(1);
  }

  /* open infile, outfile */
  infp = fopen(infile, "r");
  if (infp == NULL) {
    printf("FAIL: cannot open %s\n", infile);
    return(1);
  }
  outfp = fopen(outfile, "w");
  if (outfp == NULL) {
    printf("FAIL: cannot open %s\n", outfile);
    return(1);
  }

/* process one term at a time */
  while(fgets(line, 1000, infp) != NULL) {
    if(line[0] == '#') continue; // a comment 
    if (sscanf(line,"%lf %lf %lf",
         &pt.longitude,&pt.latitude,&pt.depth) == 3) {
      if (test_assert_int(model_query(&pt, &ret, 1), 0) == 0) {
         fprintf(outfp,"%lf %lf %lf\n",ret.vs, ret.vp, ret.rho);
      }
    }
  }
  fclose(infp);
  fclose(outfp);
                
  if (test_assert_int(model_finalize(),0) != 0) {
      return(1);
  }

  return(0);
}

int runVX%%CVMHBN%(const char *bindir, const char *cvmdir, 
	  const char *infile, const char *outfile, int mode)
{
  char currentdir[1280];
  char runpath[1280];
  char flags[1280]="";

  sprintf(runpath, "%s/run_vx_%%cvmhbn%.sh", bindir);

  switch (mode) {
    case MODE_ELEVATION:
      sprintf(flags, "-z elev ");
      break;
    case MODE_DEPTH:
      sprintf(flags, "-z dep ");
      break;
  }

  if(debug_mode) { strcat(flags, "-g "); }

  /* Save current directory */
  getcwd(currentdir, 1280);
  
  /* Fork process */
  pid_t pid;
  pid = fork();
  if (pid == -1) {
    perror("fork");
    return(1);
  } else if (pid == 0) {
    /* Change dir to cvmdir */
    if (chdir(bindir) != 0) {
      printf("FAIL: Error changing dir in run_vx_%%cvmhbn%.sh\n");
      return(1);
    }

    if (strlen(flags) == 0) {
      execl(runpath, runpath, infile, outfile, (char *)0);
    } else {
      execl(runpath, runpath, flags, infile, outfile, (char *)0);
    }

    perror("execl"); /* shall never get to here */
    printf("FAIL: CVM exited abnormally\n");
    return(1);
  } else {
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
      return(0);
    } else {
      printf("FAIL: CVM exited abnormally\n");
      return(1);
    }
  }

  return(0);
}


int runVXLite%%CVMHBN%(const char *bindir, const char *cvmdir, 
	      const char *infile, const char *outfile,
	      int mode)
{
  char currentdir[1280];
  char flags[1280]="";

  char runpath[1280];

  sprintf(runpath, "./run_vx_lite_%%cvmhbn%.sh");

  sprintf(flags, "-m %s ", cvmdir);

  switch (mode) {
     case MODE_ELEVATION:
       strcat(flags, "-z elev ");
       break;
     case MODE_DEPTH:
       strcat(flags, "-z dep ");
       break;
  }

  if(debug_mode) { strcat(flags, "-g "); }

  /* Save current directory */
  getcwd(currentdir, 1280);
  
  /* Fork process */
  pid_t pid;
  pid = fork();
  if (pid == -1) {
    perror("fork");
    printf("FAIL: unable to fork\n");
    return(1);
  } else if (pid == 0) {

    /* Change dir to bindir */
    if (chdir(bindir) != 0) {
      printf("FAIL: Error changing dir in run_vx_lite_%%cvmhbn%.sh\n");
      return(1);
    }

    if (strlen(flags) == 0) {
      execl(runpath, runpath, infile, outfile, (char *)0);
    } else {
      execl(runpath, runpath, flags, infile, outfile, (char *)0);
    }
    perror("execl"); /* shall never get to here */
    printf("FAIL: CVM exited abnormally\n");
    return(1);
  } else {
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
      return(0);
    } else {
      printf("FAIL: CVM exited abnormally\n");
      return(1);
    }
  }

  return(0);
}
