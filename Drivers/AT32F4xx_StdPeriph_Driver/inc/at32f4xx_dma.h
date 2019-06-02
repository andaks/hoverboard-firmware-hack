/**
 **************************************************************************
 * File Name    : at32f4xx_dma.h
 * Description  : at32f4xx DMA header file
 * Date         : 2018-02-26
 * Version      : V1.0.4
 **************************************************************************
 */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __AT32F4xx_DMA_H
#define __AT32F4xx_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "at32f4xx.h"

/** @addtogroup at32f4xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup DMA
  * @{
  */

/** @defgroup DMA_Exported_Types
  * @{
  */

/**
  * @brief  DMA Init structure definition
  */

typedef struct
{
    uint32_t DMA_PeripheralBaseAddr;        /*!< Specifies the peripheral base address for DMAy Channelx. */
                                            
    uint32_t DMA_MemoryBaseAddr;            /*!< Specifies the memory base address for DMAy Channelx. */
                                            
    uint32_t DMA_Direction;                 /*!< Specifies if the peripheral is the source or destination.
                                               This parameter can be a value of @ref DMA_data_transfer_direction */
                                            
    uint32_t DMA_BufferSize;                /*!< Specifies the buffer size, in data unit, of the specified Channel.
                                               The data unit is equal to the configuration set in DMA_PeripheralDataWidth
                                               or DMA_MemoryDataWidth members depending in the transfer direction. */
                                            
    uint32_t DMA_PeripheralInc;             /*!< Specifies whether the Peripheral address register is incremented or not.
                                               This parameter can be a value of @ref DMA_peripheral_incremented_mode */
                                            
    uint32_t DMA_MemoryInc;                 /*!< Specifies whether the memory address register is incremented or not.
                                               This parameter can be a value of @ref DMA_memory_incremented_mode */
                                            
    uint32_t DMA_PeripheralDataWidth;       /*!< Specifies the Peripheral data width.
                                               This parameter can be a value of @ref DMA_peripheral_data_size */
                                            
    uint32_t DMA_MemoryDataWidth;           /*!< Specifies the Memory data width.
                                               This parameter can be a value of @ref DMA_memory_data_size */
                                            
    uint32_t DMA_Mode;                      /*!< Specifies the operation mode of the DMAy Channelx.
                                               This parameter can be a value of @ref DMA_circular_normal_mode.
                                               @note: The circular buffer mode cannot be used if the memory-to-memory
                                                     data transfer is configured on the selected Channel */
                                            
    uint32_t DMA_Priority;                  /*!< Specifies the software priority for the DMAy Channelx.
                                               This parameter can be a value of @ref DMA_priority_level */
                                            
    uint32_t DMA_MTOM;                      /*!< Specifies if the DMAy Channelx will be used in memory-to-memory transfer.
                                               This parameter can be a value of @ref DMA_memory_to_memory */
} DMA_InitType;

/**
  * @}
  */

/** @defgroup DMA_Exported_Constants
  * @{
  */

#define IS_DMA_ALL_PERIPH(PERIPH)           (((PERIPH) == DMA1_Channel1) || \
                                             ((PERIPH) == DMA1_Channel2) || \
                                             ((PERIPH) == DMA1_Channel3) || \
                                             ((PERIPH) == DMA1_Channel4) || \
                                             ((PERIPH) == DMA1_Channel5) || \
                                             ((PERIPH) == DMA1_Channel6) || \
                                             ((PERIPH) == DMA1_Channel7) || \
                                             ((PERIPH) == DMA2_Channel1) || \
                                             ((PERIPH) == DMA2_Channel2) || \
                                             ((PERIPH) == DMA2_Channel3) || \
                                             ((PERIPH) == DMA2_Channel4) || \
                                             ((PERIPH) == DMA2_Channel5))

/** @defgroup DMA_data_transfer_direction
  * @{
  */

#define DMA_DIR_PERIPHERALDST               ((uint32_t)0x00000010)
#define DMA_DIR_PERIPHERALSRC               ((uint32_t)0x00000000)
#define IS_DMA_DIR(DIR)                     (((DIR) == DMA_DIR_PERIPHERALDST) || \
                                             ((DIR) == DMA_DIR_PERIPHERALSRC))
/**
  * @}
  */

/** @defgroup DMA_peripheral_incremented_mode
  * @{
  */

#define DMA_PERIPHERALINC_ENABLE            ((uint32_t)0x00000040)
#define DMA_PERIPHERALINC_DISABLE           ((uint32_t)0x00000000)
#define IS_DMA_PERIPHERAL_INC_STATE(STATE)  (((STATE) == DMA_PERIPHERALINC_ENABLE) || \
                                             ((STATE) == DMA_PERIPHERALINC_DISABLE))
/**
  * @}
  */

/** @defgroup DMA_memory_incremented_mode
  * @{
  */

#define DMA_MEMORYINC_ENABLE                ((uint32_t)0x00000080)
#define DMA_MEMORYINC_DISABLE               ((uint32_t)0x00000000)
#define IS_DMA_MEMORY_INC_STATE(STATE)      (((STATE) == DMA_MEMORYINC_ENABLE) || \
                                             ((STATE) == DMA_MEMORYINC_DISABLE))
/**
  * @}
  */

/** @defgroup DMA_peripheral_data_size
  * @{
  */

#define DMA_PERIPHERALDATAWIDTH_BYTE        ((uint32_t)0x00000000)
#define DMA_PERIPHERALDATAWIDTH_HALFWORD    ((uint32_t)0x00000100)
#define DMA_PERIPHERALDATAWIDTH_WORD        ((uint32_t)0x00000200)
#define IS_DMA_PERIPHERAL_DATA_WIDTH(WIDTH) (((WIDTH) == DMA_PERIPHERALDATAWIDTH_BYTE) || \
                                             ((WIDTH) == DMA_PERIPHERALDATAWIDTH_HALFWORD) || \
                                             ((WIDTH) == DMA_PERIPHERALDATAWIDTH_WORD))
/**
  * @}
  */

/** @defgroup DMA_memory_data_size
  * @{
  */

#define DMA_MEMORYDATAWIDTH_BYTE            ((uint32_t)0x00000000)
#define DMA_MEMORYDATAWIDTH_HALFWORD        ((uint32_t)0x00000400)
#define DMA_MEMORYDATAWIDTH_WORD            ((uint32_t)0x00000800)
#define IS_DMA_MEMORY_DATA_WIDTH(WIDTH)     (((WIDTH) == DMA_MEMORYDATAWIDTH_BYTE) || \
                                             ((WIDTH) == DMA_MEMORYDATAWIDTH_HALFWORD) || \
                                             ((WIDTH) == DMA_MEMORYDATAWIDTH_WORD))
/**
  * @}
  */

/** @defgroup DMA_circular_normal_mode
  * @{
  */

#define DMA_MODE_CIRCULAR                   ((uint32_t)0x00000020)
#define DMA_MODE_NORMAL                     ((uint32_t)0x00000000)
#define IS_DMA_MODE(MODE)                   (((MODE) == DMA_MODE_CIRCULAR) || ((MODE) == DMA_MODE_NORMAL))
/**
  * @}
  */

/** @defgroup DMA_priority_level
  * @{
  */

#define DMA_PRIORITY_VERYHIGH               ((uint32_t)0x00003000)
#define DMA_PRIORITY_HIGH                   ((uint32_t)0x00002000)
#define DMA_PRIORITY_MEDIUM                 ((uint32_t)0x00001000)
#define DMA_PRIORITY_LOW                    ((uint32_t)0x00000000)
#define IS_DMA_PRIORITY(PRIORITY)           (((PRIORITY) == DMA_PRIORITY_VERYHIGH) || \
                                             ((PRIORITY) == DMA_PRIORITY_HIGH) || \
                                             ((PRIORITY) == DMA_PRIORITY_MEDIUM) || \
                                             ((PRIORITY) == DMA_PRIORITY_LOW))
/**
  * @}
  */

/** @defgroup DMA_memory_to_memory
  * @{
  */

#define DMA_MEMTOMEM_ENABLE                 ((uint32_t)0x00004000)
#define DMA_MEMTOMEM_DISABLE                ((uint32_t)0x00000000)
#define IS_DMA_MTOM_STATE(STATE)            (((STATE) == DMA_MEMTOMEM_ENABLE) || ((STATE) == DMA_MEMTOMEM_DISABLE))

/**
  * @}
  */

/** @defgroup DMA_interrupts_definition
  * @{
  */

#define DMA_INT_TC                          ((uint32_t)0x00000002)
#define DMA_INT_HT                          ((uint32_t)0x00000004)
#define DMA_INT_ERR                         ((uint32_t)0x00000008)
#define IS_DMA_CONFIG_INT(INT)              ((((INT) & 0xFFFFFFF1) == 0x00) && ((INT) != 0x00))

#define DMA1_INT_GL1                        ((uint32_t)0x00000001)
#define DMA1_INT_TC1                        ((uint32_t)0x00000002)
#define DMA1_INT_HT1                        ((uint32_t)0x00000004)
#define DMA1_INT_ERR1                       ((uint32_t)0x00000008)
#define DMA1_INT_GL2                        ((uint32_t)0x00000010)
#define DMA1_INT_TC2                        ((uint32_t)0x00000020)
#define DMA1_INT_HT2                        ((uint32_t)0x00000040)
#define DMA1_INT_ERR2                       ((uint32_t)0x00000080)
#define DMA1_INT_GL3                        ((uint32_t)0x00000100)
#define DMA1_INT_TC3                        ((uint32_t)0x00000200)
#define DMA1_INT_HT3                        ((uint32_t)0x00000400)
#define DMA1_INT_ERR3                       ((uint32_t)0x00000800)
#define DMA1_INT_GL4                        ((uint32_t)0x00001000)
#define DMA1_INT_TC4                        ((uint32_t)0x00002000)
#define DMA1_INT_HT4                        ((uint32_t)0x00004000)
#define DMA1_INT_ERR4                       ((uint32_t)0x00008000)
#define DMA1_INT_GL5                        ((uint32_t)0x00010000)
#define DMA1_INT_TC5                        ((uint32_t)0x00020000)
#define DMA1_INT_HT5                        ((uint32_t)0x00040000)
#define DMA1_INT_ERR5                       ((uint32_t)0x00080000)
#define DMA1_INT_GL6                        ((uint32_t)0x00100000)
#define DMA1_INT_TC6                        ((uint32_t)0x00200000)
#define DMA1_INT_HT6                        ((uint32_t)0x00400000)
#define DMA1_INT_ERR6                       ((uint32_t)0x00800000)
#define DMA1_INT_GL7                        ((uint32_t)0x01000000)
#define DMA1_INT_TC7                        ((uint32_t)0x02000000)
#define DMA1_INT_HT7                        ((uint32_t)0x04000000)
#define DMA1_INT_ERR7                       ((uint32_t)0x08000000)

#define DMA2_INT_GL1                        ((uint32_t)0x10000001)
#define DMA2_INT_TC1                        ((uint32_t)0x10000002)
#define DMA2_INT_HT1                        ((uint32_t)0x10000004)
#define DMA2_INT_ERR1                       ((uint32_t)0x10000008)
#define DMA2_INT_GL2                        ((uint32_t)0x10000010)
#define DMA2_INT_TC2                        ((uint32_t)0x10000020)
#define DMA2_INT_HT2                        ((uint32_t)0x10000040)
#define DMA2_INT_ERR2                       ((uint32_t)0x10000080)
#define DMA2_INT_GL3                        ((uint32_t)0x10000100)
#define DMA2_INT_TC3                        ((uint32_t)0x10000200)
#define DMA2_INT_HT3                        ((uint32_t)0x10000400)
#define DMA2_INT_ERR3                       ((uint32_t)0x10000800)
#define DMA2_INT_GL4                        ((uint32_t)0x10001000)
#define DMA2_INT_TC4                        ((uint32_t)0x10002000)
#define DMA2_INT_HT4                        ((uint32_t)0x10004000)
#define DMA2_INT_ERR4                       ((uint32_t)0x10008000)
#define DMA2_INT_GL5                        ((uint32_t)0x10010000)
#define DMA2_INT_TC5                        ((uint32_t)0x10020000)
#define DMA2_INT_HT5                        ((uint32_t)0x10040000)
#define DMA2_INT_ERR5                        ((uint32_t)0x10080000)

#define IS_DMA_CLEAR_INT(INT)               (((((INT) & 0xF0000000) == 0x00) || (((INT) & 0xEFF00000) == 0x00)) && ((INT) != 0x00))

#define IS_DMA_GET_INT(INT)                 (((INT) == DMA1_INT_GL1) || ((INT) == DMA1_INT_TC1) || \
                                             ((INT) == DMA1_INT_HT1) || ((INT) == DMA1_INT_ERR1) || \
                                             ((INT) == DMA1_INT_GL2) || ((INT) == DMA1_INT_TC2) || \
                                             ((INT) == DMA1_INT_HT2) || ((INT) == DMA1_INT_ERR2) || \
                                             ((INT) == DMA1_INT_GL3) || ((INT) == DMA1_INT_TC3) || \
                                             ((INT) == DMA1_INT_HT3) || ((INT) == DMA1_INT_ERR3) || \
                                             ((INT) == DMA1_INT_GL4) || ((INT) == DMA1_INT_TC4) || \
                                             ((INT) == DMA1_INT_HT4) || ((INT) == DMA1_INT_ERR4) || \
                                             ((INT) == DMA1_INT_GL5) || ((INT) == DMA1_INT_TC5) || \
                                             ((INT) == DMA1_INT_HT5) || ((INT) == DMA1_INT_ERR5) || \
                                             ((INT) == DMA1_INT_GL6) || ((INT) == DMA1_INT_TC6) || \
                                             ((INT) == DMA1_INT_HT6) || ((INT) == DMA1_INT_ERR6) || \
                                             ((INT) == DMA1_INT_GL7) || ((INT) == DMA1_INT_TC7) || \
                                             ((INT) == DMA1_INT_HT7) || ((INT) == DMA1_INT_ERR7) || \
                                             ((INT) == DMA2_INT_GL1) || ((INT) == DMA2_INT_TC1) || \
                                             ((INT) == DMA2_INT_HT1) || ((INT) == DMA2_INT_ERR1) || \
                                             ((INT) == DMA2_INT_GL2) || ((INT) == DMA2_INT_TC2) || \
                                             ((INT) == DMA2_INT_HT2) || ((INT) == DMA2_INT_ERR2) || \
                                             ((INT) == DMA2_INT_GL3) || ((INT) == DMA2_INT_TC3) || \
                                             ((INT) == DMA2_INT_HT3) || ((INT) == DMA2_INT_ERR3) || \
                                             ((INT) == DMA2_INT_GL4) || ((INT) == DMA2_INT_TC4) || \
                                             ((INT) == DMA2_INT_HT4) || ((INT) == DMA2_INT_ERR4) || \
                                             ((INT) == DMA2_INT_GL5) || ((INT) == DMA2_INT_TC5) || \
                                             ((INT) == DMA2_INT_HT5) || ((INT) == DMA2_INT_ERR5))

/**
  * @}
  */

/** @defgroup DMA_flags_definition
  * @{
  */
#define DMA1_FLAG_GL1                       ((uint32_t)0x00000001)
#define DMA1_FLAG_TC1                       ((uint32_t)0x00000002)
#define DMA1_FLAG_HT1                       ((uint32_t)0x00000004)
#define DMA1_FLAG_ERR1                      ((uint32_t)0x00000008)
#define DMA1_FLAG_GL2                       ((uint32_t)0x00000010)
#define DMA1_FLAG_TC2                       ((uint32_t)0x00000020)
#define DMA1_FLAG_HT2                       ((uint32_t)0x00000040)
#define DMA1_FLAG_ERR2                      ((uint32_t)0x00000080)
#define DMA1_FLAG_GL3                       ((uint32_t)0x00000100)
#define DMA1_FLAG_TC3                       ((uint32_t)0x00000200)
#define DMA1_FLAG_HT3                       ((uint32_t)0x00000400)
#define DMA1_FLAG_ERR3                      ((uint32_t)0x00000800)
#define DMA1_FLAG_GL4                       ((uint32_t)0x00001000)
#define DMA1_FLAG_TC4                       ((uint32_t)0x00002000)
#define DMA1_FLAG_HT4                       ((uint32_t)0x00004000)
#define DMA1_FLAG_ERR4                      ((uint32_t)0x00008000)
#define DMA1_FLAG_GL5                       ((uint32_t)0x00010000)
#define DMA1_FLAG_TC5                       ((uint32_t)0x00020000)
#define DMA1_FLAG_HT5                       ((uint32_t)0x00040000)
#define DMA1_FLAG_ERR5                      ((uint32_t)0x00080000)
#define DMA1_FLAG_GL6                       ((uint32_t)0x00100000)
#define DMA1_FLAG_TC6                       ((uint32_t)0x00200000)
#define DMA1_FLAG_HT6                       ((uint32_t)0x00400000)
#define DMA1_FLAG_ERR6                      ((uint32_t)0x00800000)
#define DMA1_FLAG_GL7                       ((uint32_t)0x01000000)
#define DMA1_FLAG_TC7                       ((uint32_t)0x02000000)
#define DMA1_FLAG_HT7                       ((uint32_t)0x04000000)
#define DMA1_FLAG_ERR7                      ((uint32_t)0x08000000)

#define DMA2_FLAG_GL1                       ((uint32_t)0x10000001)
#define DMA2_FLAG_TC1                       ((uint32_t)0x10000002)
#define DMA2_FLAG_HT1                       ((uint32_t)0x10000004)
#define DMA2_FLAG_ERR1                      ((uint32_t)0x10000008)
#define DMA2_FLAG_GL2                       ((uint32_t)0x10000010)
#define DMA2_FLAG_TC2                       ((uint32_t)0x10000020)
#define DMA2_FLAG_HT2                       ((uint32_t)0x10000040)
#define DMA2_FLAG_ERR2                      ((uint32_t)0x10000080)
#define DMA2_FLAG_GL3                       ((uint32_t)0x10000100)
#define DMA2_FLAG_TC3                       ((uint32_t)0x10000200)
#define DMA2_FLAG_HT3                       ((uint32_t)0x10000400)
#define DMA2_FLAG_ERR3                      ((uint32_t)0x10000800)
#define DMA2_FLAG_GL4                       ((uint32_t)0x10001000)
#define DMA2_FLAG_TC4                       ((uint32_t)0x10002000)
#define DMA2_FLAG_HT4                       ((uint32_t)0x10004000)
#define DMA2_FLAG_ERR4                      ((uint32_t)0x10008000)
#define DMA2_FLAG_GL5                       ((uint32_t)0x10010000)
#define DMA2_FLAG_TC5                       ((uint32_t)0x10020000)
#define DMA2_FLAG_HT5                       ((uint32_t)0x10040000)
#define DMA2_FLAG_ERR5                      ((uint32_t)0x10080000)

#define IS_DMA_CLEAR_FLAG(FLAG)             (((((FLAG) & 0xF0000000) == 0x00) || (((FLAG) & 0xEFF00000) == 0x00)) && ((FLAG) != 0x00))

#define IS_DMA_GET_FLAG(FLAG)               (((FLAG) == DMA1_FLAG_GL1) || ((FLAG) == DMA1_FLAG_TC1) || \
                                             ((FLAG) == DMA1_FLAG_HT1) || ((FLAG) == DMA1_FLAG_ERR1) || \
                                             ((FLAG) == DMA1_FLAG_GL2) || ((FLAG) == DMA1_FLAG_TC2) || \
                                             ((FLAG) == DMA1_FLAG_HT2) || ((FLAG) == DMA1_FLAG_ERR2) || \
                                             ((FLAG) == DMA1_FLAG_GL3) || ((FLAG) == DMA1_FLAG_TC3) || \
                                             ((FLAG) == DMA1_FLAG_HT3) || ((FLAG) == DMA1_FLAG_ERR3) || \
                                             ((FLAG) == DMA1_FLAG_GL4) || ((FLAG) == DMA1_FLAG_TC4) || \
                                             ((FLAG) == DMA1_FLAG_HT4) || ((FLAG) == DMA1_FLAG_ERR4) || \
                                             ((FLAG) == DMA1_FLAG_GL5) || ((FLAG) == DMA1_FLAG_TC5) || \
                                             ((FLAG) == DMA1_FLAG_HT5) || ((FLAG) == DMA1_FLAG_ERR5) || \
                                             ((FLAG) == DMA1_FLAG_GL6) || ((FLAG) == DMA1_FLAG_TC6) || \
                                             ((FLAG) == DMA1_FLAG_HT6) || ((FLAG) == DMA1_FLAG_ERR6) || \
                                             ((FLAG) == DMA1_FLAG_GL7) || ((FLAG) == DMA1_FLAG_TC7) || \
                                             ((FLAG) == DMA1_FLAG_HT7) || ((FLAG) == DMA1_FLAG_ERR7) || \
                                             ((FLAG) == DMA2_FLAG_GL1) || ((FLAG) == DMA2_FLAG_TC1) || \
                                             ((FLAG) == DMA2_FLAG_HT1) || ((FLAG) == DMA2_FLAG_ERR1) || \
                                             ((FLAG) == DMA2_FLAG_GL2) || ((FLAG) == DMA2_FLAG_TC2) || \
                                             ((FLAG) == DMA2_FLAG_HT2) || ((FLAG) == DMA2_FLAG_ERR2) || \
                                             ((FLAG) == DMA2_FLAG_GL3) || ((FLAG) == DMA2_FLAG_TC3) || \
                                             ((FLAG) == DMA2_FLAG_HT3) || ((FLAG) == DMA2_FLAG_ERR3) || \
                                             ((FLAG) == DMA2_FLAG_GL4) || ((FLAG) == DMA2_FLAG_TC4) || \
                                             ((FLAG) == DMA2_FLAG_HT4) || ((FLAG) == DMA2_FLAG_ERR4) || \
                                             ((FLAG) == DMA2_FLAG_GL5) || ((FLAG) == DMA2_FLAG_TC5) || \
                                             ((FLAG) == DMA2_FLAG_HT5) || ((FLAG) == DMA2_FLAG_ERR5))
/**
  * @}
  */

/** @defgroup DMA_Buffer_Size
  * @{
  */

#define IS_DMA_BUFFER_SIZE(SIZE)            (((SIZE) >= 0x1) && ((SIZE) < 0x10000))

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup DMA_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup DMA_Exported_Functions
  * @{
  */

void DMA_Reset(DMA_Channel_Type* DMAy_Channelx);
void DMA_Init(DMA_Channel_Type* DMAy_Channelx, DMA_InitType* DMA_InitStruct);
void DMA_DefaultInitParaConfig(DMA_InitType* DMA_InitStruct);
void DMA_ChannelEnable(DMA_Channel_Type* DMAy_Channelx, FunctionalState NewState);
void DMA_INTConfig(DMA_Channel_Type* DMAy_Channelx, uint32_t DMA_INT, FunctionalState NewState);
void DMA_SetCurrDataCounter(DMA_Channel_Type* DMAy_Channelx, uint16_t DataNumber);
uint16_t DMA_GetCurrDataCounter(DMA_Channel_Type* DMAy_Channelx);
FlagStatus DMA_GetFlagStatus(uint32_t DMAy_FLAG);
void DMA_ClearFlag(uint32_t DMAy_FLAG);
ITStatus DMA_GetITStatus(uint32_t DMAy_INT);
void DMA_ClearITPendingBit(uint32_t DMAy_INT);

#ifdef __cplusplus
}
#endif

#endif /*__AT32F4xx_DMA_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

