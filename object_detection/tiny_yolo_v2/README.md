# Tiny Yolo v2 quantized

## **Use case** : `Object detection`

# Model description


Tiny Yolo v2 is a real-time object detection model targeted for real-time processing implemented in Tensorflow.

The model is quantized in int8 format using tensorflow lite converter.

## Network information


| Network information     |  Value          |
|-------------------------|-----------------|
|  Framework              | TensorFlow Lite |
|  Quantization           | int8            |
|  Provenance             | https://github.com/AlexeyAB/darknet
|  Paper                  | https://pjreddie.com/media/files/papers/YOLO9000.pdf |

The models are quantized using tensorflow lite converter.


## Network inputs / outputs


For an image resolution of NxM and NC classes

| Input Shape | Description |
| ----- | ----------- |
| (1, W, H, 3) | Single NxM RGB image with UINT8 values between 0 and 255 |

| Output Shape | Description |
| ----- | ----------- |
| (1, WxH, NAx(5+NC)) | FLOAT values Where WXH is the resolution of the output grid cell, NA is the number of anchors and NC is the number of classes|


## Recommended Platforms


| Platform | Supported | Recommended |
|----------|-----------|-------------|
| STM32L0  | []        | []          |
| STM32L4  | []        | []          |
| STM32U5  | []        | []          |
| STM32H7  | [x]       | []         |
| STM32MP1 | [x]       | [x]          |
| STM32MP2 | [x]       | [x]          |
| STM32N6  | [x]       | [x]          |

# Performances

## Metrics


Measures are done with default STM32Cube.AI configuration with enabled input / output allocated option.

### Reference **NPU** memory footprint based on COCO Person dataset (see Accuracy for details on dataset)
| Model                                                                                                            | Dataset     | Format   | Resolution   | Series   |   Internal RAM (KiB) |   External RAM (KiB) |   Weights Flash (KiB) | STM32Cube.AI version   | STEdgeAI Core version   |
|------------------------------------------------------------------------------------------------------------------|-------------|----------|--------------|----------|----------------------|----------------------|-----------------------|------------------------|-------------------------|
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_224/tiny_yolo_v2_224_int8.tflite) | COCO-Person | Int8     | 224x224x3    | STM32N6  |               392    |                    0 |               10794.4 | 10.2.0                 | 2.2.0                   |
| [tiny_yolo_v2](ST_pretrainedmodel_custom_dataset/st_person/tiny_yolo_v2_224/tiny_yolo_v2_224_int8.tflite)        | ST-Person   | Int8     | 224x224x3    | STM32N6  |               392    |                    0 |               10794.4 | 10.2.0                 | 2.2.0                   |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_416/tiny_yolo_v2_416_int8.tflite) | COCO-Person | Int8     | 416x416x3    | STM32N6  |              1880.12 |                    0 |               10818.4 | 10.2.0                 | 2.2.0                   |

### Reference **NPU**  inference time based on COCO Person dataset (see Accuracy for details on dataset)
| Model                                                                                                            | Dataset     | Format   | Resolution   | Board         | Execution Engine   |   Inference time (ms) |   Inf / sec | STM32Cube.AI version   | STEdgeAI Core version   |
|------------------------------------------------------------------------------------------------------------------|-------------|----------|--------------|---------------|--------------------|-----------------------|-------------|------------------------|-------------------------|
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_224/tiny_yolo_v2_224_int8.tflite) | COCO-Person | Int8     | 224x224x3    | STM32N6570-DK | NPU/MCU            |                 30.68 |       32.59 | 10.2.0                 | 2.2.0                   |
| [tiny_yolo_v2](ST_pretrainedmodel_custom_dataset/st_person/tiny_yolo_v2_224/tiny_yolo_v2_224_int8.tflite)        | ST-Person   | Int8     | 224x224x3    | STM32N6570-DK | NPU/MCU            |                 30.68 |       32.59 | 10.2.0                 | 2.2.0                   |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_416/tiny_yolo_v2_416_int8.tflite) | COCO-Person | Int8     | 416x416x3    | STM32N6570-DK | NPU/MCU            |                 50.81 |       19.68 | 10.2.0                 | 2.2.0                   |

### Reference **MCU** memory footprint based on COCO Person dataset (see Accuracy for details on dataset)

| Model                                                                                                            | Format   | Resolution   | Series   | Activation RAM   | Runtime RAM   | Weights Flash   | Code Flash   | Total RAM   | Total Flash   | STM32Cube.AI version   |
|------------------------------------------------------------------------------------------------------------------|----------|--------------|----------|------------------|---------------|-----------------|--------------|-------------|---------------|------------------------|
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_192/tiny_yolo_v2_192_int8.tflite) | Int8     | 192x192x3    | STM32H7  | 220.6 KiB        | 7.98 KiB      | 10775.98 KiB    | 55.85 KiB    | 228.58 KiB  | 10831.83 KiB  | 10.2.0                 |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_224/tiny_yolo_v2_224_int8.tflite) | Int8     | 224x224x3    | STM32H7  | 249.35           | 7.98 KiB      | 10775.98        | 55.24        | 257.33      | 10831.22      | 10.2.0                 |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_416/tiny_yolo_v2_416_int8.tflite) | Int8     | 416x416x3    | STM32H7  | 1263.07          | 8.03 KiB      | 10775.98        | 55.29        | 1271.10     | 10831.27      | 10.2.0                 |

### Reference **MCU** inference time based on COCO Person dataset (see Accuracy for details on dataset)


| Model                                                                                                            | Format   | Resolution   | Board            | Execution Engine   | Frequency   | Inference time (ms)   | STM32Cube.AI version   |
|------------------------------------------------------------------------------------------------------------------|----------|--------------|------------------|--------------------|-------------|-----------------------|------------------------|
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_192/tiny_yolo_v2_192_int8.tflite) | Int8     | 192x192x3    | STM32H747I-DISCO | 1 CPU              | 400 MHz     | 3006.3 ms             | 10.2.0                 |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_224/tiny_yolo_v2_224_int8.tflite) | Int8     | 224x224x3    | STM32H747I-DISCO | 1 CPU              | 400 MHz     | 2712.22               | 10.2.0                 |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_416/tiny_yolo_v2_416_int8.tflite) | Int8     | 416x416x3    | STM32H747I-DISCO | 1 CPU              | 400 MHz     | 10441.33              | 10.2.0                 |

### Reference **MPU** inference time based on COCO Person dataset (see Accuracy for details on dataset)


| Model        | Format | Resolution | Quantization  | Board             | Execution Engine | Frequency | Inference time (ms) | %NPU  | %GPU  | %CPU | X-LINUX-AI version |       Framework       |
|--------------|--------|------------|---------------|-------------------|------------------|-----------|---------------------|-------|-------|------|--------------------|-----------------------|
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_224/tiny_yolo_v2_224_int8.tflite) | Int8   | 224x224x3  |  per-channel**  | STM32MP257F-DK2   | NPU/GPU          | 800  MHz  | 137.51 ms            | 3.83  | 96.17 |0     | v6.1.0             | OpenVX                |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_416/tiny_yolo_v2_416_int8.tflite) | Int8   | 416x416x3  |  per-channel**  | STM32MP257F-DK2   | NPU/GPU          | 800  MHz  | 481.09 ms            | 2.57  | 97.43 |0     | v6.1.0             | OpenVX                |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_224/tiny_yolo_v2_224_int8.tflite) | Int8   | 224x224x3  |  per-channel  | STM32MP157F-DK2   | 2 CPU            | 800  MHz  | 417.84 ms           | NA    | NA    |100   | v6.1.0             | TensorFlowLite 2.18.0 |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_416/tiny_yolo_v2_416_int8.tflite) | Int8   | 416x416x3  |  per-channel  | STM32MP157F-DK2   | 2 CPU            | 800  MHz  | 1302.07 ms             | NA    | NA    |100   | v6.1.0             | TensorFlowLite 2.18.0 |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_224/tiny_yolo_v2_224_int8.tflite) | Int8   | 224x224x3  |  per-channel  | STM32MP135F-DK2   | 1 CPU            | 1000 MHz  | 623.35 ms           | NA    | NA    |100   | v6.1.0             | TensorFlowLite 2.18.0 |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_416/tiny_yolo_v2_416_int8.tflite) | Int8   | 416x416x3  |  per-channel  | STM32MP135F-DK2   | 1 CPU            | 1000 MHz  | 2101.3 ms             | NA    | NA    |100   | v6.1.0             | TensorFlowLite 2.18.0 |

** **To get the most out of MP25 NPU hardware acceleration, please use per-tensor quantization**

### AP on COCO Person dataset

Dataset details: [link](https://cocodataset.org/#download) , License [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/legalcode) , Quotation[[1]](#1) , Number of classes: 80, Number of images: 118,287

| Model | Format | Resolution |       AP       |
|-------|--------|------------|----------------|
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_192/tiny_yolo_v2_192_int8.tflite) | Int8 | 192x192x3   | 26.2 % |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_192/tiny_yolo_v2_192.h5) | Float | 192x192x3   | 27.5 % |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_224/tiny_yolo_v2_224_int8.tflite) | Int8 | 224x224x3   | 28.8 % |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_224/tiny_yolo_v2_224.h5) | Float | 224x224x3   | 30.9 % |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_416/tiny_yolo_v2_416_int8.tflite) | Int8 | 416x416x3   | 41.4 % |
| [tiny_yolo_v2](ST_pretrainedmodel_public_dataset/coco_2017_person/tiny_yolo_v2_416/tiny_yolo_v2_416.h5) | Float | 416x416x3   | 43.4 % |

\* EVAL_IOU = 0.5, NMS_THRESH = 0.5, SCORE_THRESH = 0.001, MAX_DETECTIONS = 100

### AP on ST Person dataset
This model has been trained using a STMicroelectronics proprietary dataset which is not provided as part of the STM32 model zoo. The ST person dataset has been built by aggregating several public datasets and by applying data augmentation on these public datasets. If users wish to retrain this model it has to be done using another dataset selected by the user.

| Model | Format | Resolution |       AP       |
|-------|--------|------------|----------------|
| [tiny_yolo_v2](ST_pretrainedmodel_custom_dataset/st_person/tiny_yolo_v2_224/tiny_yolo_v2_224_int8.tflite) | Int8 | 224x224x3   |  28.5 % |


\* EVAL_IOU = 0.5, NMS_THRESH = 0.5, SCORE_THRESH = 0.001, MAX_DETECTIONS = 100

## Retraining and Integration in a simple example:

Please refer to the stm32ai-modelzoo-services GitHub [here](https://github.com/STMicroelectronics/stm32ai-modelzoo-services)


# References


<a id="1">[1]</a>
“Microsoft COCO: Common Objects in Context”. [Online]. Available: https://cocodataset.org/#download.
@article{DBLP:journals/corr/LinMBHPRDZ14,
  author    = {Tsung{-}Yi Lin and
               Michael Maire and
               Serge J. Belongie and
               Lubomir D. Bourdev and
               Ross B. Girshick and
               James Hays and
               Pietro Perona and
               Deva Ramanan and
               Piotr Doll{'{a} }r and
               C. Lawrence Zitnick},
  title     = {Microsoft {COCO:} Common Objects in Context},
  journal   = {CoRR},
  volume    = {abs/1405.0312},
  year      = {2014},
  url       = {http://arxiv.org/abs/1405.0312},
  archivePrefix = {arXiv},
  eprint    = {1405.0312},
  timestamp = {Mon, 13 Aug 2018 16:48:13 +0200},
  biburl    = {https://dblp.org/rec/bib/journals/corr/LinMBHPRDZ14},
  bibsource = {dblp computer science bibliography, https://dblp.org}
}
