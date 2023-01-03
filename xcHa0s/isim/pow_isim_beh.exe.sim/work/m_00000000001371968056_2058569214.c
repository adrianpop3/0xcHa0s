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
static const char *ng0 = "E:/faculta/FIC/0xcHa0s/xcHa0s/pow.v";
static int ng1[] = {1, 0};
static int ng2[] = {0, 0, 0, 0};
static int ng3[] = {0, 0};
static int ng4[] = {1, 0, 0, 0};
static unsigned int ng5[] = {2147483648U, 0U, 65535U, 0U};



static void Cont_15_0(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 4928U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(15, ng0);
    t2 = (t0 + 3048);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t3 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 0);
    *((unsigned int *)t3) = t9;
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t12 & 4294967295U);
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 4294967295U);
    t14 = (t0 + 5856);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t3, 8);
    xsi_driver_vfirst_trans(t14, 0, 31);
    t19 = (t0 + 5744);
    *((int *)t19) = 1;

LAB1:    return;
}

static void Always_18_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 5176U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(18, ng0);
    t2 = (t0 + 5760);
    *((int *)t2) = 1;
    t3 = (t0 + 5208);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(18, ng0);

LAB5:    xsi_set_current_line(19, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(25, ng0);

LAB10:    xsi_set_current_line(26, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(27, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 48, 0LL);
    xsi_set_current_line(28, ng0);
    t2 = (t0 + 3528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 16, 0LL);
    xsi_set_current_line(29, ng0);
    t2 = (t0 + 3848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 16, 0LL);
    xsi_set_current_line(30, ng0);
    t2 = (t0 + 4008);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(19, ng0);

LAB9:    xsi_set_current_line(20, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 0LL);
    xsi_set_current_line(21, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 48, 0LL);
    xsi_set_current_line(22, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 0LL);
    xsi_set_current_line(23, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3688);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 0LL);
    xsi_set_current_line(24, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB8;

}

static void Always_34_2(char *t0)
{
    char t13[8];
    char t22[8];
    char t38[8];
    char t47[8];
    char t55[8];
    char t95[8];
    char t110[8];
    char t119[8];
    char t127[8];
    char t163[16];
    char t164[16];
    char t165[16];
    char t166[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    char *t37;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    char *t101;
    char *t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    char *t107;
    char *t108;
    char *t109;
    char *t111;
    char *t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    char *t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    char *t131;
    char *t132;
    char *t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    char *t141;
    char *t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    char *t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    char *t161;
    char *t162;
    int t167;
    int t168;
    unsigned int t169;
    char *t170;

LAB0:    t1 = (t0 + 5424U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 5776);
    *((int *)t2) = 1;
    t3 = (t0 + 5456);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(34, ng0);

LAB5:    xsi_set_current_line(35, ng0);
    t4 = (t0 + 2728);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2888);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    xsi_set_current_line(36, ng0);
    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3528);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 16);
    xsi_set_current_line(37, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3848);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 16);
    xsi_set_current_line(38, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4008);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(39, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    t10 = *((unsigned int *)t4);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(48, ng0);

LAB14:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t13, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t5);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t14 = (t11 ^ t12);
    t15 = (t10 | t14);
    t16 = *((unsigned int *)t6);
    t17 = *((unsigned int *)t7);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB18;

LAB15:    if (t18 != 0)
        goto LAB17;

LAB16:    *((unsigned int *)t13) = 1;

LAB18:    memset(t22, 0, 8);
    t23 = (t13 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t13);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t23) != 0)
        goto LAB21;

LAB22:    t30 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = (!(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB23;

LAB24:    memcpy(t55, t22, 8);

LAB25:    t83 = (t55 + 4);
    t84 = *((unsigned int *)t83);
    t85 = (~(t84));
    t86 = *((unsigned int *)t55);
    t87 = (t86 & t85);
    t88 = (t87 != 0);
    if (t88 > 0)
        goto LAB33;

LAB34:    xsi_set_current_line(55, ng0);

LAB76:    xsi_set_current_line(56, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_minus(t13, 32, t4, 16, t5, 32);
    t6 = (t0 + 3848);
    xsi_vlogvar_assign_value(t6, t13, 0, 0, 16);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1528U);
    t6 = *((char **)t5);
    xsi_vlog_unsigned_multiply(t163, 48, t4, 48, t6, 16);
    t5 = (t0 + 3208);
    xsi_vlogvar_assign_value(t5, t163, 0, 0, 48);
    xsi_set_current_line(58, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    t8 = 0;

LAB80:    t9 = (t8 < 2);
    if (t9 == 1)
        goto LAB81;

LAB82:    t40 = ((char*)((ng2)));
    xsi_vlog_unsigned_equal(t164, 48, t163, 48, t40, 32);
    memset(t13, 0, 8);
    t48 = (t164 + 4);
    t58 = *((unsigned int *)t48);
    t62 = (~(t58));
    t63 = *((unsigned int *)t164);
    t64 = (t63 & t62);
    t65 = (t64 & 1U);
    if (t65 != 0)
        goto LAB83;

LAB84:    if (*((unsigned int *)t48) != 0)
        goto LAB85;

LAB86:    t59 = (t13 + 4);
    t66 = *((unsigned int *)t13);
    t67 = (!(t66));
    t68 = *((unsigned int *)t59);
    t71 = (t67 || t68);
    if (t71 > 0)
        goto LAB87;

LAB88:    memcpy(t38, t13, 8);

LAB89:    t161 = (t38 + 4);
    t157 = *((unsigned int *)t161);
    t158 = (~(t157));
    t159 = *((unsigned int *)t38);
    t160 = (t159 & t158);
    t169 = (t160 != 0);
    if (t169 > 0)
        goto LAB103;

LAB104:
LAB105:
LAB35:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(39, ng0);

LAB9:    xsi_set_current_line(40, ng0);
    t6 = ((char*)((ng3)));
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    xsi_set_current_line(41, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB8;

LAB10:    xsi_set_current_line(41, ng0);

LAB13:    xsi_set_current_line(42, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t0 + 2888);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(43, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t0 + 3528);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 16);
    xsi_set_current_line(44, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = (t0 + 3848);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 16);
    xsi_set_current_line(45, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 48);
    xsi_set_current_line(46, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB12;

LAB17:    t21 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB18;

LAB19:    *((unsigned int *)t22) = 1;
    goto LAB22;

LAB21:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB22;

LAB23:    t35 = (t0 + 3688);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    memset(t38, 0, 8);
    t39 = (t38 + 4);
    t40 = (t37 + 4);
    t41 = *((unsigned int *)t37);
    t42 = (t41 >> 15);
    t43 = (t42 & 1);
    *((unsigned int *)t38) = t43;
    t44 = *((unsigned int *)t40);
    t45 = (t44 >> 15);
    t46 = (t45 & 1);
    *((unsigned int *)t39) = t46;
    memset(t47, 0, 8);
    t48 = (t38 + 4);
    t49 = *((unsigned int *)t48);
    t50 = (~(t49));
    t51 = *((unsigned int *)t38);
    t52 = (t51 & t50);
    t53 = (t52 & 1U);
    if (t53 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t48) != 0)
        goto LAB28;

LAB29:    t56 = *((unsigned int *)t22);
    t57 = *((unsigned int *)t47);
    t58 = (t56 | t57);
    *((unsigned int *)t55) = t58;
    t59 = (t22 + 4);
    t60 = (t47 + 4);
    t61 = (t55 + 4);
    t62 = *((unsigned int *)t59);
    t63 = *((unsigned int *)t60);
    t64 = (t62 | t63);
    *((unsigned int *)t61) = t64;
    t65 = *((unsigned int *)t61);
    t66 = (t65 != 0);
    if (t66 == 1)
        goto LAB30;

LAB31:
LAB32:    goto LAB25;

LAB26:    *((unsigned int *)t47) = 1;
    goto LAB29;

LAB28:    t54 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB29;

LAB30:    t67 = *((unsigned int *)t55);
    t68 = *((unsigned int *)t61);
    *((unsigned int *)t55) = (t67 | t68);
    t69 = (t22 + 4);
    t70 = (t47 + 4);
    t71 = *((unsigned int *)t69);
    t72 = (~(t71));
    t73 = *((unsigned int *)t22);
    t74 = (t73 & t72);
    t75 = *((unsigned int *)t70);
    t76 = (~(t75));
    t77 = *((unsigned int *)t47);
    t78 = (t77 & t76);
    t79 = (~(t74));
    t80 = (~(t78));
    t81 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t81 & t79);
    t82 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t82 & t80);
    goto LAB32;

LAB33:    xsi_set_current_line(49, ng0);

LAB36:    xsi_set_current_line(50, ng0);
    t89 = ((char*)((ng3)));
    t90 = (t0 + 2408);
    xsi_vlogvar_assign_value(t90, t89, 0, 0, 1);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 3688);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t13, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = *((unsigned int *)t5);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t14 = (t11 ^ t12);
    t15 = (t10 | t14);
    t16 = *((unsigned int *)t6);
    t17 = *((unsigned int *)t7);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB40;

LAB37:    if (t18 != 0)
        goto LAB39;

LAB38:    *((unsigned int *)t13) = 1;

LAB40:    memset(t22, 0, 8);
    t23 = (t13 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t13);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB41;

LAB42:    if (*((unsigned int *)t23) != 0)
        goto LAB43;

LAB44:    t30 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t30);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB45;

LAB46:    memcpy(t55, t22, 8);

LAB47:    memset(t95, 0, 8);
    t90 = (t55 + 4);
    t96 = *((unsigned int *)t90);
    t97 = (~(t96));
    t98 = *((unsigned int *)t55);
    t99 = (t98 & t97);
    t100 = (t99 & 1U);
    if (t100 != 0)
        goto LAB59;

LAB60:    if (*((unsigned int *)t90) != 0)
        goto LAB61;

LAB62:    t102 = (t95 + 4);
    t103 = *((unsigned int *)t95);
    t104 = (!(t103));
    t105 = *((unsigned int *)t102);
    t106 = (t104 || t105);
    if (t106 > 0)
        goto LAB63;

LAB64:    memcpy(t127, t95, 8);

LAB65:    t155 = (t127 + 4);
    t156 = *((unsigned int *)t155);
    t157 = (~(t156));
    t158 = *((unsigned int *)t127);
    t159 = (t158 & t157);
    t160 = (t159 != 0);
    if (t160 > 0)
        goto LAB73;

LAB74:
LAB75:    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB35;

LAB39:    t21 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB40;

LAB41:    *((unsigned int *)t22) = 1;
    goto LAB44;

LAB43:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB44;

LAB45:    t35 = (t0 + 3368);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t39 = ((char*)((ng3)));
    memset(t38, 0, 8);
    t40 = (t37 + 4);
    t48 = (t39 + 4);
    t34 = *((unsigned int *)t37);
    t41 = *((unsigned int *)t39);
    t42 = (t34 ^ t41);
    t43 = *((unsigned int *)t40);
    t44 = *((unsigned int *)t48);
    t45 = (t43 ^ t44);
    t46 = (t42 | t45);
    t49 = *((unsigned int *)t40);
    t50 = *((unsigned int *)t48);
    t51 = (t49 | t50);
    t52 = (~(t51));
    t53 = (t46 & t52);
    if (t53 != 0)
        goto LAB51;

LAB48:    if (t51 != 0)
        goto LAB50;

LAB49:    *((unsigned int *)t38) = 1;

LAB51:    memset(t47, 0, 8);
    t59 = (t38 + 4);
    t56 = *((unsigned int *)t59);
    t57 = (~(t56));
    t58 = *((unsigned int *)t38);
    t62 = (t58 & t57);
    t63 = (t62 & 1U);
    if (t63 != 0)
        goto LAB52;

LAB53:    if (*((unsigned int *)t59) != 0)
        goto LAB54;

LAB55:    t64 = *((unsigned int *)t22);
    t65 = *((unsigned int *)t47);
    t66 = (t64 & t65);
    *((unsigned int *)t55) = t66;
    t61 = (t22 + 4);
    t69 = (t47 + 4);
    t70 = (t55 + 4);
    t67 = *((unsigned int *)t61);
    t68 = *((unsigned int *)t69);
    t71 = (t67 | t68);
    *((unsigned int *)t70) = t71;
    t72 = *((unsigned int *)t70);
    t73 = (t72 != 0);
    if (t73 == 1)
        goto LAB56;

LAB57:
LAB58:    goto LAB47;

LAB50:    t54 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB51;

LAB52:    *((unsigned int *)t47) = 1;
    goto LAB55;

LAB54:    t60 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t60) = 1;
    goto LAB55;

LAB56:    t75 = *((unsigned int *)t55);
    t76 = *((unsigned int *)t70);
    *((unsigned int *)t55) = (t75 | t76);
    t83 = (t22 + 4);
    t89 = (t47 + 4);
    t77 = *((unsigned int *)t22);
    t79 = (~(t77));
    t80 = *((unsigned int *)t83);
    t81 = (~(t80));
    t82 = *((unsigned int *)t47);
    t84 = (~(t82));
    t85 = *((unsigned int *)t89);
    t86 = (~(t85));
    t74 = (t79 & t81);
    t78 = (t84 & t86);
    t87 = (~(t74));
    t88 = (~(t78));
    t91 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t91 & t87);
    t92 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t92 & t88);
    t93 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t93 & t87);
    t94 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t94 & t88);
    goto LAB58;

LAB59:    *((unsigned int *)t95) = 1;
    goto LAB62;

LAB61:    t101 = (t95 + 4);
    *((unsigned int *)t95) = 1;
    *((unsigned int *)t101) = 1;
    goto LAB62;

LAB63:    t107 = (t0 + 3688);
    t108 = (t107 + 56U);
    t109 = *((char **)t108);
    memset(t110, 0, 8);
    t111 = (t110 + 4);
    t112 = (t109 + 4);
    t113 = *((unsigned int *)t109);
    t114 = (t113 >> 15);
    t115 = (t114 & 1);
    *((unsigned int *)t110) = t115;
    t116 = *((unsigned int *)t112);
    t117 = (t116 >> 15);
    t118 = (t117 & 1);
    *((unsigned int *)t111) = t118;
    memset(t119, 0, 8);
    t120 = (t110 + 4);
    t121 = *((unsigned int *)t120);
    t122 = (~(t121));
    t123 = *((unsigned int *)t110);
    t124 = (t123 & t122);
    t125 = (t124 & 1U);
    if (t125 != 0)
        goto LAB66;

LAB67:    if (*((unsigned int *)t120) != 0)
        goto LAB68;

LAB69:    t128 = *((unsigned int *)t95);
    t129 = *((unsigned int *)t119);
    t130 = (t128 | t129);
    *((unsigned int *)t127) = t130;
    t131 = (t95 + 4);
    t132 = (t119 + 4);
    t133 = (t127 + 4);
    t134 = *((unsigned int *)t131);
    t135 = *((unsigned int *)t132);
    t136 = (t134 | t135);
    *((unsigned int *)t133) = t136;
    t137 = *((unsigned int *)t133);
    t138 = (t137 != 0);
    if (t138 == 1)
        goto LAB70;

LAB71:
LAB72:    goto LAB65;

LAB66:    *((unsigned int *)t119) = 1;
    goto LAB69;

LAB68:    t126 = (t119 + 4);
    *((unsigned int *)t119) = 1;
    *((unsigned int *)t126) = 1;
    goto LAB69;

LAB70:    t139 = *((unsigned int *)t127);
    t140 = *((unsigned int *)t133);
    *((unsigned int *)t127) = (t139 | t140);
    t141 = (t95 + 4);
    t142 = (t119 + 4);
    t143 = *((unsigned int *)t141);
    t144 = (~(t143));
    t145 = *((unsigned int *)t95);
    t146 = (t145 & t144);
    t147 = *((unsigned int *)t142);
    t148 = (~(t147));
    t149 = *((unsigned int *)t119);
    t150 = (t149 & t148);
    t151 = (~(t146));
    t152 = (~(t150));
    t153 = *((unsigned int *)t133);
    *((unsigned int *)t133) = (t153 & t151);
    t154 = *((unsigned int *)t133);
    *((unsigned int *)t133) = (t154 & t152);
    goto LAB72;

LAB73:    xsi_set_current_line(52, ng0);
    t161 = ((char*)((ng1)));
    t162 = (t0 + 2408);
    xsi_vlogvar_assign_value(t162, t161, 0, 0, 1);
    goto LAB75;

LAB77:    t27 = (t8 * 8);
    t28 = *((unsigned int *)t21);
    t31 = *((unsigned int *)t30);
    *((unsigned int *)t21) = (t28 | t31);
    t35 = (t4 + t27);
    t32 = (t27 + 4);
    t36 = (t4 + t32);
    t37 = (t5 + t27);
    t33 = (t27 + 4);
    t39 = (t5 + t33);
    t34 = *((unsigned int *)t35);
    t41 = (~(t34));
    t42 = *((unsigned int *)t36);
    t43 = (~(t42));
    t44 = *((unsigned int *)t37);
    t45 = (~(t44));
    t46 = *((unsigned int *)t39);
    t49 = (~(t46));
    t74 = (t41 & t43);
    t78 = (t45 & t49);
    t50 = (~(t74));
    t51 = (~(t78));
    t52 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t52 & t50);
    t53 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t53 & t51);
    t56 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t56 & t50);
    t57 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t57 & t51);

LAB79:    t8 = (t8 + 1);
    goto LAB80;

LAB78:    goto LAB79;

LAB81:    t10 = (t8 * 8);
    t6 = (t4 + t10);
    t7 = (t5 + t10);
    t21 = (t163 + t10);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t14 = (t11 & t12);
    *((unsigned int *)t21) = t14;
    t15 = (t8 * 8);
    t16 = (t15 + 4);
    t23 = (t4 + t16);
    t17 = (t15 + 4);
    t29 = (t5 + t17);
    t18 = (t15 + 4);
    t30 = (t163 + t18);
    t19 = *((unsigned int *)t23);
    t20 = *((unsigned int *)t29);
    t24 = (t19 | t20);
    *((unsigned int *)t30) = t24;
    t25 = *((unsigned int *)t30);
    t26 = (t25 != 0);
    if (t26 == 1)
        goto LAB77;
    else
        goto LAB78;

LAB83:    *((unsigned int *)t13) = 1;
    goto LAB86;

LAB85:    t54 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB86;

LAB87:    t60 = (t0 + 3208);
    t61 = (t60 + 56U);
    t69 = *((char **)t61);
    t70 = ((char*)((ng5)));
    t72 = 0;

LAB93:    t73 = (t72 < 2);
    if (t73 == 1)
        goto LAB94;

LAB95:    t120 = ((char*)((ng5)));
    xsi_vlog_unsigned_equal(t166, 48, t165, 48, t120, 48);
    memset(t22, 0, 8);
    t126 = (t166 + 4);
    t122 = *((unsigned int *)t126);
    t123 = (~(t122));
    t124 = *((unsigned int *)t166);
    t125 = (t124 & t123);
    t128 = (t125 & 1U);
    if (t128 != 0)
        goto LAB96;

LAB97:    if (*((unsigned int *)t126) != 0)
        goto LAB98;

LAB99:    t129 = *((unsigned int *)t13);
    t130 = *((unsigned int *)t22);
    t134 = (t129 | t130);
    *((unsigned int *)t38) = t134;
    t132 = (t13 + 4);
    t133 = (t22 + 4);
    t141 = (t38 + 4);
    t135 = *((unsigned int *)t132);
    t136 = *((unsigned int *)t133);
    t137 = (t135 | t136);
    *((unsigned int *)t141) = t137;
    t138 = *((unsigned int *)t141);
    t139 = (t138 != 0);
    if (t139 == 1)
        goto LAB100;

LAB101:
LAB102:    goto LAB89;

LAB90:    t92 = (t72 * 8);
    t93 = *((unsigned int *)t90);
    t94 = *((unsigned int *)t107);
    *((unsigned int *)t90) = (t93 | t94);
    t108 = (t69 + t92);
    t96 = (t92 + 4);
    t109 = (t69 + t96);
    t111 = (t70 + t92);
    t97 = (t92 + 4);
    t112 = (t70 + t97);
    t98 = *((unsigned int *)t108);
    t99 = (~(t98));
    t100 = *((unsigned int *)t109);
    t103 = (~(t100));
    t104 = *((unsigned int *)t111);
    t105 = (~(t104));
    t106 = *((unsigned int *)t112);
    t113 = (~(t106));
    t146 = (t99 & t103);
    t150 = (t105 & t113);
    t114 = (~(t146));
    t115 = (~(t150));
    t116 = *((unsigned int *)t107);
    *((unsigned int *)t107) = (t116 & t114);
    t117 = *((unsigned int *)t107);
    *((unsigned int *)t107) = (t117 & t115);
    t118 = *((unsigned int *)t90);
    *((unsigned int *)t90) = (t118 & t114);
    t121 = *((unsigned int *)t90);
    *((unsigned int *)t90) = (t121 & t115);

LAB92:    t72 = (t72 + 1);
    goto LAB93;

LAB91:    goto LAB92;

LAB94:    t75 = (t72 * 8);
    t83 = (t69 + t75);
    t89 = (t70 + t75);
    t90 = (t165 + t75);
    t76 = *((unsigned int *)t83);
    t77 = *((unsigned int *)t89);
    t79 = (t76 & t77);
    *((unsigned int *)t90) = t79;
    t80 = (t72 * 8);
    t81 = (t80 + 4);
    t101 = (t69 + t81);
    t82 = (t80 + 4);
    t102 = (t70 + t82);
    t84 = (t80 + 4);
    t107 = (t165 + t84);
    t85 = *((unsigned int *)t101);
    t86 = *((unsigned int *)t102);
    t87 = (t85 | t86);
    *((unsigned int *)t107) = t87;
    t88 = *((unsigned int *)t107);
    t91 = (t88 != 0);
    if (t91 == 1)
        goto LAB90;
    else
        goto LAB91;

LAB96:    *((unsigned int *)t22) = 1;
    goto LAB99;

LAB98:    t131 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t131) = 1;
    goto LAB99;

LAB100:    t140 = *((unsigned int *)t38);
    t143 = *((unsigned int *)t141);
    *((unsigned int *)t38) = (t140 | t143);
    t142 = (t13 + 4);
    t155 = (t22 + 4);
    t144 = *((unsigned int *)t142);
    t145 = (~(t144));
    t147 = *((unsigned int *)t13);
    t167 = (t147 & t145);
    t148 = *((unsigned int *)t155);
    t149 = (~(t148));
    t151 = *((unsigned int *)t22);
    t168 = (t151 & t149);
    t152 = (~(t167));
    t153 = (~(t168));
    t154 = *((unsigned int *)t141);
    *((unsigned int *)t141) = (t154 & t152);
    t156 = *((unsigned int *)t141);
    *((unsigned int *)t141) = (t156 & t153);
    goto LAB102;

LAB103:    xsi_set_current_line(59, ng0);
    t162 = ((char*)((ng1)));
    t170 = (t0 + 4008);
    xsi_vlogvar_assign_value(t170, t162, 0, 0, 1);
    goto LAB105;

}


extern void work_m_00000000001371968056_2058569214_init()
{
	static char *pe[] = {(void *)Cont_15_0,(void *)Always_18_1,(void *)Always_34_2};
	xsi_register_didat("work_m_00000000001371968056_2058569214", "isim/pow_isim_beh.exe.sim/work/m_00000000001371968056_2058569214.didat");
	xsi_register_executes(pe);
}
