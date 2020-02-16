
module FullAdder(x,y,cin,Z,cout);

 input x;
 input y;
 input cin;
 
 output Z; 
 output cout;
 
 
wire  a,b,c;
	and (a,x,y);
	xor (c,x,y);
	and (b,cin,c);
	or (cout,a,b);
	xor (Z,cin,c);


endmodule





module RippleCarryAdder4(x,y,cin,Z,cout);

	input[3:0]x,y;
	output[3:0]Z;
	input cin;
	output cout;

	wire cout1,cout2,cout3;

	FullAdder fa0(x[0],y[0],cin,Z[0],cout1);
	FullAdder fa1(x[1],y[1],cout1,Z[1],cout2);
	FullAdder fa2(x[2],y[2],cout2,Z[2],cout3);
	FullAdder fa3(x[3],y[3],cout3,Z[3],cout);
endmodule

module stimulus;
	reg [3:0] x,y;
	wire [3:0] Z;
	wire cout;

	RippleCarryAdder4 rca(x,y,1'b0,Z,cout);

	initial

	begin

		x <= 4'b1101;
		y <= 4'b0110;
		#1
		$display("%d + %d = %d, %d",x,y,Z,cout);
		
		x <= 4'b0000;
		y <= 4'b0001;
		#1
		$display("%d + %d = %d, %d",x,y,Z,cout);
		
		
		x <= 4'b0000;
		y <= 4'b0010;
		#1
		$display("%d + %d = %d, %d",x,y,Z,cout);
		
		x <= 4'b0000;
		y <= 4'b0011;
		#1
		$display("%d + %d = %d, %d",x,y,Z,cout);
		
		x <= 4'b0000;
		y <= 4'b0100;
		#1
		$display("%d + %d = %d, %d",x,y,Z,cout);
		
		x <= 4'b0000;
		y <= 4'b1111;
		#1
		$display("%d + %d = %d, %d",x,y,Z,cout);
		
		x <= 4'b1110;
		y <= 4'b1010;
		#1
		$display("%d + %d = %d, %d",x,y,Z,cout);
		
		x <= 4'b0101;
		y <= 4'b1101;
		#1
		$display("%d + %d = %d, %d",x,y,Z,cout);
	end
endmodule

