#include "main.h"
#include "../headers/print.h"
#include "string.h"

#define OS_NAME "Avelyn OS"
#define VERSION "0.0.1"

void kernel_main(struct limine_framebuffer_request framebuffer_request){

    __attribute__((used, section(".requests")))
    static volatile struct limine_bootloader_info_request bootloaderinfo_request = {
        .id = LIMINE_BOOTLOADER_INFO_REQUEST,
        .revision = 0,
    }; 

    __attribute__((used, section(".requests")))
    static volatile struct limine_memmap_request memmap_request = {
        .id = LIMINE_MEMMAP_REQUEST,
        .revision = 0,
    };

    char* bootloader_name = bootloaderinfo_request.response->name;
    char* bootloader_version = bootloaderinfo_request.response->version;

    uint64_t entry_count = memmap_request.response->entry_count;


    print_init(framebuffer_request);

    print("%s\n",OS_NAME);
    print("Version %s\n", VERSION);
    print("Bootloader name: %s\n", bootloader_name);
    print("Bootloader version: %s\n", bootloader_version);
    print("Number of memory map entries present: %i\n", entry_count);
    print(">> ");
}