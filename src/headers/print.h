#pragma once

#include <headers/limine.h>
#include <flanterm/flanterm.h>
#include <flanterm/backends/fb.h>
#include <stddef.h>
#include <stdint.h>

void print_init(struct limine_framebuffer_request);

void print_ch(char);

void print(const char* );