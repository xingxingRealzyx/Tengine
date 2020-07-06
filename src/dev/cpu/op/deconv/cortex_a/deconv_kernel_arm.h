/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * License); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * AS IS BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Copyright (c) 2020, OPEN AI LAB
 * Author: haoluo@openailab.com
 */
#ifndef __DECONV_KERNEL_ARM_H_
#define __DECONV_KERNEL_ARM_H_

#include "tengine_ir.h"
#include "deconv_param.h"

struct deconv_priv_info
{
    float* interleave_buffer ;
    int interleave_buffer_size;
    float* col_buffer ; 
    int col_buffer_size;
    float* trans_input_buffer;
    int trans_input_size;
};

int deconv_hcl_prerun(struct ir_tensor*  input_tensor , \
                    struct ir_tensor*  filter_tensor ,  \
                    struct ir_tensor*  output_tensor , \
                    struct deconv_priv_info* info ,      \
                    struct deconv_param* param)  __attribute__((weak)); 

int deconv_hcl_postrun(struct deconv_priv_info* info) __attribute__((weak));

int deconv_hcl_run(struct ir_tensor* input_tensor , \
                 struct ir_tensor* filter_tensor ,\
                 struct ir_tensor* bias_tensor ,  \
                 struct ir_tensor* output_tensor , \
                 struct deconv_priv_info*  deconv_info , \
                 struct deconv_param* param, \
                 int num_thread, \
                 int cpu_affinity)  __attribute__((weak));


#endif
