// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_Mem.h for the primary calling header

#include "Vtest_Mem__pch.h"
#include "Vtest_Mem__Syms.h"
#include "Vtest_Mem___024root.h"

void Vtest_Mem___024root___ctor_var_reset(Vtest_Mem___024root* vlSelf);

Vtest_Mem___024root::Vtest_Mem___024root(Vtest_Mem__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtest_Mem___024root___ctor_var_reset(this);
}

void Vtest_Mem___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtest_Mem___024root::~Vtest_Mem___024root() {
}
