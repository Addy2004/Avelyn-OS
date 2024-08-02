make

mkdir -p iso_root
mkdir -p iso_root/boot
cp -v bin/avelynos iso_root/boot/
cp -v src/media/background.jpeg iso_root/boot/
mkdir -p iso_root/boot/limine
cp -v limine.cfg limine/limine-bios.sys limine/limine-bios-cd.bin \
      limine/limine-uefi-cd.bin iso_root/boot/limine/

mkdir -p iso_root/EFI/BOOT
cp -v limine/BOOTX64.EFI iso_root/EFI/BOOT/
cp -v limine/BOOTIA32.EFI iso_root/EFI/BOOT/

xorriso -as mkisofs -b boot/limine/limine-bios-cd.bin \
        -no-emul-boot -boot-load-size 4 -boot-info-table \
        --efi-boot boot/limine/limine-uefi-cd.bin \
        -efi-boot-part --efi-boot-image --protective-msdos-label \
        iso_root -o avelynos.iso

qemu-system-x86_64 -cdrom avelynos.iso

rm avelynos.iso
rm -rf obj bin iso_root
echo Garbage cleansed!