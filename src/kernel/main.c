#include "main.h"
#include "../headers/print.h"
#include "string.h"

#define OS_NAME "Avelyn OS\n"
#define VERSION "Version: 0.0.1\n"

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

    print(OS_NAME);
    print(VERSION);
    print("Bootloader name: "); print(bootloader_name); print("\n");
    print("Bootloader version: "); print(bootloader_version); print("\n");
    // print("Number of memory map entries present: "); print(entry_count); print("\n");
    print(">> ");
}