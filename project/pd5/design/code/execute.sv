/*
 * Module: alu
 *
 * Description: ALU implementation for execute stage.
 *
 * Inputs:
 * 1) 32-bit PC pc_i
 * 2) 32-bit rs1 data rs1_i
 * 3) 32-bit rs2 data rs2_i
 * 4) 3-bit funct3 funct3_i
 * 5) 7-bit funct7 funct7_i
 *
 * Outputs:
 * 1) 32-bit result of ALU res_o
 * 2) 1-bit branch taken signal brtaken_o
 */

module alu #(
    parameter int DWIDTH=32,
    parameter int AWIDTH=32
)(
    input logic [AWIDTH-1:0]  pc_i,
    input logic [DWIDTH-1:0]  rs1_i,
    input logic [DWIDTH-1:0]  rs2_i,
    input logic [3:0]         aluSel_i,
    input logic [6:0]         opcode_i,

    output logic [DWIDTH-1:0] res_o
);

    //the muxes can be compined for better chip size, but this way it is cleaner and more readable
    always_comb begin

        //mux for res_o
        case(aluSel_i)
            ALU_ADD : begin
                res_o = rs1_i + rs2_i;
            end
            ALU_SUB : begin
                res_o = rs1_i - rs2_i;
            end
            ALU_XOR : begin
                res_o = rs1_i ^ rs2_i;
            end
            ALU_OR  : begin
                res_o = rs1_i | rs2_i;
            end
            ALU_AND : begin
                res_o = rs1_i & rs2_i;
            end
            ALU_SLL : begin
                res_o = rs1_i << rs2_i;
            end
            ALU_SRL : begin
                res_o = rs1_i >> rs2_i;
            end
            ALU_SRA : begin
                res_o = (32'h80000000 & rs1_i) | (rs1_i >> rs2_i);
            end
            ALU_SLT : begin
                res_o = rs1_i < rs2_i ? 32'hffffffff : 0;
            end
            ALU_SLTU: begin
                res_o = rs1_i < rs2_i ? 32'h00000001 : 0;
            end
            default: res_o = 0;
        endcase

        if(opcode_i == OP_U) res_o = rs2_i;

    end

endmodule : alu
