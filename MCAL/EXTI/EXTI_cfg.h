#ifndef EXTI_CFG_H
#define EXTI_CFG_H
   

   #define ENABLE        1u
   #define DISABLE       0u
   /*chose the one of the fourth trigger types 1-EXTI_FallingEdge
                                               2-EXTI_RisingEdge
											   3-EXTI_OnChange
											   4-EXTI_LowLevel
   */
#define EXTI_INT0_TRIG    EXTI_FallingEdge
#define EXTI_INT1_TRIG    EXTI_FallingEdge


/*chose the one of the  trigger types 1-EXTI_FallingEdge
                                      2-EXTI_RisingEdge

   */
#define EXTI_INT2_TRIG    EXTI_FallingEdge

/**/
#define EXTI_INT0_INIT_STATE      ENABLE 
#define EXTI_INT1_INIT_STATE      ENABLE
#define EXTI_INT2_INIT_STATE      ENABLE





#endif
