#ifndef %%CVMHBN%_H
#define %%CVMHBN%_H

/**
 * @file %%cvmhbn%.h
 * @brief Main header file for %%CVMHBN% library.
 * @author - SCEC 
 * @version 1.0
 *
 * Delivers CVMH %%CVMHBN_MODEL%
 *
 */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdarg.h>

#include "vx_sub_%%cvmhbn%.h"

// Constants
#ifndef M_PI
	/** Defines pi */
	#define M_PI 3.14159265358979323846
#endif

#define VX_NO_DATA -99999.0
#define %%CVMHBN%_CONFIG_MAX 1000

// Structures
/** Defines a point (latitude, longitude, and depth) in WGS84 format */
typedef struct %%cvmhbn%_point_t {
	/** Longitude member of the point */
	double longitude;
	/** Latitude member of the point */
	double latitude;
	/** Depth member of the point */
	double depth;
} %%cvmhbn%_point_t;

/** Defines the material properties this model will retrieve. */
typedef struct %%cvmhbn%_properties_t {
	/** P-wave velocity in meters per second */
	double vp;
	/** S-wave velocity in meters per second */
	double vs;
	/** Density in g/m^3 */
	double rho;
        /** NOT USED from basic_property_t */
        double qp;
        /** NOT USED from basic_property_t */
        double qs;
} %%cvmhbn%_properties_t;

/** The %%CVMHBN% configuration structure. */
typedef struct %%cvmhbn%_configuration_t {
	/** The zone of UTM projection */
	int utm_zone;
	/** The model directory */
	char model_dir[1000];
        /** interp */
	int interp;

} %%cvmhbn%_configuration_t;

/** The model structure which points to available portions of the model. */
typedef struct %%cvmhbn%_model_t {
	/** A pointer to the Vp data either in memory or disk. Null if does not exist. */
	void *vp;
	/** Vp status: 0 = not found, 1 = found and not in memory, 2 = found and in memory */
	int vp_status;
} %%cvmhbn%_model_t;

// Constants
/** The version of the model. */
extern const char *%%cvmhbn%_version_string;

/** The config of the model. */
extern char *%%cvmhbn%_config_string;
extern int %%cvmhbn%_config_sz;

// Variables
/** Set to 1 when the model is ready for query. */
extern int %%cvmhbn%_is_initialized;

/** Location of the binary data files. */
extern char %%cvmhbn%_data_directory[2000];

/** Configuration parameters. */
extern %%cvmhbn%_configuration_t *%%cvmhbn%_configuration;
/** Holds pointers to the velocity model data OR indicates it can be read from file. */
extern %%cvmhbn%_model_t *%%cvmhbn%_velocity_model;

/** The height of this model's region, in meters. */
extern double %%cvmhbn%_total_height_m;
/** The width of this model's region, in meters. */
extern double %%cvmhbn%_total_width_m;

// UCVM API Required Functions

#ifdef DYNAMIC_LIBRARY

/** Initializes the model */
int model_init(const char *dir, const char *label);
/** Cleans up the model (frees memory, etc.) */
int model_finalize();
/** Returns version information */
int model_version(char *ver, int len);
/** Returns config information */
int model_config(char **config, int *sz);
/** Queries the model */
int model_query(%%cvmhbn%_point_t *points, %%cvmhbn%_properties_t *data, int numpts);
/** Setparam */
int model_setparam(int, int, int);

#endif

// %%CVMHBN% Related Functions

/** Initializes the model */
int %%cvmhbn%_init(const char *dir, const char *label);
/** Cleans up the model (frees memory, etc.) */
int %%cvmhbn%_finalize();
/** Returns version information */
int %%cvmhbn%_version(char *ver, int len);
/** Queries the model */
int %%cvmhbn%_query(%%cvmhbn%_point_t *points, %%cvmhbn%_properties_t *data, int numpts);
/** Setparam*/
int %%cvmhbn%_setparam(int, int, ...);

// Non-UCVM Helper Functions
/** Reads the configuration file. */
int %%cvmhbn%_read_configuration(char *file, %%cvmhbn%_configuration_t *config);
void %%cvmhbn%_print_error(char *err);
int %%cvmhbn%_setzmode(char* z);

#endif
