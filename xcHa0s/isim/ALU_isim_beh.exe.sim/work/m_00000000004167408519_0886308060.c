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
static const char *ng0 = "E:/faculta/FIC/0xcHa0s/xcHa0s/ALU.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static int ng3[] = {24, 0};
static int ng4[] = {3, 0};
static int ng5[] = {2, 0};



static void Cont_23_0(char *t0)
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
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 3808U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 2888);
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
    *((unsigned int *)t3) = (t12 & 65535U);
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 65535U);
    t14 = (t0 + 4472);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 65535U;
    t20 = t19;
    t21 = (t3 + 4);
    t22 = *((unsigned int *)t3);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 15);
    t27 = (t0 + 4376);
    *((int *)t27) = 1;

LAB1:    return;
}

static void Always_25_1(char *t0)
{
    char t6[8];
    char t12[8];
    char t18[8];
    char t21[8];
    char t29[8];
    char t85[8];
    char t117[8];
    char t120[8];
    char t145[8];
    char t148[8];
    char t173[8];
    char t208[8];
    char t217[8];
    char t249[8];
    char t278[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    int t11;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t19;
    char *t20;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t90;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    char *t99;
    char *t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    int t109;
    int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t118;
    char *t119;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    char *t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    char *t134;
    char *t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    char *t146;
    char *t147;
    char *t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    unsigned int t155;
    char *t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    char *t162;
    char *t163;
    char *t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    char *t177;
    char *t178;
    char *t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    char *t187;
    char *t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    int t197;
    int t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    char *t205;
    char *t206;
    char *t207;
    char *t209;
    char *t210;
    unsigned int t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t218;
    unsigned int t219;
    unsigned int t220;
    char *t221;
    char *t222;
    char *t223;
    unsigned int t224;
    unsigned int t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    unsigned int t229;
    unsigned int t230;
    char *t231;
    char *t232;
    unsigned int t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    unsigned int t237;
    unsigned int t238;
    unsigned int t239;
    unsigned int t240;
    int t241;
    int t242;
    unsigned int t243;
    unsigned int t244;
    unsigned int t245;
    unsigned int t246;
    unsigned int t247;
    unsigned int t248;
    unsigned int t250;
    unsigned int t251;
    unsigned int t252;
    char *t253;
    char *t254;
    char *t255;
    unsigned int t256;
    unsigned int t257;
    unsigned int t258;
    unsigned int t259;
    unsigned int t260;
    unsigned int t261;
    unsigned int t262;
    char *t263;
    char *t264;
    unsigned int t265;
    unsigned int t266;
    unsigned int t267;
    int t268;
    unsigned int t269;
    unsigned int t270;
    unsigned int t271;
    int t272;
    unsigned int t273;
    unsigned int t274;
    unsigned int t275;
    unsigned int t276;
    char *t277;
    char *t279;
    char *t280;
    char *t281;
    char *t282;
    char *t283;
    unsigned int t284;
    int t285;

LAB0:    t1 = (t0 + 4056U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(25, ng0);
    t2 = (t0 + 4392);
    *((int *)t2) = 1;
    t3 = (t0 + 4088);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(25, ng0);

LAB5:    xsi_set_current_line(26, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 2888);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 17);
    xsi_set_current_line(27, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(28, ng0);
    t2 = (t0 + 2008U);
    t3 = *((char **)t2);
    t2 = (t0 + 2728);
    t4 = (t0 + 2728);
    t5 = (t4 + 72U);
    t7 = *((char **)t5);
    t8 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t6, t7, 2, t8, 32, 1);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (!(t10));
    if (t11 == 1)
        goto LAB6;

LAB7:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    t2 = (t0 + 2728);
    t4 = (t0 + 2728);
    t5 = (t4 + 72U);
    t7 = *((char **)t5);
    t8 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t6, t7, 2, t8, 32, 1);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t9);
    t11 = (!(t10));
    if (t11 == 1)
        goto LAB8;

LAB9:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);

LAB10:    t2 = ((char*)((ng2)));
    t11 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 32);
    if (t11 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng3)));
    t11 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 32);
    if (t11 == 1)
        goto LAB13;

LAB14:
LAB15:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 2888);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t7 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t8 = (t5 + 4);
    t9 = (t7 + 4);
    t10 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t7);
    t14 = (t10 ^ t13);
    t15 = *((unsigned int *)t8);
    t16 = *((unsigned int *)t9);
    t17 = (t15 ^ t16);
    t23 = (t14 | t17);
    t24 = *((unsigned int *)t8);
    t25 = *((unsigned int *)t9);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t28 = (t23 & t27);
    if (t28 != 0)
        goto LAB56;

LAB53:    if (t26 != 0)
        goto LAB55;

LAB54:    *((unsigned int *)t6) = 1;

LAB56:    t20 = (t0 + 2728);
    t22 = (t0 + 2728);
    t30 = (t22 + 72U);
    t41 = *((char **)t30);
    t57 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t12, t41, 2, t57, 32, 1);
    t58 = (t12 + 4);
    t31 = *((unsigned int *)t58);
    t11 = (!(t31));
    if (t11 == 1)
        goto LAB57;

LAB58:    xsi_set_current_line(106, ng0);
    t2 = (t0 + 2888);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t7 = (t6 + 4);
    t8 = (t5 + 4);
    t10 = *((unsigned int *)t5);
    t13 = (t10 >> 15);
    t14 = (t13 & 1);
    *((unsigned int *)t6) = t14;
    t15 = *((unsigned int *)t8);
    t16 = (t15 >> 15);
    t17 = (t16 & 1);
    *((unsigned int *)t7) = t17;
    t9 = (t0 + 2728);
    t19 = (t0 + 2728);
    t20 = (t19 + 72U);
    t22 = *((char **)t20);
    t30 = ((char*)((ng5)));
    xsi_vlog_generic_convert_bit_index(t12, t22, 2, t30, 32, 1);
    t41 = (t12 + 4);
    t23 = *((unsigned int *)t41);
    t11 = (!(t23));
    if (t11 == 1)
        goto LAB59;

LAB60:    goto LAB2;

LAB6:    xsi_vlogvar_assign_value(t2, t3, 0, *((unsigned int *)t6), 1);
    goto LAB7;

LAB8:    xsi_vlogvar_assign_value(t2, t3, 0, *((unsigned int *)t6), 1);
    goto LAB9;

LAB11:    xsi_set_current_line(33, ng0);

LAB16:    xsi_set_current_line(34, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = (t0 + 1368U);
    t7 = *((char **)t4);
    memset(t12, 0, 8);
    t4 = (t12 + 4);
    t8 = (t7 + 4);
    t10 = *((unsigned int *)t7);
    t13 = (t10 >> 15);
    t14 = (t13 & 1);
    *((unsigned int *)t12) = t14;
    t15 = *((unsigned int *)t8);
    t16 = (t15 >> 15);
    t17 = (t16 & 1);
    *((unsigned int *)t4) = t17;
    xsi_vlogtype_concat(t6, 17, 17, 2U, t12, 1, t5, 16);
    t9 = (t0 + 1528U);
    t19 = *((char **)t9);
    t9 = (t0 + 1528U);
    t20 = *((char **)t9);
    memset(t21, 0, 8);
    t9 = (t21 + 4);
    t22 = (t20 + 4);
    t23 = *((unsigned int *)t20);
    t24 = (t23 >> 15);
    t25 = (t24 & 1);
    *((unsigned int *)t21) = t25;
    t26 = *((unsigned int *)t22);
    t27 = (t26 >> 15);
    t28 = (t27 & 1);
    *((unsigned int *)t9) = t28;
    xsi_vlogtype_concat(t18, 17, 17, 2U, t21, 1, t19, 16);
    memset(t29, 0, 8);
    xsi_vlog_unsigned_add(t29, 17, t6, 17, t18, 17);
    t30 = (t0 + 2888);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 17);
    xsi_set_current_line(36, ng0);
    t2 = (t0 + 1368U);
    t4 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t5 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t13 = (t10 >> 15);
    t14 = (t13 & 1);
    *((unsigned int *)t6) = t14;
    t15 = *((unsigned int *)t5);
    t16 = (t15 >> 15);
    t17 = (t16 & 1);
    *((unsigned int *)t2) = t17;
    t7 = (t0 + 1528U);
    t8 = *((char **)t7);
    memset(t12, 0, 8);
    t7 = (t12 + 4);
    t9 = (t8 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (t23 >> 15);
    t25 = (t24 & 1);
    *((unsigned int *)t12) = t25;
    t26 = *((unsigned int *)t9);
    t27 = (t26 >> 15);
    t28 = (t27 & 1);
    *((unsigned int *)t7) = t28;
    t31 = *((unsigned int *)t6);
    t32 = *((unsigned int *)t12);
    t33 = (t31 & t32);
    *((unsigned int *)t18) = t33;
    t19 = (t6 + 4);
    t20 = (t12 + 4);
    t22 = (t18 + 4);
    t34 = *((unsigned int *)t19);
    t35 = *((unsigned int *)t20);
    t36 = (t34 | t35);
    *((unsigned int *)t22) = t36;
    t37 = *((unsigned int *)t22);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB17;

LAB18:
LAB19:    t57 = (t0 + 2888);
    t58 = (t57 + 56U);
    t59 = *((char **)t58);
    memset(t29, 0, 8);
    t60 = (t29 + 4);
    t61 = (t59 + 4);
    t62 = *((unsigned int *)t59);
    t63 = (t62 >> 15);
    t64 = (t63 & 1);
    *((unsigned int *)t29) = t64;
    t65 = *((unsigned int *)t61);
    t66 = (t65 >> 15);
    t67 = (t66 & 1);
    *((unsigned int *)t60) = t67;
    memset(t21, 0, 8);
    t68 = (t29 + 4);
    t69 = *((unsigned int *)t68);
    t70 = (~(t69));
    t71 = *((unsigned int *)t29);
    t72 = (t71 & t70);
    t73 = (t72 & 1U);
    if (t73 != 0)
        goto LAB23;

LAB21:    if (*((unsigned int *)t68) == 0)
        goto LAB20;

LAB22:    t74 = (t21 + 4);
    *((unsigned int *)t21) = 1;
    *((unsigned int *)t74) = 1;

LAB23:    t75 = (t21 + 4);
    t76 = (t29 + 4);
    t77 = *((unsigned int *)t29);
    t78 = (~(t77));
    *((unsigned int *)t21) = t78;
    *((unsigned int *)t75) = 0;
    if (*((unsigned int *)t76) != 0)
        goto LAB25;

LAB24:    t83 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t83 & 1U);
    t84 = *((unsigned int *)t75);
    *((unsigned int *)t75) = (t84 & 1U);
    t86 = *((unsigned int *)t18);
    t87 = *((unsigned int *)t21);
    t88 = (t86 & t87);
    *((unsigned int *)t85) = t88;
    t89 = (t18 + 4);
    t90 = (t21 + 4);
    t91 = (t85 + 4);
    t92 = *((unsigned int *)t89);
    t93 = *((unsigned int *)t90);
    t94 = (t92 | t93);
    *((unsigned int *)t91) = t94;
    t95 = *((unsigned int *)t91);
    t96 = (t95 != 0);
    if (t96 == 1)
        goto LAB26;

LAB27:
LAB28:    t118 = (t0 + 1368U);
    t119 = *((char **)t118);
    memset(t120, 0, 8);
    t118 = (t120 + 4);
    t121 = (t119 + 4);
    t122 = *((unsigned int *)t119);
    t123 = (t122 >> 15);
    t124 = (t123 & 1);
    *((unsigned int *)t120) = t124;
    t125 = *((unsigned int *)t121);
    t126 = (t125 >> 15);
    t127 = (t126 & 1);
    *((unsigned int *)t118) = t127;
    memset(t117, 0, 8);
    t128 = (t120 + 4);
    t129 = *((unsigned int *)t128);
    t130 = (~(t129));
    t131 = *((unsigned int *)t120);
    t132 = (t131 & t130);
    t133 = (t132 & 1U);
    if (t133 != 0)
        goto LAB32;

LAB30:    if (*((unsigned int *)t128) == 0)
        goto LAB29;

LAB31:    t134 = (t117 + 4);
    *((unsigned int *)t117) = 1;
    *((unsigned int *)t134) = 1;

LAB32:    t135 = (t117 + 4);
    t136 = (t120 + 4);
    t137 = *((unsigned int *)t120);
    t138 = (~(t137));
    *((unsigned int *)t117) = t138;
    *((unsigned int *)t135) = 0;
    if (*((unsigned int *)t136) != 0)
        goto LAB34;

LAB33:    t143 = *((unsigned int *)t117);
    *((unsigned int *)t117) = (t143 & 1U);
    t144 = *((unsigned int *)t135);
    *((unsigned int *)t135) = (t144 & 1U);
    t146 = (t0 + 1528U);
    t147 = *((char **)t146);
    memset(t148, 0, 8);
    t146 = (t148 + 4);
    t149 = (t147 + 4);
    t150 = *((unsigned int *)t147);
    t151 = (t150 >> 15);
    t152 = (t151 & 1);
    *((unsigned int *)t148) = t152;
    t153 = *((unsigned int *)t149);
    t154 = (t153 >> 15);
    t155 = (t154 & 1);
    *((unsigned int *)t146) = t155;
    memset(t145, 0, 8);
    t156 = (t148 + 4);
    t157 = *((unsigned int *)t156);
    t158 = (~(t157));
    t159 = *((unsigned int *)t148);
    t160 = (t159 & t158);
    t161 = (t160 & 1U);
    if (t161 != 0)
        goto LAB38;

LAB36:    if (*((unsigned int *)t156) == 0)
        goto LAB35;

LAB37:    t162 = (t145 + 4);
    *((unsigned int *)t145) = 1;
    *((unsigned int *)t162) = 1;

LAB38:    t163 = (t145 + 4);
    t164 = (t148 + 4);
    t165 = *((unsigned int *)t148);
    t166 = (~(t165));
    *((unsigned int *)t145) = t166;
    *((unsigned int *)t163) = 0;
    if (*((unsigned int *)t164) != 0)
        goto LAB40;

LAB39:    t171 = *((unsigned int *)t145);
    *((unsigned int *)t145) = (t171 & 1U);
    t172 = *((unsigned int *)t163);
    *((unsigned int *)t163) = (t172 & 1U);
    t174 = *((unsigned int *)t117);
    t175 = *((unsigned int *)t145);
    t176 = (t174 & t175);
    *((unsigned int *)t173) = t176;
    t177 = (t117 + 4);
    t178 = (t145 + 4);
    t179 = (t173 + 4);
    t180 = *((unsigned int *)t177);
    t181 = *((unsigned int *)t178);
    t182 = (t180 | t181);
    *((unsigned int *)t179) = t182;
    t183 = *((unsigned int *)t179);
    t184 = (t183 != 0);
    if (t184 == 1)
        goto LAB41;

LAB42:
LAB43:    t205 = (t0 + 2888);
    t206 = (t205 + 56U);
    t207 = *((char **)t206);
    memset(t208, 0, 8);
    t209 = (t208 + 4);
    t210 = (t207 + 4);
    t211 = *((unsigned int *)t207);
    t212 = (t211 >> 15);
    t213 = (t212 & 1);
    *((unsigned int *)t208) = t213;
    t214 = *((unsigned int *)t210);
    t215 = (t214 >> 15);
    t216 = (t215 & 1);
    *((unsigned int *)t209) = t216;
    t218 = *((unsigned int *)t173);
    t219 = *((unsigned int *)t208);
    t220 = (t218 & t219);
    *((unsigned int *)t217) = t220;
    t221 = (t173 + 4);
    t222 = (t208 + 4);
    t223 = (t217 + 4);
    t224 = *((unsigned int *)t221);
    t225 = *((unsigned int *)t222);
    t226 = (t224 | t225);
    *((unsigned int *)t223) = t226;
    t227 = *((unsigned int *)t223);
    t228 = (t227 != 0);
    if (t228 == 1)
        goto LAB44;

LAB45:
LAB46:    t250 = *((unsigned int *)t85);
    t251 = *((unsigned int *)t217);
    t252 = (t250 | t251);
    *((unsigned int *)t249) = t252;
    t253 = (t85 + 4);
    t254 = (t217 + 4);
    t255 = (t249 + 4);
    t256 = *((unsigned int *)t253);
    t257 = *((unsigned int *)t254);
    t258 = (t256 | t257);
    *((unsigned int *)t255) = t258;
    t259 = *((unsigned int *)t255);
    t260 = (t259 != 0);
    if (t260 == 1)
        goto LAB47;

LAB48:
LAB49:    t277 = (t0 + 2728);
    t279 = (t0 + 2728);
    t280 = (t279 + 72U);
    t281 = *((char **)t280);
    t282 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t278, t281, 2, t282, 32, 1);
    t283 = (t278 + 4);
    t284 = *((unsigned int *)t283);
    t285 = (!(t284));
    if (t285 == 1)
        goto LAB50;

LAB51:    goto LAB15;

LAB13:    xsi_set_current_line(93, ng0);

LAB52:    xsi_set_current_line(94, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = (t0 + 1528U);
    t7 = *((char **)t4);
    memset(t6, 0, 8);
    xsi_vlog_unsigned_rshift(t6, 17, t5, 16, t7, 16);
    t4 = (t0 + 2888);
    xsi_vlogvar_assign_value(t4, t6, 0, 0, 17);
    goto LAB15;

LAB17:    t39 = *((unsigned int *)t18);
    t40 = *((unsigned int *)t22);
    *((unsigned int *)t18) = (t39 | t40);
    t30 = (t6 + 4);
    t41 = (t12 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t30);
    t45 = (~(t44));
    t46 = *((unsigned int *)t12);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t11 = (t43 & t45);
    t50 = (t47 & t49);
    t51 = (~(t11));
    t52 = (~(t50));
    t53 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t53 & t51);
    t54 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t54 & t52);
    t55 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t55 & t51);
    t56 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t56 & t52);
    goto LAB19;

LAB20:    *((unsigned int *)t21) = 1;
    goto LAB23;

LAB25:    t79 = *((unsigned int *)t21);
    t80 = *((unsigned int *)t76);
    *((unsigned int *)t21) = (t79 | t80);
    t81 = *((unsigned int *)t75);
    t82 = *((unsigned int *)t76);
    *((unsigned int *)t75) = (t81 | t82);
    goto LAB24;

LAB26:    t97 = *((unsigned int *)t85);
    t98 = *((unsigned int *)t91);
    *((unsigned int *)t85) = (t97 | t98);
    t99 = (t18 + 4);
    t100 = (t21 + 4);
    t101 = *((unsigned int *)t18);
    t102 = (~(t101));
    t103 = *((unsigned int *)t99);
    t104 = (~(t103));
    t105 = *((unsigned int *)t21);
    t106 = (~(t105));
    t107 = *((unsigned int *)t100);
    t108 = (~(t107));
    t109 = (t102 & t104);
    t110 = (t106 & t108);
    t111 = (~(t109));
    t112 = (~(t110));
    t113 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t113 & t111);
    t114 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t114 & t112);
    t115 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t115 & t111);
    t116 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t116 & t112);
    goto LAB28;

LAB29:    *((unsigned int *)t117) = 1;
    goto LAB32;

LAB34:    t139 = *((unsigned int *)t117);
    t140 = *((unsigned int *)t136);
    *((unsigned int *)t117) = (t139 | t140);
    t141 = *((unsigned int *)t135);
    t142 = *((unsigned int *)t136);
    *((unsigned int *)t135) = (t141 | t142);
    goto LAB33;

LAB35:    *((unsigned int *)t145) = 1;
    goto LAB38;

LAB40:    t167 = *((unsigned int *)t145);
    t168 = *((unsigned int *)t164);
    *((unsigned int *)t145) = (t167 | t168);
    t169 = *((unsigned int *)t163);
    t170 = *((unsigned int *)t164);
    *((unsigned int *)t163) = (t169 | t170);
    goto LAB39;

LAB41:    t185 = *((unsigned int *)t173);
    t186 = *((unsigned int *)t179);
    *((unsigned int *)t173) = (t185 | t186);
    t187 = (t117 + 4);
    t188 = (t145 + 4);
    t189 = *((unsigned int *)t117);
    t190 = (~(t189));
    t191 = *((unsigned int *)t187);
    t192 = (~(t191));
    t193 = *((unsigned int *)t145);
    t194 = (~(t193));
    t195 = *((unsigned int *)t188);
    t196 = (~(t195));
    t197 = (t190 & t192);
    t198 = (t194 & t196);
    t199 = (~(t197));
    t200 = (~(t198));
    t201 = *((unsigned int *)t179);
    *((unsigned int *)t179) = (t201 & t199);
    t202 = *((unsigned int *)t179);
    *((unsigned int *)t179) = (t202 & t200);
    t203 = *((unsigned int *)t173);
    *((unsigned int *)t173) = (t203 & t199);
    t204 = *((unsigned int *)t173);
    *((unsigned int *)t173) = (t204 & t200);
    goto LAB43;

LAB44:    t229 = *((unsigned int *)t217);
    t230 = *((unsigned int *)t223);
    *((unsigned int *)t217) = (t229 | t230);
    t231 = (t173 + 4);
    t232 = (t208 + 4);
    t233 = *((unsigned int *)t173);
    t234 = (~(t233));
    t235 = *((unsigned int *)t231);
    t236 = (~(t235));
    t237 = *((unsigned int *)t208);
    t238 = (~(t237));
    t239 = *((unsigned int *)t232);
    t240 = (~(t239));
    t241 = (t234 & t236);
    t242 = (t238 & t240);
    t243 = (~(t241));
    t244 = (~(t242));
    t245 = *((unsigned int *)t223);
    *((unsigned int *)t223) = (t245 & t243);
    t246 = *((unsigned int *)t223);
    *((unsigned int *)t223) = (t246 & t244);
    t247 = *((unsigned int *)t217);
    *((unsigned int *)t217) = (t247 & t243);
    t248 = *((unsigned int *)t217);
    *((unsigned int *)t217) = (t248 & t244);
    goto LAB46;

LAB47:    t261 = *((unsigned int *)t249);
    t262 = *((unsigned int *)t255);
    *((unsigned int *)t249) = (t261 | t262);
    t263 = (t85 + 4);
    t264 = (t217 + 4);
    t265 = *((unsigned int *)t263);
    t266 = (~(t265));
    t267 = *((unsigned int *)t85);
    t268 = (t267 & t266);
    t269 = *((unsigned int *)t264);
    t270 = (~(t269));
    t271 = *((unsigned int *)t217);
    t272 = (t271 & t270);
    t273 = (~(t268));
    t274 = (~(t272));
    t275 = *((unsigned int *)t255);
    *((unsigned int *)t255) = (t275 & t273);
    t276 = *((unsigned int *)t255);
    *((unsigned int *)t255) = (t276 & t274);
    goto LAB49;

LAB50:    xsi_vlogvar_assign_value(t277, t249, 0, *((unsigned int *)t278), 1);
    goto LAB51;

LAB55:    t19 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB56;

LAB57:    xsi_vlogvar_assign_value(t20, t6, 0, *((unsigned int *)t12), 1);
    goto LAB58;

LAB59:    xsi_vlogvar_assign_value(t9, t6, 0, *((unsigned int *)t12), 1);
    goto LAB60;

}


extern void work_m_00000000004167408519_0886308060_init()
{
	static char *pe[] = {(void *)Cont_23_0,(void *)Always_25_1};
	xsi_register_didat("work_m_00000000004167408519_0886308060", "isim/ALU_isim_beh.exe.sim/work/m_00000000004167408519_0886308060.didat");
	xsi_register_executes(pe);
}
