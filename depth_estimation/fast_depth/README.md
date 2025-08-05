# FastDepth

## **Use case** : `Depth Estimation`

# Model description

FastDepth is a lightweight encoder-decoder network designed for real-time monocular depth estimation, optimized for edge devices. This implementation is based on model number 146 from [PINTO's model zoo](https://github.com/PINTO0309/PINTO_model_zoo), which builds upon a MobileNetV1 based feature extractor and a fast decoder.

Although the original training dataset is not explicitly provided, it is most likely **NYU Depth V2**, a standard benchmark dataset for indoor depth estimation.

## Network information


| Network Information     | Value                                                          |
|-------------------------|----------------------------------------------------------------|
|  Framework              | TensorFlowLite                      |
|  Quantization           | int8                                |
|  Provenance             | PINTO Model Zoo #146                |
|  Paper                  | [Link to Paper](https://arxiv.org/pdf/1903.03273)|

The models are quantized using tensorflow lite converter.


## Network inputs / outputs

| Input Shape  | Description                                         |
|--------------|-----------------------------------------------------|
| (1, H, W, 3) | Single RGB image (int8)     |

| Output Shape  | Description                                     |
|---------------|-------------------------------------------------|
| (1, H, W, 1)  | Single-channel depth prediction (int8)|


## Recommended platforms


| Platform | Supported | Recommended |
|----------|--------|-----------|
| STM32L0  |[]|[]|
| STM32L4  |[]|[]|
| STM32U5  |[]|[]|
| STM32H7  |[]|[]|
| STM32MP1 |[]|[]|
| STM32MP2 |[x]|[x]|
| STM32N6  |[x]|[x]|


# Performances

## Metrics

Measures are done with default STM32Cube.AI configuration with enabled input / output allocated option.

### Reference **NPU** memory footprint 

| Model      | Dataset       | Format   | Resolution | Series    | Internal RAM (KiB) | External RAM (KiB) | Weights Flash (KiB) | STM32Cube.AI version | STEdgeAI Core version |
|------------|---------------|----------|------------|-----------|--------------|--------------|---------------|----------------------|-----------------------|
| [Fast Depth](Public_pretrainedmodel_public_dataset/nyu_depth_v2/fast_depth_224/fast_depth_224_int8_pc.tflite) | NYU depth v2 | Int8 | 224x224x3 | STM32N6 | 2365.98 | 0.0  | 1505.19 |  10.2.0  | 2.2.0 |
| [Fast Depth](Public_pretrainedmodel_public_dataset/nyu_depth_v2/fast_depth_224/fast_depth_224_int8_pc.tflite) | NYU depth v2 | Int8 | 256x256x3 | STM32N6 | 2688 | 1024.0  | 1505.19 |  10.2.0  | 2.2.0 |
| [Fast Depth](Public_pretrainedmodel_public_dataset/nyu_depth_v2/fast_depth_320/fast_depth_320_int8_pc.tflite) | NYU depth v2 | Int8 | 224x224x3 | STM32N6 | 2800 | 1600 | 1505.17 |  10.2.0  | 2.2.0 |


### Reference **NPU**  inference time 


| Model      | Dataset       | Format   | Resolution | Board            | Execution Engine | Inference time (ms) | Inf / sec   | STM32Cube.AI version  |  STEdgeAI Core version |
|------------|---------------|----------|------------|------------------|------------------|---------------------|-------------|----------------------|-------------------------|
| [Fast Depth](Public_pretrainedmodel_public_dataset/nyu_depth_v2/fast_depth_224/fast_depth_224_int8_pc.tflite) | NYU depth v2    | Int8   | 224x224x3  | STM32N6570-DK   |   NPU/MCU      |      24.43      |   40.93    |       10.2.0        |     2.2.0   |
| [Fast Depth](Public_pretrainedmodel_public_dataset/nyu_depth_v2/fast_depth_224/fast_depth_224_int8_pc.tflite) | NYU depth v2    | Int8   | 256x256x3  | STM32N6570-DK   |   NPU/MCU      |     55.51    |   18.01   |       10.2.0        |     2.2.0   |
| [Fast Depth](Public_pretrainedmodel_public_dataset/nyu_depth_v2/fast_depth_320/fast_depth_320_int8_pc.tflite) | NYU depth v2    | Int8   | 320x320x3  | STM32N6570-DK   |   NPU/MCU      |     56.07    |   17.83   |       10.2.0        |     2.2.0   |



Please refer to the stm32ai-modelzoo-services GitHub [here](https://github.com/STMicroelectronics/stm32ai-modelzoo-services)
