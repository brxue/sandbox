module hello();
    reg clk = 0;
    always #5 clk = ~clk;

    initial begin
        repeat (10)@(posedge clk);
        $display("Hello Wolrd.");
        $finish;
    end

    // Enable VCD dumping
    initial begin
        $dumpfile("hello.vcd");
        $dumpvars(0, hello);
    end
endmodule
