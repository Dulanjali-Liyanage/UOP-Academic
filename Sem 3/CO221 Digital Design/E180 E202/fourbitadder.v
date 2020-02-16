
module FullAdder(x,y,cin,k,cout);

 input x;
 input y;
 input cin;
 
 output k; 
 output cout;
 
 
wire  p,q,r;
	and (p,x,y);
	xor (r,x,y);
	or (cout,p,q);
	xor (k,cin,r);
	and (q,cin,r);


endmodule


module RippleCarryAdder4(x,y,cin,k,cout);

	input[3:0]x,y;
	output[3:0]k;
	input cin;
	output cout;

	wire cout1,cout2,cout3;

	FullAdder fa0(x[0],y[0],cin,k[0],cout1);
	FullAdder fa1(x[1],y[1],cout1,k[1],cout2);
	FullAdder fa2(x[2],y[2],cout2,k[2],cout3);
	FullAdder fa3(x[3],y[3],cout3,k[3],cout);
endmodule

module stimulus;
	reg [3:0] x,y;
	wire [3:0] k;
	wire cout;

	RippleCarryAdder4 rca(x,y,1'b0,k,cout);

	initial

	begin

		x <= 4'b1111;
		y <= 4'b0110;
		#1
		$display("%d + %d = %d, %d",x,y,k,cout);
		
		x <= 4'b0100;
		y <= 4'b1001;
		#1
		$display("%d + %d = %d, %d",x,y,k,cout);
		
		
		x <= 4'b0000;
		y <= 4'b0010;
		#1
		$display("%d + %d = %d, %d",x,y,k,cout);
		
		x <= 4'b1001;
		y <= 4'b1011;
		#1
		$display("%d + %d = %d, %d",x,y,k,cout);
		
		x <= 4'b1010;
		y <= 4'b0100;
		#1
		$display("%d + %d = %d, %d",x,y,k,cout);
		
		x <= 4'b0101;
		y <= 4'b1111;
		#1
		$display("%d + %d = %d, %d",x,y,k,cout);
		

	end
endmodule

