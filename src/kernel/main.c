#include "main.h"
#include "../headers/print.h"

void kernel_main(struct limine_framebuffer_request framebuffer_request){

    print_init(framebuffer_request);

    print("Avelyn OS");
    print("Version: 0.0.1");
    print(">> ");
}