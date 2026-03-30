// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtest_Mem__Syms.h"


void Vtest_Mem___024root__trace_chg_0_sub_0(Vtest_Mem___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtest_Mem___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root__trace_chg_0\n"); );
    // Init
    Vtest_Mem___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtest_Mem___024root*>(voidSelf);
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtest_Mem___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtest_Mem___024root__trace_chg_0_sub_0(Vtest_Mem___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root__trace_chg_0_sub_0\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.test_Mem__DOT__data_in),32);
        bufp->chgIData(oldp+1,(vlSelfRef.test_Mem__DOT__addressDbg),32);
        bufp->chgBit(oldp+2,(vlSelfRef.test_Mem__DOT__readEDbg));
        bufp->chgBit(oldp+3,(vlSelfRef.test_Mem__DOT__writeEDbg));
        bufp->chgBit(oldp+4,(vlSelfRef.test_Mem__DOT__resetDbg));
        bufp->chgIData(oldp+5,(vlSelfRef.test_Mem__DOT__err),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgIData(oldp+6,(vlSelfRef.test_Mem__DOT__data_out),32);
        bufp->chgIData(oldp+7,(vlSelfRef.test_Mem__DOT__data_outDbg),32);
        bufp->chgIData(oldp+8,(vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch),32);
        bufp->chgIData(oldp+9,(vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch),32);
        bufp->chgIData(oldp+10,(vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk4__DOT__j),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+11,(vlSelfRef.test_Mem__DOT__prevData),32);
        bufp->chgIData(oldp+12,(vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+13,(vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk3__DOT__j),32);
        bufp->chgIData(oldp+14,(vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+15,(vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk3__DOT__j),32);
    }
    bufp->chgBit(oldp+16,(vlSelfRef.test_Mem__DOT__clock));
    bufp->chgIData(oldp+17,(vlSelfRef.test_Mem__DOT__address),32);
    bufp->chgBit(oldp+18,(vlSelfRef.test_Mem__DOT__readE));
    bufp->chgBit(oldp+19,(vlSelfRef.test_Mem__DOT__writeE));
    bufp->chgIData(oldp+20,(vlSelfRef.test_Mem__DOT__counter),32);
    bufp->chgIData(oldp+21,(vlSelfRef.test_Mem__DOT__memDebuger__DOT__address),32);
    bufp->chgIData(oldp+22,(vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i),32);
    bufp->chgIData(oldp+23,(vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk4__DOT__j),32);
    bufp->chgIData(oldp+24,(vlSelfRef.test_Mem__DOT__memTester__DOT__address),32);
    bufp->chgIData(oldp+25,(vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i),32);
}

void Vtest_Mem___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root__trace_cleanup\n"); );
    // Init
    Vtest_Mem___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtest_Mem___024root*>(voidSelf);
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
