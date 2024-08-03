#pragma once

#include <headers/limine.h>
#include <flanterm/flanterm.h>
#include <flanterm/backends/fb.h>
#include "string.h"
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include <limits.h>

void print_init(struct limine_framebuffer_request);

int print_ch(int);

int print(const char* __restrict, ...);