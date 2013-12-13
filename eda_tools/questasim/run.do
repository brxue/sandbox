# To run this example, bring up the simulator and type the following at the prompt:
#     do run.do
# or, to run from a shell, type the following at the shell prompt:
#     vsim -c -do run.do
# (omit the "-c" to see the GUI while running from the shell)
# Remove the "quit -f" command from this file to view the results in the GUI.

onbreak {resume}

# Create the library.
if [file exists work] { # remove the directory named "work" if it already exists
    vdel -all
}
vlib work 
# create work library

# Compile the sources.
vlog -sv +define+HELLO hello.v

# Simulate the design.
vsim -novopt hello
run -all

# View the results.
if {![batch_mode]} {
	log -r /*
	add wave -divider "Clock Signal"
	add wave /hello/clk
	add wave -divider "Interface Signals"
	add wave -hex /hello/d
	add wave -hex /hello/q
	wave zoomfull
}

# force quit of simulation
#quit -f
