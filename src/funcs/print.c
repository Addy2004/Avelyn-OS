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



int print_ch(int ich){
    char c = (char) ich;
    flanterm_write(ft_ctx, &c, sizeof(char));

    return ich;
}

static bool printf(const char* data, size_t length){
    const unsigned char* bytes = (const unsigned char*) data;
    for(size_t i = 0; i < length; i++){
        if(print_ch(bytes[i]) == -1){
            return false;
        }
    }
    return true;
}

int print(const char* restrict format, ...){
    va_list parameters;
    va_start(parameters, format);

    int written  = 0;

    while(*format != '\0'){
        size_t maxrem = INT_MAX - written;

        if(format[0] != '%' || format[1] == '%'){
            if(format[0] == '%'){
                format++;
            }
            size_t amount = 1;
            while(format[amount] && format[amount] != '%'){
                amount++;
            }
            if(maxrem < amount){
                // TODO: Set errno to EVOERFLOW
                return -1;
            }
            if(!printf(format, amount)){
                return -1;
            }
            format += amount;
            written += amount;
            continue;
        }
        const char* format_begun_at = format++;

        if(*format == 'c'){
            format++;
            char c = (char) va_arg(parameters, int);
            if(!maxrem){
                // TODO: Set errno to EOVERFLOW
                return -1;
            }
            if(!printf(&c, sizeof(c))){
                return -1;
            }
            written++;
        } else if (*format == 's'){
            format++;
            const char* str = va_arg(parameters, const char*);
            size_t len = strlen(str);
            if(maxrem < len){
                // TODO: Set errno to EOVERFLOW
                return -1;
            }
            if(!printf(str, len)){
                return -1;
            }
            written += len;
        } else if (*format == 'i'){
            format++;
            uint64_t num = va_arg(parameters, uint64_t);
            const char* str = (char*)(itos(num));
            size_t len = strlen(str);
            if(maxrem < len){
                // TODO: Set errno to EOVERFLOW
                return -1;
            }
            if(!printf(str, len)){
                return -1;
            }
            written += len;
        }
        else{
            format = format_begun_at;
            size_t len = strlen(format);
            if(maxrem < len){
                // TODO: Set errno to EOVERFLOW.
                return -1;
            }
            if(!printf(format, len)){
                return -1;
            }
            written += len;
            format += len;
        }
    }
    va_end(parameters);
    return written;
}