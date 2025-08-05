# Yolov8n object detection quantized

## **Use case** : `Object detection`

# Model description

Yolov8n is a lightweight and efficient object detection model designed for instance segmentation tasks. It is part of the YOLO (You Only Look Once) family of models, known for their real-time object detection capabilities. The "n" in Yolov8n_seg indicates that it is a nano version, optimized for speed and resource efficiency, making it suitable for deployment on devices with limited computational power, such as mobile devices and embedded systems.

Yolov8n is implemented in Pytorch by Ultralytics and is quantized in int8 format using tensorflow lite converter.

## Network information


| Network information     |  Value          |
|-------------------------|-----------------|
|  Framework              | TensorFlow Lite |
|  Quantization           | int8            |
|  Provenance             | https://docs.ultralytics.com/tasks/detect/ |


## Networks inputs / outputs

With an image resolution of NxM and K classes to detect:

| Input Shape | Description |
| ----- | ----------- |
| (1, N, M, 3) | Single NxM RGB image with UINT8 values between 0 and 255 |

| Output Shape | Description |
| ----- | ----------- |
| (1, 4+K, F) | FLOAT values Where F = (N/8)^2 + (N/16)^2 + (N/32)^2 is the 3 concatenated feature maps |


## Recommended Platforms


| Platform | Supported | Recommended |
|----------|-----------|-------------|
| STM32L0  | []        | []          |
| STM32L4  | []        | []          |
| STM32U5  | []        | []          |
| STM32H7  | []        | []          |
| STM32MP1 | []        | []          |
| STM32MP2 | [x]       | [x]         |
| STM32N6  | [x]       | [x]         |


# Performances

## Metrics

Measures are done with default STM32Cube.AI configuration with enabled input / output allocated option.  
> [!CAUTION] 
> All YOLOv8 hyperlinks in the tables below link to an external GitHub folder, which is subject to its own license terms:
https://github.com/stm32-hotspot/ultralytics/blob/main/LICENSE
Please also check the folder's README.md file for detailed information about its use and content:
https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/README.md


### Reference **NPU** memory footprint based on COCO Person dataset (see Accuracy for details on dataset)
| Model                                                                                                                                                                                 | Dataset     | Format   | Resolution   | Series   |   Internal RAM |   External RAM |   Weights Flash | STM32Cube.AI version   | STEdgeAI Core version   |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------|----------|--------------|----------|----------------|----------------|-----------------|------------------------|-------------------------|
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_192_quant_pc_uf_od_coco-person.tflite) | COCO-Person | Int8     | 192x192x3    | STM32N6  |         261    |              0 |         2936.52 | 10.2.0                 | 2.2.0                   |
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_256_quant_pc_uf_od_coco-person.tflite) | COCO-Person | Int8     | 256x256x3    | STM32N6  |         624    |              0 |         2941.09 | 10.2.0                 | 2.2.0                   |
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_320_quant_pc_uf_od_coco-person.tflite) | COCO-Person | Int8     | 320x320x3    | STM32N6  |         839.06 |              0 |         2947.02 | 10.2.0                 | 2.2.0                   |
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_416_quant_pc_uf_od_coco-person.tflite) | COCO-Person | Int8     | 416x416x3    | STM32N6  |        2242.84 |              0 |         2958.34 | 10.2.0                 | 2.2.0                   |
### Reference **NPU**  inference time based on COCO Person dataset (see Accuracy for details on dataset)
| Model                                                                                                                                                                                 | Dataset     | Format   | Resolution   | Board         | Execution Engine   |   Inference time (ms) |   Inf / sec | STM32Cube.AI version   | STEdgeAI Core version   |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------|----------|--------------|---------------|--------------------|-----------------------|-------------|------------------------|-------------------------|
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_192_quant_pc_uf_od_coco-person.tflite) | COCO-Person | Int8     | 192x192x3    | STM32N6570-DK | NPU/MCU            |                 16.88 |       59.24 | 10.2.0                 | 2.2.0                   |
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_256_quant_pc_uf_od_coco-person.tflite) | COCO-Person | Int8     | 256x256x3    | STM32N6570-DK | NPU/MCU            |                 24.94 |       40.1  | 10.2.0                 | 2.2.0                   |
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_320_quant_pc_uf_od_coco-person.tflite) | COCO-Person | Int8     | 320x320x3    | STM32N6570-DK | NPU/MCU            |                 31.75 |       31.5  | 10.2.0                 | 2.2.0                   |
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_416_quant_pc_uf_od_coco-person.tflite) | COCO-Person | Int8     | 416x416x3    | STM32N6570-DK | NPU/MCU            |                 53.11 |       18.83 | 10.2.0                 | 2.2.0                   |
### Reference **MPU** inference time based on COCO Person dataset (see Accuracy for details on dataset)
 Model         | Format | Resolution | Quantization  | Board             | Execution Engine | Frequency | Inference time (ms) | %NPU  | %GPU  | %CPU | X-LINUX-AI version |       Framework       |
|-----------|--------|------------|---------------|-------------------|------------------|-----------|---------------------|-------|-------|------|--------------------|-----------------------|
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_256_quant_pc_uf_pose_coco-st.tflite) | Int8   | 256x256x3  |  per-channel**  | STM32MP257F-DK2   | NPU/GPU          | 800  MHz  | 102.8 ms            | 11.70  | 88.30 |0     | v6.1.0             | OpenVX                |
| [YOLOv8n per tensor](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_256_quant_pt_uf_pose_coco-st.tflite)  | Int8   | 256x256x3  |  per-tensor     | STM32MP257F-DK2   | NPU/GPU          | 800  MHz  | 17.57 ms            | 86.79  | 13.21 |0     | v6.1.0             | OpenVX                |

** **To get the most out of MP25 NPU hardware acceleration, please use per-tensor quantization**

### AP on COCO Person dataset


Dataset details: [link](https://cocodataset.org/#download) , License [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/legalcode) , Quotation[[1]](#1) , Number of classes: 80, Number of images: 118,287


| Model | Format | Resolution |       AP*   |
|-------|--------|------------|----------------|
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_192_quant_pc_uf_od_coco-person.tflite) | Int8   | 192x192x3  | 53.50 %  |
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_256_quant_pc_uf_od_coco-person.tflite) | Int8   | 256x256x3  | 58.40 %  |
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_320_quant_pc_uf_od_coco-person.tflite) | Int8   | 320x320x3  | 61.80 %  |
| [YOLOv8n per channel](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/object_detection/yolov8n_416_quant_pc_uf_od_coco-person.tflite) | Int8   | 416x416x3  | 64.80 %  |

\* EVAL_IOU = 0.5, NMS_THRESH = 0.5, SCORE_THRESH = 0.001, MAX_DETECTIONS = 100

## Integration in a simple example and other services support:

Please refer to the stm32ai-modelzoo-services GitHub [here](https://github.com/STMicroelectronics/stm32ai-modelzoo-services).
The models are stored in the Ultralytics repository. You can find them at the following link: [Ultralytics YOLOv8-STEdgeAI Models](https://github.com/stm32-hotspot/ultralytics/blob/main/examples/YOLOv8-STEdgeAI/stedgeai_models/).

Please refer to the [Ultralytics documentation](https://docs.ultralytics.com/tasks/detect/#train) to retrain the models.

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
