module alu(
           input [7:0] A,B,  // ALU 8-bit Inputs                 
           input [2:0] ALU_Sel,// ALU Selection
           output [7:0] ALU_Out // ALU 8-bit Output
    );
    reg [7:0] ALU_Result;
    wire [8:0] tmp;
    assign ALU_Out = ALU_Result; // ALU out
    always @(*)
    begin
        case(ALU_Sel)
        3'b000: // Forward
           ALU_Result = A; 
        3'b001: // Add
           ALU_Result = A + B ;
        3'b010: // And
           ALU_Result = A & B;
        3'b011: // Or
           ALU_Result = A | B;
         default:
         	ALU_Result = 8'b00000000;
        endcase
    end

endmodule



`timescale 1ns / 1ps  

module tb_alu;
//Inputs
 reg[7:0] A,B;
 reg[2:0] ALU_Sel;

//Outputs
 wire[7:0] ALU_Out;
 // Verilog code for ALU
 alu test_unit(
            A,B,  // ALU 8-bit Inputs                 
            ALU_Sel,// ALU Selection
            ALU_Out // ALU 8-bit Output
      
     );
     
    initial begin
    $monitor("a=%b   b=%b  select=%b  out=%b",A,B,ALU_Sel,ALU_Out);

     	A = 8'h0A;B = 8'h02;ALU_Sel=3'b000;
      
        #5  A = 8'h0A;B = 8'h02;ALU_Sel=3'b000;
        #5  A = 8'h0A;B = 8'h02;ALU_Sel=3'b001;
        #5  A = 8'h0A;B = 8'h02;ALU_Sel=3'b010;
        #5  A = 8'h0A;B = 8'h02;ALU_Sel=3'b011;
        #5  A = 8'h0A;B = 8'h02;ALU_Sel=3'b111;
             
      
    end
endmodule