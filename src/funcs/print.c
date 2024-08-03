#include "../headers/print.h"

struct flanterm_context *ft_ctx;

void print_init(struct limine_framebuffer_request framebuffer_request){
    // // Fetch the first framebuffer.
    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    ft_ctx = flanterm_fb_init(
        NULL, NULL,
        framebuffer->address, framebuffer->width, framebuffer->height, framebuffer->pitch,
        framebuffer->red_mask_size, framebuffer->red_mask_shift,
        framebuffer->green_mask_size, framebuffer->green_mask_shift,
        framebuffer->blue_mask_size, framebuffer->blue_mask_shift,
        NULL, NULL, NULL, NULL, 
        NULL, NULL, NULL, NULL, 
        0, 0, 1, 1, 1, 5
    );
}

void print_ch(char ch){
    flanterm_write(ft_ctx, &ch, sizeof(char));
}

void print(const char* str){
    for(size_t i = 0; 1; i++){
        if(str[i] == '\0'){
            return;
        } else{
            print_ch(str[i]);
        }
    }
}