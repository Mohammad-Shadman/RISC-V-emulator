// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtest_Mem.h for the primary calling header

#ifndef VERILATED_VTEST_MEM___024ROOT_H_
#define VERILATED_VTEST_MEM___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtest_Mem__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtest_Mem___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ test_Mem__DOT__clock;
    CData/*0:0*/ test_Mem__DOT__readE;
    CData/*0:0*/ test_Mem__DOT__writeE;
    CData/*0:0*/ test_Mem__DOT__reset;
    CData/*0:0*/ test_Mem__DOT__readEDbg;
    CData/*0:0*/ test_Mem__DOT__writeEDbg;
    CData/*0:0*/ test_Mem__DOT__resetDbg;
    CData/*7:0*/ test_Mem__DOT__memTester__DOT____Vlvbound_hb9f4f850__0;
    CData/*7:0*/ test_Mem__DOT__memTester__DOT____Vlvbound_h9ec4626e__0;
    CData/*7:0*/ test_Mem__DOT__memTester__DOT____Vlvbound_h9ed5c959__0;
    CData/*7:0*/ test_Mem__DOT__memTester__DOT____Vlvbound_h9ed2f70a__0;
    CData/*7:0*/ test_Mem__DOT__memTester__DOT____Vlvbound_hd7e9cbb7__0;
    CData/*7:0*/ test_Mem__DOT__memDebuger__DOT____Vlvbound_hb9f4f850__0;
    CData/*7:0*/ test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ec4626e__0;
    CData/*7:0*/ test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ed5c959__0;
    CData/*7:0*/ test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ed2f70a__0;
    CData/*7:0*/ test_Mem__DOT__memDebuger__DOT____Vlvbound_hd7e9cbb7__0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__test_Mem__DOT__clock__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ test_Mem__DOT__address;
    IData/*31:0*/ test_Mem__DOT__data_in;
    IData/*31:0*/ test_Mem__DOT__data_out;
    IData/*31:0*/ test_Mem__DOT__counter;
    IData/*31:0*/ test_Mem__DOT__addressDbg;
    IData/*31:0*/ test_Mem__DOT__data_inDbg;
    IData/*31:0*/ test_Mem__DOT__data_outDbg;
    IData/*31:0*/ test_Mem__DOT__prevData;
    IData/*31:0*/ test_Mem__DOT__err;
    IData/*31:0*/ test_Mem__DOT__memTester__DOT__address;
    IData/*31:0*/ test_Mem__DOT__memTester__DOT__data_fetch;
    IData/*31:0*/ test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ test_Mem__DOT__memTester__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ test_Mem__DOT__memTester__DOT__unnamedblk3__DOT__j;
    IData/*31:0*/ test_Mem__DOT__memTester__DOT__unnamedblk4__DOT__j;
    IData/*31:0*/ test_Mem__DOT__memDebuger__DOT__address;
    IData/*31:0*/ test_Mem__DOT__memDebuger__DOT__data_fetch;
    IData/*31:0*/ test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ test_Mem__DOT__memDebuger__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ test_Mem__DOT__memDebuger__DOT__unnamedblk3__DOT__j;
    IData/*31:0*/ test_Mem__DOT__memDebuger__DOT__unnamedblk4__DOT__j;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 1048577> test_Mem__DOT__memTester__DOT__temp_memory;
    VlUnpacked<CData/*7:0*/, 4194305> test_Mem__DOT__memTester__DOT__main_memory;
    VlUnpacked<IData/*31:0*/, 1048577> test_Mem__DOT__memDebuger__DOT__temp_memory;
    VlUnpacked<CData/*7:0*/, 4194305> test_Mem__DOT__memDebuger__DOT__main_memory;
    VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtest_Mem__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtest_Mem___024root(Vtest_Mem__Syms* symsp, const char* v__name);
    ~Vtest_Mem___024root();
    VL_UNCOPYABLE(Vtest_Mem___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
