/*
 * Copyright 2022 ICE9 Consulting LLC
 */

#ifndef __BURST_CATCHER_H__
#define __BURST_CATCHER_H__

#include "fsk.h"

// burst processing, one per channel
typedef struct _burst_catcher_t {
    unsigned freq;
    agc_crcf agc;
    float complex *burst;
    unsigned burst_len;
    unsigned burst_buf_size;
    unsigned burst_num;
} burst_catcher_t;

typedef struct _burst_t {
    float complex *burst;
    unsigned len;
    unsigned freq;
    packet_t packet;
    unsigned num;
    // TODO timestamp or sample num?
} burst_t;

typedef struct _burst_catcher_t burst_catcher_t;

void burst_catcher_create(burst_catcher_t *c, unsigned freq);
void burst_catcher_destroy(burst_catcher_t *c);
int burst_catcher_execute(burst_catcher_t *c, float complex *sample, burst_t *burst_out);
void burst_destroy(burst_t *b);

#endif
