/*
 * Module: top
 *
 * Description: Testbench that drives the probes and displays the signal changes
 */
`include "../../design/probes.svh"

module top;
    logic clock;
    logic reset;

    clockgen clkg(
                  .clk(clock),
                  .rst(reset)
                  );

    design_wrapper dut(
                       .clk(clock),
                       .reset(reset)
                       );

    integer counter = 0;
    integer errors = 0;


    always_ff @(posedge clock) begin
        counter <= counter + 1;
        if(counter == 32'hffffffff) begin
            $display("[PD0] No error encountered");
            $finish;
        end
    end

    initial begin
        $monitor(" clk = %0b", clock);
    end

    always_ff @(negedge clock) begin
        $display("###########");
    end
    
    logic       reset_done;
    logic       reset_neg;
    logic       reset_reg;
    integer     reset_counter;
    always_ff @(posedge clock) begin
        if(reset) reset_counter <= 0;
        else      reset_counter <= reset_counter + 1;
        // detect negedge
        reset_reg <= reset;
        if(reset_reg && !reset) reset_neg <= 1;
        // delay for some cycles
        if(reset_neg && reset_counter >= 3) begin
            reset_done <= 1;
        end
    end

    // assign_xor
    logic assign_xor_op1;
    logic assign_xor_op2;
    logic assign_xor_res;

    always_comb begin: assign_xor_input
        dut.core.`PROBE_ASSIGN_XOR_OP1 = counter[0];
        dut.core.`PROBE_ASSIGN_XOR_OP2 = counter[1];
    end

    always_ff @(posedge clock) begin: assign_xor_test
        if (reset_done) begin
            $display("[ASSIGN_XOR] op1=%b, op2=%b, res=%b", assign_xor_op1, assign_xor_op2, assign_xor_res);
        end
        assign_xor_op1 <= dut.core.`PROBE_ASSIGN_XOR_OP1;
        assign_xor_op2 <= dut.core.`PROBE_ASSIGN_XOR_OP2;
        assign_xor_res <= dut.core.`PROBE_ASSIGN_XOR_RES;
        if(assign_xor_res != assign_xor_op1 ^ assign_xor_op2) begin
            $display("[ALU] counter=%d inp1=%b, inp2=%b, alusel=%b, res=%b", counter, alu_op1, alu_op2, alu_sel, alu_res);
            //$fatal(1,"[ASSIGN_XOR] assign_xor_res not correct");
            
        end
        
    end

`ifdef PROBE_ALU_OP1 `ifdef PROBE_ALU_OP2 `ifdef PROBE_ALU_SEL `ifdef PROBE_ALU_RES
    `define PROBE_ALU_OK
   `endif  `endif `endif `endif
`ifdef PROBE_ALU_OK
    // alu
    logic [1:0] alu_sel;
    logic [31:0] alu_op1;
    logic [31:0] alu_op2;
    logic [31:0] alu_res;
    always_comb begin: alu_input
        dut.core.`PROBE_ALU_SEL  = counter[1:0];
        dut.core.`PROBE_ALU_OP1  = counter[31:0];
        dut.core.`PROBE_ALU_OP2  = {counter[2], counter[3], counter[0], counter[1], counter[31:4]};
    end
    always_ff @(posedge clock) begin: alu_test
        if (reset_done) begin
            //$display("[ALU] counter=%d inp1=%d, inp2=%d, alusel=%d, res=%d", counter, alu_op1, alu_op2, alu_sel, alu_res);
        end
        alu_sel  <= dut.core.`PROBE_ALU_SEL;
        alu_op1 <= dut.core.`PROBE_ALU_OP1;
        alu_op2 <= dut.core.`PROBE_ALU_OP2;
        alu_res  <= dut.core.`PROBE_ALU_RES;
        if((alu_res != alu_op1 + alu_op2) && alu_sel == 0) begin
            $display("[ALU] counter=%d inp1=%d, inp2=%d, alusel=%d, res=%d, op=%d", counter, alu_op1, alu_op2, alu_sel, alu_res, (alu_op1 + alu_op2));
            //$fatal(1,"[ALU] alu_res - not correct");
        end
        if((alu_res != alu_op1 - alu_op2) && alu_sel == 1) begin
            $display("[ALU] counter=%d inp1=%d, inp2=%d, alusel=%d, res=%d, op=%d", counter, alu_op1, alu_op2, alu_sel, alu_res, (alu_op1 - alu_op2));          
            //$fatal(1,"[ALU] alu_res + not correct");
        end
        if((alu_res != (alu_op1 & alu_op2)) && alu_sel == 2) begin
            $display("[ALU] counter=%d inp1=%d, inp2=%d, alusel=%d, res=%d, op=%d", counter, alu_op1, alu_op2, alu_sel, alu_res, (alu_op1 & alu_op2));
            //$fatal(1,"[ALU] alu_res & not correct");
        end
        if((alu_res != (alu_op1 | alu_op2)) && alu_sel == 3) begin
            $display("[ALU] counter=%d inp1=%d, inp2=%d, alusel=%d, res=%d, op=%d", counter, alu_op1, alu_op2, alu_sel, alu_res, (alu_op1 | alu_op2));
            //$fatal(1,"[ALU] alu_res | not correct");
            
        end
    end
`else
    always_ff @(posedge clock) begin: alu_test
        $fatnal(1, "[ALU] Probe signals not defined");
    end
`endif


`ifdef PROBE_REG_IN `ifdef PROBE_REG_OUT
  `define PROBE_REG_OK
 `endif `endif
`ifdef PROBE_REG_OK
    logic [31:0] reg_rst_inp;
    logic [31:0] reg_rst_out;
    logic [31:0] reg_rst_test_inp;
    logic [31:0] reg_rst_test_out;

    always_comb begin: reg_rst_input
        dut.core.`PROBE_REG_IN = counter[31:0];
    end
    int prevRegIn = 0;
    
    always_ff @(posedge clock) begin: reg_rst_test
        if (reset_done) begin
            //$display("[REG] counter=%d inp=%b, out=%b", counter, reg_rst_inp, reg_rst_out);
        end
        
        reg_rst_inp <= dut.core.`PROBE_REG_IN;
        reg_rst_out <= dut.core.`PROBE_REG_OUT;
        reg_rst_test_inp <= dut.core.`PROBE_REG_IN; 
        reg_rst_test_out <= reg_rst_test_inp;   
        if(reset)begin
            reg_rst_test_out <= 0;
        end
        
    end 
    always_ff @(negedge clock) begin: reg_rst_test_fail
        if(reg_rst_test_out != reg_rst_out )begin
            $display("[REG] counter=%d inp=%b, out=%b, trueOut=%b, reset=%b", counter, reg_rst_inp, reg_rst_out, reg_rst_test_out, reset);
            ////$fatal(1, "[REG] failed register failed");
        end
    end

    
`else
    always_ff @(posedge clock) begin: reg_rst_test
        //$fatal(1, "[REG] counter=%d Probe signals not defined");
    end
`endif

`ifdef PROBE_TSP_OP1 `ifdef PROBE_TSP_OP2 `ifdef PROBE_TSP_RES
   `define PROBE_TSP_OK
  `endif `endif `endif
`ifdef PROBE_TSP_OK

    // three_stage_pipeline
    logic [31:0] tsp_op1;
    logic [31:0] tsp_op2;
    logic [31:0] tsp_out;
    logic [63:0] tsp_reg1;
    logic [63:0] tsp_reg2;
    logic [31:0] tsp_reg3;
    logic [31:0] tsp_reg4;
    
    always_comb begin: tsp_input
        dut.core.`PROBE_TSP_OP1 = counter[31:0];
        dut.core.`PROBE_TSP_OP2 = {counter[1], counter[2], counter[0], counter[31:3]};
    end
    always_ff @(posedge clock) begin: tsp_test
        
        if (reset_done) begin  
            //$display("[TSP] counter=%d op1=%b, op2=%b, out=%b", counter, tsp_op1, tsp_op2, tsp_out);
        end
        
        
        tsp_op1 <= dut.core.`PROBE_TSP_OP1;
        tsp_op2 <= dut.core.`PROBE_TSP_OP2;
        tsp_out <= dut.core.`PROBE_TSP_RES;
        
        if(reset)begin
            tsp_reg1[63:0] <= 64'd0;
            tsp_reg2[63:0] <= 64'd0;
            tsp_reg3[31:0] <= 32'd0;
            tsp_reg4[31:0] <= 32'd0;
        end
        else begin
            tsp_reg1[31:0] <= dut.core.`PROBE_TSP_OP1; 
            tsp_reg1[63:32] <=  dut.core.`PROBE_TSP_OP2;
            tsp_reg2[31:0] <= tsp_reg1[31:0];
            tsp_reg2[63:32] <= (tsp_reg1[31:0] + tsp_reg1[63:32]);
            tsp_reg3 <= tsp_reg2[31:0] - tsp_reg2[63:32];
            tsp_reg4 <= tsp_reg3;
          
            
        end
        
    end // block: tsp_test
    always_ff @(negedge clock) begin: tsp_test_fail
        
        if(tsp_reg4 != tsp_out && !reset)begin
            $display("[TSP] counter=%d op1=%d, op2=%d, out=%d, trueOut=%d", counter, tsp_op1, tsp_op2, tsp_out, tsp_reg3);
            //$fatal(1, "[TSP] counter=%d bad out");
        end
        
    end
`else
    always_ff @(posedge clock) begin: tsp_test
        $fatal(1, "[TSP] counter=%d Probe signals not defined");
    end
`endif


`ifdef VCD
    initial begin
        $dumpfile(`VCD_FILE);
        $dumpvars;
    end
`endif
endmodule
