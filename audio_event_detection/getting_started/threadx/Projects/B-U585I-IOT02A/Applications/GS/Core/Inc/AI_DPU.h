/**
  ******************************************************************************
  * @file    AI_DPU.h
  * @author  STMicroelectronics - AIS - MCD Team
  * @brief   Digital processing Unit specialized for the Cube.AI library  *
  * This DPU process the data using Ai library generated by Cube.AI.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef AI_DPU_H_
#define AI_DPU_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ADPU2.h"
#include "ADPU2_vtbl.h"
#include "network.h"
#include "network_data.h"
#include "config.h"

#define AI_MNETWORK_NUMBER         (1U)

#define AI_DPU_NB_AXIS             (3U)
#define AI_DPU_SHAPE_SIZE          (4U)
#define AI_DPU_SHAPE_BATCH_MAX     (1U)
#define AI_DPU_SHAPE_HEIGHT_MAX    (100U)
#define AI_DPU_SHAPE_WIDTH_MAX     (100U)
#define AI_DPU_SHAPE_CHANNEL_MAX   (100U)


#define AI_DPU_X_CUBE_AI_API_MAJOR (1)
#define AI_DPU_X_CUBE_AI_API_MINOR (2)
#define AI_DPU_X_CUBE_AI_API_MICRO (0)

#define AI_DPU_NB_MAX_INPUT        (1U)
#define AI_DPU_NB_MAX_OUTPUT       (2U)

/**
 * Create  type name for _AI_DPU_t
 */
typedef struct _AI_DPU_t AI_DPU_t;

/**
 * AiDPU_t internal state.
 * It declares only the virtual table used to implement the inheritance.
 */
struct _AI_DPU_t {
  /**
   * Base class object.
   */
  ADPU2_t super;
  /**
    * AI network informations & handler
    */
  struct ai_network_exec_ctx {
      ai_handle handle;
      ai_network_report report;
  }net_exec_ctx[AI_MNETWORK_NUMBER];

  /**
    * AI network activation buffer
    */
  AI_ALIGNED(32)
  uint8_t activation_buffer[AI_NETWORK_DATA_ACTIVATION_1_SIZE];

#ifndef  AI_NETWORK_INPUTS_IN_ACTIVATIONS
  /**
  * AI network input
  */
  AI_ALIGNED(4)
  uint8_t in[AI_NETWORK_IN_1_SIZE_BYTES];
#endif

#ifndef  AI_NETWORK_OUTPUTS_IN_ACTIVATIONS
  /**
  * AI network output
  */
  AI_ALIGNED(4)
  uint8_t out1[AI_NETWORK_OUT_1_SIZE_BYTES];
#if (AI_NETWORK_OUT_NUM==2)
  AI_ALIGNED(4)
  uint8_t out2[AI_NETWORK_OUT_2_SIZE_BYTES];
#endif
#endif

  /**
   * Specifies AI processing scale factor.
   */
  float scale;

  /**
   * Specifies AI processing scale factor.
   */
  uint32_t sensor_type;

  /**
   * Specifies the quantization parameters of teh unique input of the network
   */
  float input_Q_inv_scale;
  int   input_Q_offset;
};


/* Public API declaration */
/**************************/

/**
 * Allocate an instance of NeaiDPU_t in the heap.
 *
 * @return a pointer to the generic object ::IDPU if success,
 * or NULL if out of memory error occurs.
 */
IDPU2_t *AI_DPU_Alloc(void);

/**
 * Allocate an instance of AI_DPU_t in a memory block specified by the application.
 * The size of the memory block must be greater or equal to sizeof(AI_DPU_t).
 * This allocator allows the application to avoid the dynamic allocation.
 *
 * \code
 * AI_DPU_t dpu;
 * AI_DPU_StaticAlloc(&dpu);
 * \endcode
 *
 * @param p_mem_block [IN] specify a memory block allocated by the application.
 *        The size of the memory block must be greater or equal to sizeof(NeaiDPU_t).
 * @return a pointer to the generic object ::IDPU2_t if success,
 * or NULL if out of memory error occurs.
 */
IDPU2_t *AI_DPU_StaticAlloc(void *p_mem_block);

/**
 * Initialize the DPU. It must called before using the instance.
 * After the initialization the DPU needs two memory buffers to manage the input and output data.
 * The memory allocation is delegated to the application. The application use the following methods
 * to set the buffers needed by the DPU:
 * - ADPU2_SetInDataBuffer()
 * - ADPU2_SetOutDataBuffer()
 *
 * @param _this [IN] specifies a pointer to the object.
 * @return SYS_NO_ERROR_CODE if success, an application specific error code otherwise.
 */
sys_error_code_t AI_DPU_Init(AI_DPU_t *_this);

/**
 * Set the processing mode for the DPU. It specifies to the DPU if a new signal is used
 * to learn and improve the model, or to detect anomalies.
 *
 * @param _this [IN] specifies a pointer to the object.
 * @param sensi [IN] specifies the sensitivity of the sensor
 * @return SYS_NO_ERROR_CODE if success, an error code otherwise.
 */
sys_error_code_t AI_DPU_SetSensitivity(AI_DPU_t *_this, float sensi);

/**
 * load X-CUBE-AI model for DPU processing .
 *
 * @param _this [IN] specifies a pointer to the object.
 * @param name [IN] specifies the model name
 * @return SYS_NO_ERROR_CODE if success, an error code otherwise.
 */
sys_error_code_t AiDPULoadModel(AI_DPU_t *_this, const char *name);

/**
 * release X-CUBE-AI model for DPU processing .
 *
 * @param _this [IN] specifies a pointer to the object.
 * @param name [IN] specifies the model name
 * @return SYS_NO_ERROR_CODE if success, an error code otherwise.
 */
sys_error_code_t AiDPUReleaseModel(AI_DPU_t *_this);


/* Inline functions definition */
/*******************************/


#ifdef __cplusplus
}
#endif

#endif /* AI_DPU_H_ */
