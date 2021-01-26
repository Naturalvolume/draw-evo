orb-slam2 -> /happy/ORB_SLAM2/Examples/Monocular -> ./mono_kitti /home/kathy/happy/ORB_SLAM2/Vocabulary/ORBvoc.txt KITTI00-02.yaml /home/kathy/projects/Data/Kitti/dataset/sequences/02

segment-orb-slam2 ->  /happy/ORB_SLAM2/Examples/Monocular -> ./mono_kitti /home/kathy/happy/ORB_SLAM2/Vocabulary/ORBvoc.txt KITTI00-02.yaml /home/kathy/projects/Data/Kitti/dataset/sequences/01 /home/kathy/happy/data/01 

yolact -> happy/yolact -> python3 eval.py --trained_model=weights/yolact_resnet50_54_800000.pth --score_threshold=0.15 --top_k=15 --images=/home/kathy/projects/Data/Kitti/dataset/sequences/02/image_0:/home/kathy/happy/data/02/image_0




