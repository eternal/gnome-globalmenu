#! /bin/bash

source ../patch.sh

patch '/g_return_if_fail (previous_window != NULL)/d' applet.c
patch '/gnome_program_init/s/APPLET_STANDARD_PROPERTIES/GNOME_PROGRAM_STANDARD_PROPERTIES/' applet.c