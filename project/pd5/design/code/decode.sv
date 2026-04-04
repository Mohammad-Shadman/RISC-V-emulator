/*
 * Module: decode
 *
 * Description: Decode stage
 *
 * -------- REPLACE THIS FILE WITH THE MEMORY MODULE DEVELOPED IN PD2 -----------
 */
/*
 * Module: decode
 *
 * Description: Decode stage
 *
 * Inputs:
 * 1) clk
 * 2) rst signal
 * 3) insn_iruction ins_i
 * 4) program counter pc_i
 * Outputs:
 * 1) AWIDTH wide program counter pc_o
 * 2) DWIDTH wide insn_iruction output insn_o
 * 3) 5-bit wide destination register ID rd_o
 * 4) 5-bit wide source 1 register ID rs1_o
 * 5) 5-bit wide source 2 register ID rs2_o
 * 6) 7-bit wide funct7 funct7_o
 * 7) 3-bit wide funct3 funct3_o
 * 8) 32-bit wide immediate imm_o
 * 9) 5-bit wide shift amount shamt_o
 * 10) 7-bit width opcode_o
    */

`include "constants.svh"


//it will include handeling of the BC in X and an IG
module decode #(
    parameter int DWIDTH=32,
    parameter int AWIDTH=32
)(
    // inputs
    input logic                clk,
    input logic                rst,
    input logic [DWIDTH - 1:0] insn_i,
    input logic [DWIDTH - 1:0] pc_i,
    input logic [DWIDTH - 1:0] oldRd_e,
    input logic [DWIDTH - 1:0] oldRd_m,
    input logic [DWIDTH - 1:0] oldRs1,
    input logic [DWIDTH - 1:0] oldRs2,

    // outputs
    output logic [AWIDTH-1:0]  pc_o,
    output logic [DWIDTH-1:0]  insn_o,
    output logic [6:0]         opcode_o,
    output logic [4:0]         rd_o,
    output logic [4:0]         rs1_o,
    output logic [4:0]         rs2_o,
    output logic [6:0]         funct7_o,
    output logic [2:0]         funct3_o,
    output logic [4:0]         shamt_o,
    output logic [DWIDTH-1:0]  imm_o
);

    logic [DWIDTH-1:0] immReg;

    igen #(.DWIDTH(DWIDTH))
         imm (.opcode_i(insn_i[6:0]), .insn_i(insn_i), .imm_o(immReg));

//stall logic
    always_comb begin
        if (rs1_o == oldRd_e || rs2_o == oldRd_e || rs1_o == oldRd_m || rs2_o == oldRd_m)  begin
            opcode_o = 0;
            pc_o     = pc_i-4;
        end
        else begin
            opcode_o = insn_i[6:0];
            pc_o     = pc_i;
        end
    end

    //if rst, do nop,
    always_comb begin
        if (rst) begin
            funct3_o = 0;
            funct7_o = 0;
            opcode_o = 0;
            rd_o     = 0;
            rs1_o    = 0;
            rs2_o    = 0;
            shamt_o  = 0;
            imm_o    = 0;
        end

        else begin
            insn_o   = insn_i;
            imm_o    = immReg;

            funct7_o = insn_i[31:25];

            case(insn_i[6:0])
                // OP_U, OP_UPC, OP_J : begin
                //     funct3_o = 0;
                //     rs1_o    = 0;
                // end
                default : begin
                    funct3_o = insn_i[14:12];
                    rs1_o    = insn_i[19:15];
                end
            endcase

            case(insn_i[6:0])
                // OP_S, OP_B : rd_o = 0;
                default :    rd_o = insn_i[11:7];
            endcase

            case(insn_i[6:0])
                // OP_R, OP_B, OP_S : rs2_o = insn_i[24:20];
                default :          rs2_o = insn_i[24:20];
            endcase

            shamt_o  = insn_i[24:20];
        end
    end // always_ff @ (posedge clk)
endmodule : decode
