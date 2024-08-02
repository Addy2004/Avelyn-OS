#include "main.h"

void kernel_main(struct limine_framebuffer_request framebuffer_request){

    // // Fetch the first framebuffer.
    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    struct flanterm_context *ft_ctx = flanterm_fb_init(
        NULL, NULL,
        framebuffer->address, framebuffer->width, framebuffer->height, framebuffer->pitch,
        framebuffer->red_mask_size, framebuffer->red_mask_shift,
        framebuffer->green_mask_size, framebuffer->green_mask_shift,
        framebuffer->blue_mask_size, framebuffer->blue_mask_shift,
        NULL, NULL, NULL, NULL, 
        NULL, NULL, NULL, NULL, 
        0, 0, 1, 1, 1, 5
    );


    
    const char output[] = "Avelyn OS\nVersion: 0.0.1\n>> ";
    flanterm_write(ft_ctx, output, sizeof(output));
}