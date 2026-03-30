module testMem;

    logic        clock;
    logic [31:0] address;
    logic [31:0] data_in;
    logic [31:0] data_out;
    reg          readE;
    reg          writeE;
    reg          reset;
    int          counter;

    logic [31:0] addressDbg;
    logic [31:0] data_inDbg;
    logic [31:0] data_outDbg;
    reg          readEDbg;
    reg          writeEDbg;
    reg          resetDbg;
    int          prevData;
    int          err;
    
    


    memory memTester(
                     .reset(reset),
                     .clock(clock),
                     .address(address),
                     .data_in(data_in),
                     .data_out(data_out),
                     .read_en_i(readE),
                     .write_en_i(writeE)
      );

    memory memDebuger(
                      .reset(resetDbg),
                      .clock(clockDbg),
                      .address(addressDbg),
                      .data_in(data_inDbg),
                      .data_out(data_outDbg),
                      .read_en_i(readEDbg),
                      .write_en_i(writeEDbg)
      );


    initial begin
        readE      = 1;
        writeE     = 0;
        addressDbg = 32'h01000000;
        address    = 32'h01000000;
        data_in    = 32'hDEADBEEF;
        readEDbg   = 1;
        writeEDbg  = 0;
        resetDbg   = 0;
        while(counter >= 100)begin
            addressDbg = addressDbg + 4;
            if(readE && data_out != data_outDbg)begin
                err = err+1;
                $display("read data not matched %d != %d",data_out,data_outDbg);
            end
            if(writeE)begin
                #1;
                if(data_out != 32'hDEADBEEF)begin
                    $display("write data not matched %h != DEADBEEF",data_out,data_outDbg);
                    err = err + 1;
                end
                #1;
                continue;
            end
            #2;
        end
    end

    always_comb begin
        clock   = ~clock;
        counter =  counter + 1;
        if(counter >=100)begin
            $display("ran succsesfully with %d errors found",err);
            $finish;
        end
        #1;

    end

    always_ff @(posedge clock) begin
        if((counter+1)%4==0) begin
        readE   <= ~readE;
        writeE  <= ~writeE;
        end
        address <=  address + 4;
        prevData <= data_out;
    end



endmodule
