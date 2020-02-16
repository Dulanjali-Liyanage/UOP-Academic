module testbench;

reg D, CLK, RST;
wire Q,Q_BAR;

dff flipflop(D, CLK, RST, Q,Q_BAR);

//testing
initial begin
      CLK = 1;
      D = 0;
      RST = 1;

     $dumpfile("D.vcd");
     $dumpvars(0, flipflop);

    #1 D = 1;
    #3 RST = 0;
    #8 D = 0;
    #6 D = 1;
    #2 D = 0;
    #6 D = 1;
    #5 D = 0;
    #3 RST = 1;
    #10 $finish;
end

always #5 CLK = ~CLK ;

endmodule

module dff(d, clk, reset,q,q_bar);

input  d, clk, reset;
output q,q_bar;

wire s,r,t;

	nand (s,d,clk);
	nand(t,~d,clk);
	nand(r,s,q_bar);
	nand(q_bar,t,r);
	and(q,r,~reset);
	

endmodule
