// sample.h
#ifndef SAMPLE_H
#define SAMPLE_H

// extern "C" int add(int a, int b);

#if defined(__cplusplus)
extern "C" int add(int a, int b);
#else
int add(int a, int b);
#endif

#endif
