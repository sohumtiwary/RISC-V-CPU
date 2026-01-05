// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top__pch.h"
#include "Vtb_top__Syms.h"
#include "Vtb_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__stl(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_top___024root___eval_triggers__stl(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_triggers__stl\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_top___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtb_top___024root___stl_sequent__TOP__0(Vtb_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___stl_sequent__TOP__0\n"); );
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_top__DOT__dut__DOT__core_i__DOT__rs1_val;
    tb_top__DOT__dut__DOT__core_i__DOT__rs1_val = 0;
    CData/*0:0*/ tb_top__DOT__dut__DOT__core_i__DOT____VdfgExtracted_hcd2084b8__0;
    tb_top__DOT__dut__DOT__core_i__DOT____VdfgExtracted_hcd2084b8__0 = 0;
    // Body
    vlSelfRef.tb_top__DOT__dut__DOT__instr = vlSelfRef.tb_top__DOT__dut__DOT__imem_i__DOT__mem
        [(0xffU & (vlSelfRef.tb_top__DOT__dut__DOT__pc 
                   >> 2U))];
    if ((1U & (~ VL_ONEHOT_I((((0x6fU == (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr)) 
                               << 2U) | (((0x33U == 
                                           (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr)) 
                                          << 1U) | 
                                         (0x13U == 
                                          (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr)))))))) {
        if ((0U != (((0x6fU == (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr)) 
                     << 2U) | (((0x33U == (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr)) 
                                << 1U) | (0x13U == 
                                          (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr)))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: core.sv:66: Assertion failed in %Ntb_top.dut.core_i: unique case, but multiple matches found for '7'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name(),7,
                             (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr));
                VL_STOP_MT("C:/Users/sohum/RISC-V-CPU/rtl/core\\core.sv", 66, "");
            }
        }
    }
    vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__next_pc 
        = ((IData)(4U) + vlSelfRef.tb_top__DOT__dut__DOT__pc);
    if ((0x13U != (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr))) {
        if ((0x33U != (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr))) {
            if ((0x6fU == (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr))) {
                vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__next_pc 
                    = (vlSelfRef.tb_top__DOT__dut__DOT__pc 
                       + ((((- (IData)((vlSelfRef.tb_top__DOT__dut__DOT__instr 
                                        >> 0x1fU))) 
                            << 0x15U) | (0x100000U 
                                         & (vlSelfRef.tb_top__DOT__dut__DOT__instr 
                                            >> 0xbU))) 
                          | (((0xff000U & vlSelfRef.tb_top__DOT__dut__DOT__instr) 
                              | (0x800U & (vlSelfRef.tb_top__DOT__dut__DOT__instr 
                                           >> 9U))) 
                             | (0x7feU & (vlSelfRef.tb_top__DOT__dut__DOT__instr 
                                          >> 0x14U)))));
            }
        }
    }
    tb_top__DOT__dut__DOT__core_i__DOT__rs1_val = (
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelfRef.tb_top__DOT__dut__DOT__instr 
                                                        >> 0xfU)))
                                                    ? 0U
                                                    : 
                                                   vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__regs
                                                   [
                                                   (0x1fU 
                                                    & (vlSelfRef.tb_top__DOT__dut__DOT__instr 
                                                       >> 0xfU))]);
    tb_top__DOT__dut__DOT__core_i__DOT____VdfgExtracted_hcd2084b8__0 
        = (IData)((0U == (0xfe007000U & vlSelfRef.tb_top__DOT__dut__DOT__instr)));
    vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__reg_we = 0U;
    vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__reg_wdata = 0U;
    if ((0x13U == (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr))) {
        if ((0U == (7U & (vlSelfRef.tb_top__DOT__dut__DOT__instr 
                          >> 0xcU)))) {
            vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__reg_we = 1U;
            vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__reg_wdata 
                = (tb_top__DOT__dut__DOT__core_i__DOT__rs1_val 
                   + (((- (IData)((vlSelfRef.tb_top__DOT__dut__DOT__instr 
                                   >> 0x1fU))) << 0xcU) 
                      | (vlSelfRef.tb_top__DOT__dut__DOT__instr 
                         >> 0x14U)));
        }
    } else if ((0x33U == (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr))) {
        if (tb_top__DOT__dut__DOT__core_i__DOT____VdfgExtracted_hcd2084b8__0) {
            vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__reg_we = 1U;
            vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__reg_wdata 
                = (tb_top__DOT__dut__DOT__core_i__DOT__rs1_val 
                   + ((0U == (0x1fU & (vlSelfRef.tb_top__DOT__dut__DOT__instr 
                                       >> 0x14U))) ? 0U
                       : vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__regs
                      [(0x1fU & (vlSelfRef.tb_top__DOT__dut__DOT__instr 
                                 >> 0x14U))]));
        }
    } else if ((0x6fU == (0x7fU & vlSelfRef.tb_top__DOT__dut__DOT__instr))) {
        vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__reg_we = 1U;
        vlSelfRef.tb_top__DOT__dut__DOT__core_i__DOT__reg_wdata 
            = ((IData)(4U) + vlSelfRef.tb_top__DOT__dut__DOT__pc);
    }
}
