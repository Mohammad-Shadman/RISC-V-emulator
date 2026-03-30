// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_Mem.h for the primary calling header

#include "Vtest_Mem__pch.h"
#include "Vtest_Mem___024root.h"

VL_ATTR_COLD void Vtest_Mem___024root___eval_static__TOP(Vtest_Mem___024root* vlSelf);
VL_ATTR_COLD void Vtest_Mem___024root____Vm_traceActivitySetAll(Vtest_Mem___024root* vlSelf);

VL_ATTR_COLD void Vtest_Mem___024root___eval_static(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_static\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtest_Mem___024root___eval_static__TOP(vlSelf);
    Vtest_Mem___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__test_Mem__DOT__clock__0 
        = vlSelfRef.test_Mem__DOT__clock;
}

VL_ATTR_COLD void Vtest_Mem___024root___eval_static__TOP(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_static__TOP\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.test_Mem__DOT__address = 0x1000000U;
    vlSelfRef.test_Mem__DOT__addressDbg = 0x1000000U;
}

extern const VlWide<16>/*511:0*/ Vtest_Mem__ConstPool__CONST_h35324973_0;

VL_ATTR_COLD void Vtest_Mem___024root___eval_initial__TOP(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_initial__TOP\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_READMEM_N(true, 32, 1048577, 0, VL_CVT_PACK_STR_NW(16, Vtest_Mem__ConstPool__CONST_h35324973_0)
                 ,  &(vlSelfRef.test_Mem__DOT__memTester__DOT__temp_memory)
                 , 0, ~0ULL);
    vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x7fU, vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_hb9f4f850__0 
            = ((0x100000U >= (0x1fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i))
                ? (0xffU & vlSelfRef.test_Mem__DOT__memTester__DOT__temp_memory
                   [(0x1fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i)])
                : 0U);
        if (VL_LIKELY(((0x400000U >= (0x7fffffU & VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i)))))) {
            vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory[(0x7fffffU 
                                                                  & VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i))] 
                = vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_hb9f4f850__0;
        }
        vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_h9ec4626e__0 
            = (0xffU & (((0x100000U >= (0x1fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i))
                          ? vlSelfRef.test_Mem__DOT__memTester__DOT__temp_memory
                         [(0x1fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i)]
                          : 0U) >> 8U));
        if (VL_LIKELY(((0x400000U >= (0x7fffffU & ((IData)(1U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i))))))) {
            vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory[(0x7fffffU 
                                                                  & ((IData)(1U) 
                                                                     + 
                                                                     VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i)))] 
                = vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_h9ec4626e__0;
        }
        vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_h9ed5c959__0 
            = (0xffU & (((0x100000U >= (0x1fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i))
                          ? vlSelfRef.test_Mem__DOT__memTester__DOT__temp_memory
                         [(0x1fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i)]
                          : 0U) >> 0x10U));
        if (VL_LIKELY(((0x400000U >= (0x7fffffU & ((IData)(2U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i))))))) {
            vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory[(0x7fffffU 
                                                                  & ((IData)(2U) 
                                                                     + 
                                                                     VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i)))] 
                = vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_h9ed5c959__0;
        }
        vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_h9ed2f70a__0 
            = (((0x100000U >= (0x1fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i))
                 ? vlSelfRef.test_Mem__DOT__memTester__DOT__temp_memory
                [(0x1fffffU & vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i)]
                 : 0U) >> 0x18U);
        if (VL_LIKELY(((0x400000U >= (0x7fffffU & ((IData)(3U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i))))))) {
            vlSelfRef.test_Mem__DOT__memTester__DOT__main_memory[(0x7fffffU 
                                                                  & ((IData)(3U) 
                                                                     + 
                                                                     VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i)))] 
                = vlSelfRef.test_Mem__DOT__memTester__DOT____Vlvbound_h9ed2f70a__0;
        }
        vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i);
    }
    VL_WRITEF_NX("IMEMORY: Loaded 127 32-bit words from /home/mo/school/4201/RISCV/project/pd1/verif/data/test1.patten\n",0);
    VL_READMEM_N(true, 32, 1048577, 0, VL_CVT_PACK_STR_NW(16, Vtest_Mem__ConstPool__CONST_h35324973_0)
                 ,  &(vlSelfRef.test_Mem__DOT__memDebuger__DOT__temp_memory)
                 , 0, ~0ULL);
    vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x7fU, vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_hb9f4f850__0 
            = ((0x100000U >= (0x1fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i))
                ? (0xffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__temp_memory
                   [(0x1fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i)])
                : 0U);
        if (VL_LIKELY(((0x400000U >= (0x7fffffU & VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i)))))) {
            vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory[(0x7fffffU 
                                                                   & VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i))] 
                = vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_hb9f4f850__0;
        }
        vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ec4626e__0 
            = (0xffU & (((0x100000U >= (0x1fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i))
                          ? vlSelfRef.test_Mem__DOT__memDebuger__DOT__temp_memory
                         [(0x1fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i)]
                          : 0U) >> 8U));
        if (VL_LIKELY(((0x400000U >= (0x7fffffU & ((IData)(1U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i))))))) {
            vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory[(0x7fffffU 
                                                                   & ((IData)(1U) 
                                                                      + 
                                                                      VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i)))] 
                = vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ec4626e__0;
        }
        vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ed5c959__0 
            = (0xffU & (((0x100000U >= (0x1fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i))
                          ? vlSelfRef.test_Mem__DOT__memDebuger__DOT__temp_memory
                         [(0x1fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i)]
                          : 0U) >> 0x10U));
        if (VL_LIKELY(((0x400000U >= (0x7fffffU & ((IData)(2U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i))))))) {
            vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory[(0x7fffffU 
                                                                   & ((IData)(2U) 
                                                                      + 
                                                                      VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i)))] 
                = vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ed5c959__0;
        }
        vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ed2f70a__0 
            = (((0x100000U >= (0x1fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i))
                 ? vlSelfRef.test_Mem__DOT__memDebuger__DOT__temp_memory
                [(0x1fffffU & vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i)]
                 : 0U) >> 0x18U);
        if (VL_LIKELY(((0x400000U >= (0x7fffffU & ((IData)(3U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i))))))) {
            vlSelfRef.test_Mem__DOT__memDebuger__DOT__main_memory[(0x7fffffU 
                                                                   & ((IData)(3U) 
                                                                      + 
                                                                      VL_MULS_III(32, (IData)(4U), vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i)))] 
                = vlSelfRef.test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ed2f70a__0;
        }
        vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i);
    }
    VL_WRITEF_NX("IMEMORY: Loaded 127 32-bit words from /home/mo/school/4201/RISCV/project/pd1/verif/data/test1.patten\n",0);
}

VL_ATTR_COLD void Vtest_Mem___024root___eval_final(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_final\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_Mem___024root___dump_triggers__stl(Vtest_Mem___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtest_Mem___024root___eval_phase__stl(Vtest_Mem___024root* vlSelf);

VL_ATTR_COLD void Vtest_Mem___024root___eval_settle(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_settle\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtest_Mem___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("test_Mem.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtest_Mem___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_Mem___024root___dump_triggers__stl(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___dump_triggers__stl\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtest_Mem___024root___act_sequent__TOP__0(Vtest_Mem___024root* vlSelf);

VL_ATTR_COLD void Vtest_Mem___024root___eval_stl(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_stl\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtest_Mem___024root___act_sequent__TOP__0(vlSelf);
        Vtest_Mem___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vtest_Mem___024root___eval_triggers__stl(Vtest_Mem___024root* vlSelf);

VL_ATTR_COLD bool Vtest_Mem___024root___eval_phase__stl(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___eval_phase__stl\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtest_Mem___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtest_Mem___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_Mem___024root___dump_triggers__act(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___dump_triggers__act\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge test_Mem.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtest_Mem___024root___dump_triggers__nba(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___dump_triggers__nba\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge test_Mem.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtest_Mem___024root____Vm_traceActivitySetAll(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root____Vm_traceActivitySetAll\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void Vtest_Mem___024root___ctor_var_reset(Vtest_Mem___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_Mem___024root___ctor_var_reset\n"); );
    Vtest_Mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->test_Mem__DOT__clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1669843473477322143ull);
    vlSelf->test_Mem__DOT__address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4427764101365952763ull);
    vlSelf->test_Mem__DOT__data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14649143074956901865ull);
    vlSelf->test_Mem__DOT__data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6043005989692699959ull);
    vlSelf->test_Mem__DOT__readE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 767442248438728583ull);
    vlSelf->test_Mem__DOT__writeE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18321579062139303968ull);
    vlSelf->test_Mem__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2684396495071689968ull);
    vlSelf->test_Mem__DOT__counter = 0;
    vlSelf->test_Mem__DOT__addressDbg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2596611141742608540ull);
    vlSelf->test_Mem__DOT__data_inDbg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11044875581710148362ull);
    vlSelf->test_Mem__DOT__data_outDbg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4754008983135468244ull);
    vlSelf->test_Mem__DOT__readEDbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16417898899624355233ull);
    vlSelf->test_Mem__DOT__writeEDbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4254817976277930042ull);
    vlSelf->test_Mem__DOT__resetDbg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4670681063614469947ull);
    vlSelf->test_Mem__DOT__prevData = 0;
    vlSelf->test_Mem__DOT__err = 0;
    for (int __Vi0 = 0; __Vi0 < 1048577; ++__Vi0) {
        vlSelf->test_Mem__DOT__memTester__DOT__temp_memory[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14305036676258372797ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4194305; ++__Vi0) {
        vlSelf->test_Mem__DOT__memTester__DOT__main_memory[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15266706694852623457ull);
    }
    vlSelf->test_Mem__DOT__memTester__DOT__address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10062164553373447662ull);
    vlSelf->test_Mem__DOT__memTester__DOT__data_fetch = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5588158668198229155ull);
    vlSelf->test_Mem__DOT__memTester__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->test_Mem__DOT__memTester__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->test_Mem__DOT__memTester__DOT__unnamedblk3__DOT__j = 0;
    vlSelf->test_Mem__DOT__memTester__DOT__unnamedblk4__DOT__j = 0;
    vlSelf->test_Mem__DOT__memTester__DOT____Vlvbound_hb9f4f850__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15842498238458079779ull);
    vlSelf->test_Mem__DOT__memTester__DOT____Vlvbound_h9ec4626e__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15500049477043509436ull);
    vlSelf->test_Mem__DOT__memTester__DOT____Vlvbound_h9ed5c959__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10498167572193975052ull);
    vlSelf->test_Mem__DOT__memTester__DOT____Vlvbound_h9ed2f70a__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11349744497486390311ull);
    vlSelf->test_Mem__DOT__memTester__DOT____Vlvbound_hd7e9cbb7__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4805864470165358997ull);
    for (int __Vi0 = 0; __Vi0 < 1048577; ++__Vi0) {
        vlSelf->test_Mem__DOT__memDebuger__DOT__temp_memory[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10725688479076477285ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4194305; ++__Vi0) {
        vlSelf->test_Mem__DOT__memDebuger__DOT__main_memory[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6403885446989141251ull);
    }
    vlSelf->test_Mem__DOT__memDebuger__DOT__address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17020804483188591696ull);
    vlSelf->test_Mem__DOT__memDebuger__DOT__data_fetch = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2629123813354290239ull);
    vlSelf->test_Mem__DOT__memDebuger__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->test_Mem__DOT__memDebuger__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->test_Mem__DOT__memDebuger__DOT__unnamedblk3__DOT__j = 0;
    vlSelf->test_Mem__DOT__memDebuger__DOT__unnamedblk4__DOT__j = 0;
    vlSelf->test_Mem__DOT__memDebuger__DOT____Vlvbound_hb9f4f850__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5508594674522630279ull);
    vlSelf->test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ec4626e__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17085075992796081561ull);
    vlSelf->test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ed5c959__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13093164313469312700ull);
    vlSelf->test_Mem__DOT__memDebuger__DOT____Vlvbound_h9ed2f70a__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15484094865234652136ull);
    vlSelf->test_Mem__DOT__memDebuger__DOT____Vlvbound_hd7e9cbb7__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9957702845635915921ull);
    vlSelf->__Vtrigprevexpr___TOP__test_Mem__DOT__clock__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13975196849985149373ull);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
