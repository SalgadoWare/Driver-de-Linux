#!/bin/bash     

sudo rmmod chardev_leds
sudo rm /dev/chardev_leds
make clean
make all
sudo insmod chardev_leds.ko
dmesg | tail
sudo mknod -m 666 /dev/chardev_leds c 250 0
