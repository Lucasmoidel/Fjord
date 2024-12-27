#!/bin/bash

# IF YOUR DISTRO's PAKAGE MANAGER IS NOT ON HERE THE FEEL GREE TO ADD IT

set -e

UNKNOWN="echo your distro is not on this list, feel free to add it. The needed pakages are sdl2, jsoncpp, yamlcpp, box2d, and cmake"

PACMAN="sudo pacman -S sdl2 sdl2_ttf jsoncpp yaml-cpp box2d cmake"
APT="sudo apt install libsdl2-dev jsoncpp yaml-cpp box2d cmake"
DNF=$UNKNOWN

if [ $(lsb_release -is) == "Arch" ]
then
    echo $(lsb_release -is)
    $PACMAN
elif [ $(lsb_release -is) == "ubuntu" ] || [ $(lsb_release -is) == "debian" ] || [ $(lsb_release -is) == "*pop*" ]
then
    echo $(lsb_release -is)
    $APT
elif [ $(lsb_release -is) == "fedora" ]
then
    echo $(lsb_release -is)
    $DNF
else
    echo $(lsb_release -is)
    $UNKNOWN
fi