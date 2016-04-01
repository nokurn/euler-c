/*
 * Project Euler in C
 * Copyright (c) Jeremiah Griffin 2016
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "timer.h"
#include <mach/clock.h>
#include <mach/mach.h>

static clock_serv_t clock_serv;

void eu_timer_init() {
    host_get_clock_service(mach_host_self(), SYSTEM_CLOCK, &clock_serv);
}

void eu_timer_fini() {
    mach_port_deallocate(mach_task_self(), clock_serv);
}

eu_nsec_t eu_timer_nsec() {
    mach_timespec_t ts;
    clock_get_time(clock_serv, &ts);
    return (eu_nsec_t)ts.tv_sec * 1000000000 + (eu_nsec_t)ts.tv_nsec;
}