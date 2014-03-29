set files [glob -nocomplain *.o *.wlf core* *.exp *.lib *.obj *.dll *.vstf *.so *.ucdb *.dump]
foreach file $files {
	file delete -force $file
}
file delete -force work
