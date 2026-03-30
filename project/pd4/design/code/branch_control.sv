/*
    * Module: branch_control
    *
    * Description: Branch control logic. Only sets the branch control bits based on the
    * branch instruction
    *
    * Inputs:
    * 1) 7-bit instruction opcode opcode_i
    * 2) 3-bit funct3 funct3_i
    * 3) 32-bit rs1 data rs1_i
    * 4) 32-bit rs2 data rs2_i
    *
    * Outputs:
    * 1) 1-bit operands are equal signal breq_o
    * 2) 1-bit rs1 < rs2 signal brlt_o
    */
`include "constants.svh"

module branch_control #(
    parameter int DWIDTH=32
)(
    // inputs
  input logic [6:0]        opcode_i,
  input logic [2:0]        funct3_i,
  input logic [DWIDTH-1:0] rs1_i,
  input logic [DWIDTH-1:0] rs2_i,
    // outputs
  output logic             branch_o
);

    always_comb begin

        if(opcode_i == OP_B) begin
            //mux for branches

            case(funct3_i)

                FB_BEQ : begin
                    branch_o = (rs1_i == rs2_i) ? 1 : 0;
                end

                FB_BNE : begin
                    branch_o = (rs1_i !=  rs2_i) ? 1 : 0;
                end

                FB_BLT : begin
                    branch_o = (rs1_i < rs2_i) ? 1 : 0;
                end

                FB_BGE : begin
                    branch_o = (rs1_i >= rs2_i) ? 1 : 0;
                end

                FB_BLTU: begin
                    branch_o = ($unsigned(rs1_i) <  $unsigned(rs2_i)) ? 1 : 0;
                end

                FB_BGEU: begin
                    branch_o = ($unsigned(rs1_i)  >= $unsigned(rs2_i)) ? 1 : 0;
                end

                default: branch_o = 0;

            endcase // case (funct3_i)
        end

        else begin
            branch_o = 0;
        end
    end

endmodule : branch_control

