/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "E:/faculta/FIC/0xcHa0s/xcHa0s/ALU_testbench.v";
static unsigned int ng1[] = {32768U, 0U};
static int ng2[] = {3, 0};
static int ng3[] = {42, 0};



static void Initial_30_0(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 2528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(30, ng0);

LAB4:    xsi_set_current_line(31, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(32, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(33, ng0);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    xsi_vlog_signed_unary_minus(t4, 32, t2, 32);
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    xsi_set_current_line(34, ng0);
    t2 = ((char*)((ng3)));
    memset(t4, 0, 8);
    xsi_vlog_signed_unary_minus(t4, 32, t2, 32);
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    xsi_set_current_line(35, ng0);
    t2 = (t0 + 2336);
    xsi_process_wait(t2, 32000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(36, ng0);
    t3 = (t0 + 1448);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 1608);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t4, 0, 8);
    xsi_vlog_unsigned_multiply(t4, 32, t6, 16, t9, 16);
    t10 = (t0 + 1288);
    xsi_vlogvar_assign_value(t10, t4, 0, 0, 32);
    goto LAB1;

}


extern void work_m_00000000000919404091_2334512093_init()
{
	static char *pe[] = {(void *)Initial_30_0};
	xsi_register_didat("work_m_00000000000919404091_2334512093", "isim/ALU_testbench_isim_beh.exe.sim/work/m_00000000000919404091_2334512093.didat");
	xsi_register_executes(pe);
}
