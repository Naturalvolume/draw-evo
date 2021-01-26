这是做实验过程中用到的工具性函数
- exect_image.py 是从视频中提取图片成kitti数据集格式, 使用前需要更改视频文件位置, 和图片保存位置
- kitti_poses_to_tum.py 把kitti格式轨迹转换成tum格式的, 便于进行轨迹对照
- experiment_meaning.md 画图以及数据解释
- FormatCag 是师姐留下来的格式转换工具
- eval.py 是修改后保存掩码位置的yolact代码
```
# 修改后使用yolact
python3 eval.py --trained_model=weights/yolact_resnet50_54_800000.pth --score_threshold=0.15 --top_k=15 --images=/home/kathy/happy/dataset/image_0:/home/kathy/happy/dataset/image_1

# yolact的原始命令
# Display qualitative results on the specified image.
python eval_origin.py --trained_model=weights/yolact_resnet50_54_800000.pth --score_threshold=0.15 --top_k=15 --image=/home/kathy/happy/dataset/person/image_0/000000.jpg

# Process an image and save it to another file.
python eval_origin.py --trained_model=weights/yolact_resnet50_54_800000.pth --score_threshold=0.15 --top_k=15 --image=input_image.png:output_image.png

# Process a whole folder of images.
python eval_origin.py --trained_model=weights/yolact_resnet50_54_800000.pth --score_threshold=0.15 --top_k=15 --images=path/to/input/folder:path/to/output/folder
```



