#ifndef __RAYTRACING_H
#define __RAYTRACING_H

#include "objects.h"
#include <stdint.h>

#define THREAD_NUM 128

typedef struct THREAD_CONTENT{

	uint8_t *pixels;
        double *background_color;//
        rectangular_node rectangulars;
        sphere_node spheres;
        light_node lights;
        const viewpoint *view;

        int width;
        int height;
	
	double *u;//
   	double *v;//
	double *w;//
	double *d;//
	
	int factor;
}Thread_Content;

typedef struct THREAD_ARG{

	int start_;
	int end_;
	Thread_Content* tc_;
}Thread_Arg;


void *thread_function(void *arg_);
void parallel(uint8_t *pixels, double* background_color,
                            rectangular_node rectangulars, sphere_node spheres,
                            light_node lights, const viewpoint *view,
                            int width, int height, double *u, double* v, double* w, double* d, int factor);
void raytracing(uint8_t *pixels, color background_color,
                rectangular_node rectangulars, sphere_node spheres,
                light_node lights, const viewpoint *view,
                int width, int height);


#endif
