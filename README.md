# Advection-FTCS
Numerical solution of Advection equation using FTCS method. Here three programmes are given. FTCS scheme implements in Adv_FTCS.c whereas Lax Friedrichs and Lax Wendroff scheme are introduced in Adv_FTCS-LF.c and Adv_FTCS-LW.c respectively.

To run the code use the following commands.

gcc -Wall Adv_FTCS-LF.c -o Adv_FTCS-LF

./Adv_FTCS-LF > ndata.dat

gnuplot AdvPlot.plt
