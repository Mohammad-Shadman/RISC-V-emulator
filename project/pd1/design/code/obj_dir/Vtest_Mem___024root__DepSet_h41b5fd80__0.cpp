// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_Mem.h for the primary calling header

#include "Vtest_Mem__pch.h"
#include "Vtest_Mem___024root.h"

VL_ATTR_COLD void Vtest_Mem___024root___eval_initial__TOP(Vtest_Mem___024root* vlSelf);
VlCoroutine Vtest_Mem___024root___eval_initial__TOP__Vtiming__0(Vtest_Mem___024root* vlSelf);
VlCoroutine Vtest_Mem___024root___eval_initial__TOP__Vtiming__1(Vtest_Mem___024root* vlSelf);

void Vtest_Mem___024root___eval_initial(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_initial\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtest_Mem___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtest_Mem___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtest_Mem___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtest_Mem___024root___eval_initial__TOP__Vtiming__0(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.test_Mem__DOT__readE = 1U;
    vlSelfRef.test_Mem__DOT__writeE = 0U;
    vlSelfRef.test_Mem__DOT__addressDbg = 0x1000000U;
    vlSelfRef.test_Mem__DOT__address = 0x1000000U;
    vlSelfRef.test_Mem__DOT__data_in = 0xdeadbeefU;
    vlSelfRef.test_Mem__DOT__readEDbg = 1U;
    vlSelfRef.test_Mem__DOT__writeEDbg = 0U;
    vlSelfRef.test_Mem__DOT__resetDbg = 0U;
    while (VL_LTES_III(32, 0x64U, vlSelfRef.test_Mem__DOT__counter)) {
        {
            vlSelfRef.test_Mem__DOT__addressDbg = ((IData)(4U) 
                                                   + vlSelfRef.test_Mem__DOT__addressDbg);
            if (VL_UNLIKELY((((IData)(vlSelfRef.test_Mem__DOT__readE) 
                              & (vlSelfRef.test_Mem__DOT__data_out 
                                 != vlSelfRef.test_Mem__DOT__data_outDbg))))) {
                vlSelfRef.test_Mem__DOT__err = ((IData)(1U) 
                                                + vlSelfRef.test_Mem__DOT__err);
                VL_WRITEF_NX("read data not matched %10# != %10#\n",0,
                             32,vlSelfRef.test_Mem__DOT__data_out,
                             32,vlSelfRef.test_Mem__DOT__data_outDbg);
            }
            if (vlSelfRef.test_Mem__DOT__writeE) {
                co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                                     nullptr, 
                                                     "test_Mem.sv", 
                                                     59);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
                if (VL_UNLIKELY(((0xdeadbeefU != vlSelfRef.test_Mem__DOT__data_out)))) {
                    VL_WRITEF_NX("write data not matched %x != DEADBEEF%10#\n",0,
                                 32,vlSelfRef.test_Mem__DOT__data_out,
                                 32,vlSelfRef.test_Mem__DOT__data_outDbg);
                    vlSelfRef.test_Mem__DOT__err = 
                        ((IData)(1U) + vlSelfRef.test_Mem__DOT__err);
                }
                co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                                     nullptr, 
                                                     "test_Mem.sv", 
                                                     64);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
                goto __Vlabel0;
            }
            co_await vlSelfRef.__VdlySched.delay(2ULL, 
                                                 nullptr, 
                                                 "test_Mem.sv", 
                                                 67);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            __Vlabel0: ;
        }
    }
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

void Vtest_Mem___024root___act_sequent__TOP__0(Vtest_Mem___024root* vlSelf);

void Vtest_Mem___024root___eval_act(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_act\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtest_Mem___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtest_Mem___024root___act_sequent__TOP__0(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___act_sequent__TOP__0\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.test_Mem__DOT__memTester__DOT__address 
        = (vlSelfRef.test_Mem__DOT__address - (IData)(0x1000000U));
    if (vlSelfRef.test_Mem__DOT__readE) {
        vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk4__DOT__j = 4U;
        vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch 
            = ((0xffffff00U & vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch) 
               | ((0x400000U >= (0x7fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__address))
                   ? vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory
                  [(0x7fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__address)]
                   : 0U));
        vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch 
            = ((0xffff00ffU & vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(1U) 
                                               + vlSelfRef.test_Mem__DOT__memTester__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory
                   [(0x7fffffU & ((IData)(1U) + vlSelfRef.test_Mem__DOT__memTester__DOT__address))]
                    : 0U) << 8U));
        vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch 
            = ((0xff00ffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(2U) 
                                               + vlSelfRef.test_Mem__DOT__memTester__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory
                   [(0x7fffffU & ((IData)(2U) + vlSelfRef.test_Mem__DOT__memTester__DOT__address))]
                    : 0U) << 0x10U));
        vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch 
            = ((0xffffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(3U) 
                                               + vlSelfRef.test_Mem__DOT__memTester__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory
                   [(0x7fffffU & ((IData)(3U) + vlSelfRef.test_Mem__DOT__memTester__DOT__address))]
                    : 0U) << 0x18U));
    } else {
        vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch = 0U;
    }
    vlSelfRef.test_Mem__DOT__memDebuger__DOT__address 
        = (vlSelfRef.test_Mem__DOT__addressDbg - (IData)(0x1000000U));
    if (vlSelfRef.test_Mem__DOT__readEDbg) {
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk4__DOT__j = 4U;
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch 
            = ((0xffffff00U & vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch) 
               | ((0x400000U >= (0x7fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))
                   ? vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory
                  [(0x7fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)]
                   : 0U));
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch 
            = ((0xffff00ffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(1U) 
                                               + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory
                   [(0x7fffffU & ((IData)(1U) + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))]
                    : 0U) << 8U));
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch 
            = ((0xff00ffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(2U) 
                                               + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory
                   [(0x7fffffU & ((IData)(2U) + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))]
                    : 0U) << 0x10U));
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch 
            = ((0xffffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(3U) 
                                               + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory
                   [(0x7fffffU & ((IData)(3U) + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))]
                    : 0U) << 0x18U));
    } else {
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch = 0U;
    }
    vlSelfRef.test_Mem__DOT__data_out = vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch;
    vlSelfRef.test_Mem__DOT__data_outDbg = vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch;
}

void Vtest_Mem___024root___nba_sequent__TOP__0(Vtest_Mem___024root* vlSelf);
void Vtest_Mem___024root___nba_sequent__TOP__1(Vtest_Mem___024root* vlSelf);
void Vtest_Mem___024root___nba_sequent__TOP__2(Vtest_Mem___024root* vlSelf);
void Vtest_Mem___024root___nba_comb__TOP__0(Vtest_Mem___024root* vlSelf);

void Vtest_Mem___024root___eval_nba(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_nba\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtest_Mem___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtest_Mem___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtest_Mem___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtest_Mem___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

VL_INLINE_OPT void Vtest_Mem___024root___nba_sequent__TOP__0(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___nba_sequent__TOP__0\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.test_Mem__DOT__readEDbg) {
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk4__DOT__j = 4U;
    }
}

VL_INLINE_OPT void Vtest_Mem___024root___nba_sequent__TOP__1(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___nba_sequent__TOP__1\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__test_Mem__DOT__readE;
    __Vdly__test_Mem__DOT__readE = 0;
    CData/*0:0*/ __VdlyMask__test_Mem__DOT__readE;
    __VdlyMask__test_Mem__DOT__readE = 0;
    CData/*0:0*/ __Vdly__test_Mem__DOT__writeE;
    __Vdly__test_Mem__DOT__writeE = 0;
    CData/*0:0*/ __VdlyMask__test_Mem__DOT__writeE;
    __VdlyMask__test_Mem__DOT__writeE = 0;
    IData/*31:0*/ __Vdly__test_Mem__DOT__address;
    __Vdly__test_Mem__DOT__address = 0;
    // Body
    if (vlSelfRef.test_Mem__DOT__reset) {
        vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk2__DOT__i = 0U;
        while (VL_GTS_III(32, 0x7fU, vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk2__DOT__i)) {
            vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk2__DOT__i 
                = ((IData)(1U) + vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk2__DOT__i);
        }
    }
    if (vlSelfRef.test_Mem__DOT__resetDbg) {
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk2__DOT__i = 0U;
        while (VL_GTS_III(32, 0x7fU, vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk2__DOT__i)) {
            vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk2__DOT__i 
                = ((IData)(1U) + vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk2__DOT__i);
        }
    }
    if (vlSelfRef.test_Mem__DOT__writeEDbg) {
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk3__DOT__j = 4U;
    }
    if ((0U == VL_MODDIVS_III(32, ((IData)(1U) + vlSelfRef.test_Mem__DOT__counter), (IData)(4U)))) {
        __Vdly__test_Mem__DOT__writeE = (1U & (~ (IData)(vlSelfRef.test_Mem__DOT__writeE)));
        __VdlyMask__test_Mem__DOT__writeE = 1U;
    }
    if (vlSelfRef.test_Mem__DOT__writeE) {
        vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk3__DOT__j = 4U;
    }
    if (VL_UNLIKELY(((0x1000000U > vlSelfRef.test_Mem__DOT__addressDbg)))) {
        VL_WRITEF_NX("addr_i < base_addr\n",0);
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__address = 0U;
    }
    if ((0U == VL_MODDIVS_III(32, ((IData)(1U) + vlSelfRef.test_Mem__DOT__counter), (IData)(4U)))) {
        __Vdly__test_Mem__DOT__readE = (1U & (~ (IData)(vlSelfRef.test_Mem__DOT__readE)));
        __VdlyMask__test_Mem__DOT__readE = 1U;
    }
    vlSelfRef.test_Mem__DOT__memDebuger__DOT__address 
        = (vlSelfRef.test_Mem__DOT__memDebuger__DOT__address 
           - (3U & vlSelfRef.test_Mem__DOT__memDebuger__DOT__address));
    if (vlSelfRef.test_Mem__DOT__writeEDbg) {
        vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_hd7e9cbb7__0 
            = (0xffU & vlSelfRef.test_Mem__DOT__data_inDbg);
        if ((0x400000U >= (0x7fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))) {
            vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory[(0x7fffffU 
                                                                   & vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)] 
                = vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_hd7e9cbb7__0;
        }
        vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_hd7e9cbb7__0 
            = (0xffU & (vlSelfRef.test_Mem__DOT__data_inDbg 
                        >> 8U));
        if ((0x400000U >= (0x7fffffU & ((IData)(1U) 
                                        + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)))) {
            vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory[(0x7fffffU 
                                                                   & ((IData)(1U) 
                                                                      + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))] 
                = vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_hd7e9cbb7__0;
        }
        vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_hd7e9cbb7__0 
            = (0xffU & (vlSelfRef.test_Mem__DOT__data_inDbg 
                        >> 0x10U));
        if ((0x400000U >= (0x7fffffU & ((IData)(2U) 
                                        + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)))) {
            vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory[(0x7fffffU 
                                                                   & ((IData)(2U) 
                                                                      + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))] 
                = vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_hd7e9cbb7__0;
        }
        vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_hd7e9cbb7__0 
            = (vlSelfRef.test_Mem__DOT__data_inDbg 
               >> 0x18U);
        if ((0x400000U >= (0x7fffffU & ((IData)(3U) 
                                        + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)))) {
            vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory[(0x7fffffU 
                                                                   & ((IData)(3U) 
                                                                      + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))] 
                = vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_hd7e9cbb7__0;
        }
    }
    __Vdly__test_Mem__DOT__address = ((IData)(4U) + vlSelfRef.test_Mem__DOT__address);
    if (VL_UNLIKELY(((0x1000000U > vlSelfRef.test_Mem__DOT__address)))) {
        VL_WRITEF_NX("addr_i < base_addr\n",0);
        vlSelfRef.test_Mem__DOT__memTester__DOT__address = 0U;
    }
    vlSelfRef.test_Mem__DOT__memTester__DOT__address 
        = (vlSelfRef.test_Mem__DOT__memTester__DOT__address 
           - (3U & vlSelfRef.test_Mem__DOT__memTester__DOT__address));
    if (vlSelfRef.test_Mem__DOT__writeE) {
        vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_hd7e9cbb7__0 
            = (0xffU & vlSelfRef.test_Mem__DOT__data_in);
        if ((0x400000U >= (0x7fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__address))) {
            vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory[(0x7fffffU 
                                                                  & vlSelfRef.test_Mem__DOT__memTester__DOT__address)] 
                = vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_hd7e9cbb7__0;
        }
        vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_hd7e9cbb7__0 
            = (0xffU & (vlSelfRef.test_Mem__DOT__data_in 
                        >> 8U));
        if ((0x400000U >= (0x7fffffU & ((IData)(1U) 
                                        + vlSelfRef.test_Mem__DOT__memTester__DOT__address)))) {
            vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory[(0x7fffffU 
                                                                  & ((IData)(1U) 
                                                                     + vlSelfRef.test_Mem__DOT__memTester__DOT__address))] 
                = vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_hd7e9cbb7__0;
        }
        vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_hd7e9cbb7__0 
            = (0xffU & (vlSelfRef.test_Mem__DOT__data_in 
                        >> 0x10U));
        if ((0x400000U >= (0x7fffffU & ((IData)(2U) 
                                        + vlSelfRef.test_Mem__DOT__memTester__DOT__address)))) {
            vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory[(0x7fffffU 
                                                                  & ((IData)(2U) 
                                                                     + vlSelfRef.test_Mem__DOT__memTester__DOT__address))] 
                = vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_hd7e9cbb7__0;
        }
        vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_hd7e9cbb7__0 
            = (vlSelfRef.test_Mem__DOT__data_in >> 0x18U);
        if ((0x400000U >= (0x7fffffU & ((IData)(3U) 
                                        + vlSelfRef.test_Mem__DOT__memTester__DOT__address)))) {
            vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory[(0x7fffffU 
                                                                  & ((IData)(3U) 
                                                                     + vlSelfRef.test_Mem__DOT__memTester__DOT__address))] 
                = vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_hd7e9cbb7__0;
        }
    }
    vlSelfRef.test_Mem__DOT__prevData = vlSelfRef.test_Mem__DOT__data_out;
    vlSelfRef.test_Mem__DOT__readE = (((IData)(__Vdly__test_Mem__DOT__readE) 
                                       & (IData)(__VdlyMask__test_Mem__DOT__readE)) 
                                      | ((IData)(vlSelfRef.test_Mem__DOT__readE) 
                                         & (~ (IData)(__VdlyMask__test_Mem__DOT__readE))));
    __VdlyMask__test_Mem__DOT__readE = 0U;
    vlSelfRef.test_Mem__DOT__writeE = (((IData)(__Vdly__test_Mem__DOT__writeE) 
                                        & (IData)(__VdlyMask__test_Mem__DOT__writeE)) 
                                       | ((IData)(vlSelfRef.test_Mem__DOT__writeE) 
                                          & (~ (IData)(__VdlyMask__test_Mem__DOT__writeE))));
    __VdlyMask__test_Mem__DOT__writeE = 0U;
    vlSelfRef.test_Mem__DOT__address = __Vdly__test_Mem__DOT__address;
}

VL_INLINE_OPT void Vtest_Mem___024root___nba_sequent__TOP__2(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___nba_sequent__TOP__2\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.test_Mem__DOT__memDebuger__DOT__address 
        = (vlSelfRef.test_Mem__DOT__addressDbg - (IData)(0x1000000U));
}

VL_INLINE_OPT void Vtest_Mem___024root___nba_comb__TOP__0(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___nba_comb__TOP__0\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.test_Mem__DOT__memTester__DOT__address 
        = (vlSelfRef.test_Mem__DOT__address - (IData)(0x1000000U));
    if (vlSelfRef.test_Mem__DOT__readE) {
        vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk4__DOT__j = 4U;
        vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch 
            = ((0xffffff00U & vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch) 
               | ((0x400000U >= (0x7fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__address))
                   ? vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory
                  [(0x7fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__address)]
                   : 0U));
        vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch 
            = ((0xffff00ffU & vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(1U) 
                                               + vlSelfRef.test_Mem__DOT__memTester__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory
                   [(0x7fffffU & ((IData)(1U) + vlSelfRef.test_Mem__DOT__memTester__DOT__address))]
                    : 0U) << 8U));
        vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch 
            = ((0xff00ffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(2U) 
                                               + vlSelfRef.test_Mem__DOT__memTester__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory
                   [(0x7fffffU & ((IData)(2U) + vlSelfRef.test_Mem__DOT__memTester__DOT__address))]
                    : 0U) << 0x10U));
        vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch 
            = ((0xffffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(3U) 
                                               + vlSelfRef.test_Mem__DOT__memTester__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory
                   [(0x7fffffU & ((IData)(3U) + vlSelfRef.test_Mem__DOT__memTester__DOT__address))]
                    : 0U) << 0x18U));
    } else {
        vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch = 0U;
    }
    if (vlSelfRef.test_Mem__DOT__readEDbg) {
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch 
            = ((0xffffff00U & vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch) 
               | ((0x400000U >= (0x7fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))
                   ? vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory
                  [(0x7fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)]
                   : 0U));
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch 
            = ((0xffff00ffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(1U) 
                                               + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory
                   [(0x7fffffU & ((IData)(1U) + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))]
                    : 0U) << 8U));
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch 
            = ((0xff00ffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(2U) 
                                               + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory
                   [(0x7fffffU & ((IData)(2U) + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))]
                    : 0U) << 0x10U));
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch 
            = ((0xffffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch) 
               | (((0x400000U >= (0x7fffffU & ((IData)(3U) 
                                               + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address)))
                    ? vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory
                   [(0x7fffffU & ((IData)(3U) + vlSelfRef.test_Mem__DOT__memDebuger__DOT__address))]
                    : 0U) << 0x18U));
    } else {
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch = 0U;
    }
    vlSelfRef.test_Mem__DOT__data_outDbg = vlSelfRef.test_Mem__DOT__memDebuger__DOT__data_fetch;
    vlSelfRef.test_Mem__DOT__data_out = vlSelfRef.test_Mem__DOT__memTester__DOT__data_fetch;
}

void Vtest_Mem___024root___timing_resume(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___timing_resume\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtest_Mem___024root___eval_triggers__act(Vtest_Mem___024root* vlSelf);

bool Vtest_Mem___024root___eval_phase__act(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_phase__act\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtest_Mem___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtest_Mem___024root___timing_resume(vlSelf);
        Vtest_Mem___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtest_Mem___024root___eval_phase__nba(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_phase__nba\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtest_Mem___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_Mem___024root___dump_triggers__nba(Vtest_Mem___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_Mem___024root___dump_triggers__act(Vtest_Mem___024root* vlSelf);
#endif  // VL_DEBUG

void Vtest_Mem___024root___eval(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtest_Mem___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("test_Mem.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtest_Mem___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("test_Mem.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtest_Mem___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtest_Mem___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtest_Mem___024root___eval_debug_assertions(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_debug_assertions\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
