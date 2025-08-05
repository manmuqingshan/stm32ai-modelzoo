# BlazeFace Front 128x128 Quantized

## **Use case** : `Object detection`

# Model description

BlazeFace Front 128x128 is a lightweight and efficient face detection model optimized for real-time applications on embedded devices. It is a variant of the BlazeFace architecture, designed specifically for detecting frontal faces at a resolution of 128x128 pixels. The model is quantized to int8 format using TensorFlow Lite converter to reduce memory footprint and improve inference speed on resource-constrained hardware.

BlazeFace is known for its fast inference and accuracy, making it suitable for applications such as face tracking, augmented reality, and user authentication.

## Network information

| Network information     |  Value          |
|------------------------|-----------------|
| Framework              | TensorFlow Lite |
| Quantization           | int8            |
| Input resolution       | 128x128         |
| Provenance             | https://github.com/PINTO0309/PINTO_model_zoo/tree/main/030_BlazeFace |

## Network inputs / outputs

| Input Shape | Description |
|-------------|-------------|
| (1, 128, 128, 3) | Single 128x128 RGB image with FLOAT32 values between -1 and 1 |

| Output Shape | Description |
|--------------|-------------|
| (1, 512, 16) | FLOAT32 tensor containing bounding box coordinates and keypointss for detected faces |
| (1, 512, 1) | FLOAT32 tensor containing confidence scores for detected faces |
| (1, 384, 16) | FLOAT32 tensor containing bounding box coordinates and keypointss for detected faces |
| (1, 384, 1) | FLOAT32 tensor containing confidence scores for detected faces |

## Recommended Platforms

| Platform | Supported | Recommended |
|----------|-----------|-------------|
| STM32L0  | []        | []          |
| STM32L4  | []        | []          |
| STM32U5  | []        | []          |
| STM32H7  | []        | []          |
| STM32MP1 | []        | []          |
| STM32MP2 | []        | []          |
| STM32N6  | [x]       | [x]         |

## Performances

### Metrics

Performance metrics are measured using default STM32Cube.AI configurations with input/output allocated buffers.

| Model                | Dataset       | Format | Resolution | Series  | Internal RAM (KB) | External RAM (KB) | Weights Flash (KB) | STM32Cube.AI version | STEdgeAI Core version |
|----------------------|---------------|--------|------------|---------|-------------------|-------------------|--------------------|----------------------|-----------------------|
| [BlazeFace Front 128x128 per channel](Public_pretrainedmodel_public_dataset/wider_face/blazeface_front_128_quant_pc_ff_od_wider_face.tflite) | WIDER FACE (frontal) | Int8   | 128x128x3 | STM32N6 | 528               | 0              | 150.97            | 10.2.0               | 2.2.0                 |

### Reference **NPU** inference time (example)

| Model                | Dataset       | Format | Resolution | Board          | Execution Engine | Inference time (ms) | Inf / sec | STM32Cube.AI version | STEdgeAI Core version |
|----------------------|---------------|--------|------------|----------------|------------------|---------------------|-----------|----------------------|-----------------------|
| [BlazeFace Front 128x128 per channel](Public_pretrainedmodel_public_dataset/wider_face/blazeface_front_128_quant_pc_ff_od_wider_face.tflite) | WIDER FACE (frontal) | Int8   | 128x128x3 | STM32N6570-DK | NPU/MCU          | 5.09                 | 196.3       | 10.2.0               | 2.2.0                 |


## Integration and support

For integration examples and additional services, please refer to the STM32 AI model zoo services repository:  
[https://github.com/STMicroelectronics/stm32ai-modelzoo-services](https://github.com/STMicroelectronics/stm32ai-modelzoo-services)


## References

- BlazeFace paper: [https://arxiv.org/abs/1907.05047](https://arxiv.org/abs/1907.05047)  
- MediaPipe BlazeFace model repository: [https://github.com/PINTO0309/PINTO_model_zoo/tree/main/030_BlazeFace](https://github.com/PINTO0309/PINTO_model_zoo/tree/main/030_BlazeFace)  
- WIDER FACE dataset: [http://shuoyang1213.me/WIDERFACE/](http://shuoyang1213.me/WIDERFACE/)