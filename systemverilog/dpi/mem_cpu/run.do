onerror {resume}
# Create the library.
if [file exists work] {
    vdel -all
}
vlib work

# Compile the HDL source(s)
vlog -dpiheader test.h -sv test.sv test.c

# Simulate the design.
onerror {quit -sim}
vsim -novopt -c top
run -all
