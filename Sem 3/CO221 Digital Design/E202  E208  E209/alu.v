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





module complement2of4(num,numcomp);

input [3:0]num;
output [3:0]numcomp;

wire [3:0]p;

not invert[3:0](p,num);

RippleCarryAdder4 name1(4'b0001,p,0,numcomp,cout);

endmodule





		
module subtract4(sub,a,b);

input [3:0]a;
input [3:0]b;
output [3:0]sub;

wire [3:0]p;

complement2of4 name2(b,p);

RippleCarryAdder4 name3(p,a,0,sub,cout);

endmodule





module bit4and(andout,m,n);

input [3:0] m,n;
output [3:0] andout;

	and(andout[0],m[0],n[0]);
	and(andout[1],m[1],n[1]);
	and(andout[2],m[2],n[2]);
	and(andout[3],m[3],n[3]);
	
endmodule





module bit4or(orout,g,h);

input [3:0] g,h;
output [3:0] orout;

	or(orout[0],g[0],h[0]);
	or(orout[1],g[1],h[1]);
	or(orout[2],g[2],h[2]);
	or(orout[3],g[3],h[3]);
	
endmodule






module multiplier(out,a,b);
input[3:0] a,b;
output[7:0] out;
wire[3:0] wa0,wa1,wa2,wa3,wa4,wa5,sum1,sum2,sum3;

and(out[0],a[0],b[0]);
and(wa0[0],a[0],b[1]);
and(wa0[1],a[0],b[2]);
and(wa0[2],a[0],b[3]);
not(wa0[3],1'b1);

and(wa1[0],a[1],b[0]);
and(wa1[1],a[1],b[1]);
and(wa1[2],a[1],b[2]);
and(wa1[3],a[1],b[3]);

RippleCarryAdder4 adder1(wa1,wa0,1'b0,sum1,c_out1);
and(out[1],sum1[0],1'b1);

and(wa2[0],a[2],b[0]);
and(wa2[1],a[2],b[1]);
and(wa2[2],a[2],b[2]);
and(wa2[3],a[2],b[3]);

and(wa3[0],sum1[1],1'b1);
and(wa3[1],sum1[2],1'b1);
and(wa3[2],sum1[3],1'b1);
and(wa3[3],c_out1,1'b1);

RippleCarryAdder4 adder2(wa2,wa3,1'b0,sum2,c_out2);
and(out[2],sum2[0],1'b1);

and(wa4[0],a[3],b[0]);
and(wa4[1],a[3],b[1]);
and(wa4[2],a[3],b[2]);
and(wa4[3],a[3],b[3]);

and(wa5[0],sum2[1],1'b1);
and(wa5[1],sum2[2],1'b1);
and(wa5[2],sum2[3],1'b1);
and(wa5[3],c_out2,1'b1);

RippleCarryAdder4 adder3(wa4,wa5,1'b0,sum3,c_out3);

and(out[3],sum3[0],1'b1);
and(out[4],sum3[1],1'b1);
and(out[5],sum3[2],1'b1);
and(out[6],sum3[3],1'b1);
and(out[7],c_out3,1'b1);

endmodule








module mux8to1(finaloutbit,j,c);

input[7:0] j;
input[2:0] c;
output finaloutbit;

wire[2:0] ic;
wire[7:0] r;

not inverter[2:0] (ic,c);

and(r[0], j[0], ic[0], ic[1], ic[2]);
and(r[1], j[1], c[0], ic[1], ic[2]);
and(r[2], j[2], ic[0], c[1], ic[2]);
and(r[3], j[3], c[0], c[1], ic[2]);
and(r[4], j[4], ic[0], ic[1], c[2]);
and(r[5], j[5], c[0], ic[1], c[2]);
and(r[6], j[6], ic[0], c[1], c[2]);
and(r[7], j[7], c[0], c[1], c[2]);

or(finaloutbit,r[0],r[1],r[2],r[3],r[4],r[5],r[6],r[7]);

endmodule








module finallyOurAlu(out,a,b,c);

input[3:0] a;
input[3:0] b;
input[2:0] c;
output[3:0] out;

wire[3:0] ca,cb,outsum,outsub,bandout,borout;
wire[7:0] mulout;
wire[7:0] firstbit,secondbit,thirdbit,fourthbit;

complement2of4 compa(a,ca);

complement2of4 compb(b,cb);

RippleCarryAdder4 add(a,b,1'b0,outsum,cout);

subtract4 subtract(outsub,a,b);

bit4and band(bandout,a,b);

bit4or bor(borout,a,b);

multiplier mul(mulout,a,b);


and (firstbit[0],ca[0],1'b1);
and (firstbit[1],cb[0],1'b1);
and (firstbit[2],outsum[0],1'b1);
and (firstbit[3],outsub[0],1'b1);
and (firstbit[4],bandout[0],1'b1);
and (firstbit[5],borout[0],1'b1);
and (firstbit[6],mulout[0],1'b1);
and (firstbit[7],mulout[4],1'b1);


and (secondbit[0],ca[1],1'b1);
and (secondbit[1],cb[1],1'b1);
and (secondbit[2],outsum[1],1'b1);
and (secondbit[3],outsub[1],1'b1);
and (secondbit[4],bandout[1],1'b1);
and (secondbit[5],borout[1],1'b1);
and (secondbit[6],mulout[1],1'b1);
and (secondbit[7],mulout[5],1'b1);



and (thirdbit[0],ca[2],1'b1);
and (thirdbit[1],cb[2],1'b1);
and (thirdbit[2],outsum[2],1'b1);
and (thirdbit[3],outsub[2],1'b1);
and (thirdbit[4],bandout[2],1'b1);
and (thirdbit[5],borout[2],1'b1);
and (thirdbit[6],mulout[2],1'b1);
and (thirdbit[7],mulout[6],1'b1);



and (fourthbit[0],ca[3],1'b1);
and (fourthbit[1],cb[3],1'b1);
and (fourthbit[2],outsum[3],1'b1);
and (fourthbit[3],outsub[3],1'b1);
and (fourthbit[4],bandout[3],1'b1);
and (fourthbit[5],borout[3],1'b1);
and (fourthbit[6],mulout[3],1'b1);
and (fourthbit[7],mulout[7],1'b1);


mux8to1 mux0(out[0],firstbit,c);
mux8to1 mux1(out[1],secondbit,c);
mux8to1 mux2(out[2],thirdbit,c);
mux8to1 mux3(out[3],fourthbit,c);

endmodule





module testbench;


        reg[3:0] A,B;
        reg [2:0] C;
        wire[3:0] OUT;
        

        finallyOurAlu alu(OUT,A,B,C);


        initial 
        
        begin

        $monitor("a=%b   b=%b   c=%b   out=%b",A,B,C,OUT);
        A=4'b0000;B=4'b0000;C=3'b000;

        #5 A=4'b0001;B=4'b0000;C=3'b001;
        #5 A=4'b0000;B=4'b0001;C=3'b010;
        #5 A=4'b0001;B=4'b0000;C=3'b011;
        #5 A=4'b0001;B=4'b0001;C=3'b100;
        #5 A=4'b0010;B=4'b0001;C=3'b101;
        #5 A=4'b0001;B=4'b0000;C=3'b110;
        #5 A=4'b0001;B=4'b0000;C=3'b111;
        
        
        #5 A=4'b0001;B=4'b0000;C=3'b000;
        #5 A=4'b0001;B=4'b0001;C=3'b001;
        #5 A=4'b1010;B=4'b0101;C=3'b010;
        #5 A=4'b0101;B=4'b0100;C=3'b011;
        #5 A=4'b1010;B=4'b0101;C=3'b100;
        #5 A=4'b0000;B=4'b1101;C=3'b101;
        #5 A=4'b0010;B=4'b0101;C=3'b110;
        #5 A=4'b0110;B=4'b1111;C=3'b111;

        end

endmodule






