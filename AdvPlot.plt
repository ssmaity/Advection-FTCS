do for [i=0:50] {
	plot [][0:1.5] 'ndata.dat' index i u 1:2, 'ndata.dat' index i u 1:3
	pause(0.1)
}
