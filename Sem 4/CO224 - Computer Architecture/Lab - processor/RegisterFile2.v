module RegisterFile2(input [7:0] IN,
			output reg [7:0] OUT1,
			output reg [7:0] OUT2,
			input [2:0] INaddr,input [2:0] OUT1addr,input [2:0] OUT2addr,input wire CLK,input wire RESET);
			
reg[7:0] r0,r1,r2,r3,r4,r5,r6,r7;

 initial begin
  r0 = 8'b00000000;
      r1 = 8'b00000000;
      r2 = 8'b00000000;
      r3 = 8'b00000000;
      r4 = 8'b00000000;
      r5 = 8'b00000000;
      r6 = 8'b00000000;
    r7 = 8'b00000000;
end

always @(posedge RESET) begin
    
    	r0=8'b00000000;
        r1=8'b00000000;
        r2=8'b00000000;
        r3=8'b00000000;
        r4=8'b00000000;
        r5=8'b00000000;
        r6=8'b00000000;
    	r7=8'b00000000;
end
   
    always @(negedge CLK) begin	
    case(INaddr)
    3'b000:r0=IN;
        3'b001:r1=IN;
        3'b010:r2=IN;
        3'b011:r3=IN;
        3'b100:r4=IN;
        3'b101:r5=IN;
        3'b110:r6=IN;
    3'b111:r7=IN;
    endcase
    
    end
    
    always @(posedge CLK) begin
    case(OUT1addr)
        3'b000:OUT1=r0;
        3'b001:OUT1=r1;
        3'b010:OUT1=r2;
        3'b011:OUT1=r3;
        3'b100:OUT1=r4;
        3'b101:OUT1=r5;
        3'b110:OUT1=r6;
        3'b111:OUT1=r7;
   endcase
   
   
   case(OUT2addr)
       3'b000:OUT2=r0;
               3'b001:OUT2=r1;
               3'b010:OUT2=r2;
               3'b011:OUT2=r3;
               3'b100:OUT2=r4;
               3'b101:OUT2=r5;
               3'b110:OUT2=r6;
        3'b111:OUT2=r7;
   endcase
    end
   
endmodule


module testbench;

reg CLK,RESET;

reg[7:0] IN;
reg[2:0] INaddr,OUT1addr,OUT2addr;

wire[7:0] OUT1;
wire[7:0] OUT2;

RegisterFile2 test_unit(IN,
			 OUT1,
			 OUT2,
			INaddr,OUT1addr,OUT2addr,CLK,RESET);
    

initial begin
    RESET = 1'b0;
    INaddr = 3'b000;OUT1addr= 3'b000;OUT2addr= 3'b010;IN= 8'b11001100;
    #5
    $monitor(" IN = %b, OUT1= %b, OUT2= %b,INaddr= %b,OUT1addr= %b,OUT2addr= %b,CLK= %b,RESET= %b, ",IN, OUT1, OUT2, INaddr, OUT1addr, OUT2addr, CLK, RESET);
    CLK =1'b1;
        #5;
        CLK =1'b0;
        #5;
        CLK =1'b1;
        #5;
        INaddr = 3'b011;OUT1addr= 3'b000;OUT2addr= 3'b011;IN= 8'b11001110;
        #5
        CLK =1'b0;
        #5
        CLK =1'b1;

    
    
 end

        
endmodule
        
