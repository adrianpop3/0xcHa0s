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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000000916232398_0967961054_init();
    work_m_00000000002642417493_0236324256_init();
    work_m_00000000001308470031_4112152428_init();
    work_m_00000000002642417493_3913188552_init();
    work_m_00000000002642417493_3811023632_init();
    work_m_00000000002351842954_0886308060_init();
    work_m_00000000002642417493_3149429741_init();
    work_m_00000000004026001717_1200043877_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000004026001717_1200043877");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
