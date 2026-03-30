// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_Mem.h for the primary calling header

#include "Vtest_Mem__pch.h"
#include "Vtest_Mem__Syms.h"
#include "Vtest_Mem___024root.h"

VL_INLINE_OPT VlCoroutine Vtest_Mem___024root___eval_initial__TOP__Vtiming__1(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        vlSelfRef.test_Mem__DOT__clock = (1U & (~ (IData)(vlSelfRef.test_Mem__DOT__clock)));
        vlSelfRef.test_Mem__DOT__counter = ((IData)(1U) 
                                            + vlSelfRef.test_Mem__DOT__counter);
        if (VL_UNLIKELY((VL_LTES_III(32, 0x64U, vlSelfRef.test_Mem__DOT__counter)))) {
            VL_WRITEF_NX("ran succsesfully with %11d errors found\n",0,
                         32,vlSelfRef.test_Mem__DOT__err);
            VL_FINISH_MT("test_Mem.sv", 76, "");
        }
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "test_Mem.sv", 
                                             78);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_Mem___024root___dump_triggers__act(Vtest_Mem___024root* vlSelf);
#endif  // VL_DEBUG

void Vtest_Mem___024root___eval_triggers__act(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_triggers__act\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.test_Mem__DOT__clock) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__test_Mem__DOT__clock__0))));
    vlSelfRef.__VactTriggered.setBit(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__test_Mem__DOT__clock__0 
        = vlSelfRef.test_Mem__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtest_Mem___024root___dump_triggers__act(vlSelf);
    }
#endif
}
