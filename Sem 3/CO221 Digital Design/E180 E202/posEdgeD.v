module testbench;

reg D,CLK;
wire Q,Q_BAR;

posEdgeD flpy(D,CLK,Q,Q_BAR);

initial begin
    

	$dumpfile("D.vcd");
	$dumpvars(0,flpy);
    
      	CLK = 1;
	D = 0;
	//Q = 0;

	#5 D = 1;
	
	#5 D = 1;
	#5 D = 0;
	#5 D = 0;
	#5 D = 1;
	#5 D = 1;
	#10 $finish;
    
end	
  
always  #5  CLK = ~CLK;

endmodule





module posEdgeD(d,clk,q,q_bar);

input d;
input clk;

output q;
output q_bar;

wire p1,p2,p3,p4;

	nand (p4,d,p2);
	nand (p2,p4,clk,p1);
	nand (p1,clk,p3);
	nand (p3,p4,p1);
	nand (q,p1,q_bar);
	nand (q_bar,p2,q);
	
endmodule