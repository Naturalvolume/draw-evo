### 数据说明
在每个文件夹下面
- image_0 image_1是图像数据
- 01 02 03等是轨迹真值groundtruth

02.txt等代表真值，但orb_slam单目只能保存关键帧的tum格式位姿．所以要把02.txt从kitti格式根据时间戳times.txt转换成tum格式，命令为
```
// /happy/dataset/kitti_sequences
python kitti_poses_to_tum.py 09/09.txt 09/times.txt 09/3_ground_truth_tum.txt
```

- 1_orb_tum.txt 是orb_slam执行过后保存的tum格式的关键帧位姿
- 2_segment_tum.txt 是加入实例分割后的orb关键帧位姿，也是tum格式
- 3_ground_truth.tum.txt 是把09.txt从kitti格式转换为tum格式
- calib.txt 相机基本参数
- times.txt 时间戳

### 用evo量化数据
- 轨迹可视化

```
cd 02
evo_traj tum 1_orb_tum.txt --ref 3_ground_truth_tum.txt -p -a -s

// --ref　指定参考轨迹
// -p 绘图
// -a (或--align)　进行对齐（旋转与平移）
// -s　改善单目的尺度不确定性，进行尺度缩放
```

- 绝对位姿误差
```
evo_ape tum 3_ground_truth_tum.txt 2_segment_tum.txt -a -s -p
```
- 相对位姿误差
```
evo_rpe tum 3_ground_truth_tum.txt 2_segment_tum.txt -a -s -p
```


