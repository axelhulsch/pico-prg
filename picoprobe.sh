#!/bin/sh
usbipd.exe wsl detach -a
usbipd.exe wsl attach -i 2e8a:0004 
exit