/*
 * Module: igen
 *
 * Description: Immediate value generator
 * -------- REPLACE THIS FILE WITH THE MEMORY MODULE DEVELOPED IN PD2 -----------
 */
/*
 * Module: igen
 *
 * Description: Immediate value generator
 *
 * Inputs:
 * 1) opcode opcode_i
 * 2) input instruction insn_i
 * Outputs:
 * 2) 32-bit immediate value imm_o
 */

module igen #(
              parameter int DWIDTH=32
              )(
                input logic [6:0] opcode_i,
                input logic [DWIDTH-1:0] insn_i,
                output logic [31:0] imm_o
                );
    /*
     * Process definitions to be filled by
     * student below...
     */
    always_comb begin
        imm_o = insn_i[31] == 1? 32'hffffffff : 32'h00000000;
        case(opcode_i)
            OP_IA, OP_IL, OP_IJ : begin
                imm_o[11:0] = insn_i[31:20];
                if(insn_i[14:12] == FIA_SLTU) begin
                       imm_o[31:12] = 0;
                end
            end
            OP_S : begin
                imm_o[11:5] = insn_i[31:25];
                imm_o[4:0] = insn_i[11:7];
            end
            OP_B : begin
                imm_o[0]=0;
                imm_o[4:1] = insn_i[11:8];
                imm_o[11] = insn_i[7];
                imm_o[12] = insn_i[31];
                imm_o[10:5] = insn_i[30:25];
            end
            OP_U, OP_UPC: begin
                imm_o[31:0] = {insn_i[31:12],12'd0};
            end
            OP_J : begin
                imm_o[0] = 0;
                
                imm_o[19:12] = insn_i[19:12];
                imm_o[10:1] = insn_i[30:21];
                imm_o[11] = insn_i[20];
                imm_o[20] = insn_i[31];
            end
            default: imm_o = 0;
        endcase
    end

endmodule : igen
