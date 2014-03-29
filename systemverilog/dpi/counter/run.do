onerror {resume}
# Create the library.
if [file exists work] {
    vdel -all
}
vlib work

# Compile the HDL source(s)
vlog -sv test.sv test.cpp

# Simulate the design.
onerror {quit -sim}
vsim -novopt -c top
run -all
