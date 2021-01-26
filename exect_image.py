#coding=utf-8
import cv2

vc = cv2.VideoCapture('bike.mp4')  # 读入视频文件
path = "image_0/"
timeF = 3  # 视频帧计数间隔频率

c=0
count = 0

 
while vc.isOpened():
    # 循环读取视频帧
    rval, frame = vc.read()
    # cv2.imshow("img", frame)
    # cv2.waitKey(200)

    #gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
 
    # Display the resulting frame
    if rval:	
        if (c % timeF == 0):
            # 每隔timeF帧进行存储操作
            if count < 10:
                cv2.imwrite(path + '00000' + str(count) + '.png', frame)  # 存储为图像
            elif count >= 10 and count < 100:
                cv2.imwrite(path + '0000' + str(count) + '.png', frame)
            elif count >= 100 and count < 1000:
                cv2.imwrite(path + '000' + str(count) + '.png', frame)
            elif count >= 1000 and count < 10000:
                cv2.imwrite(path + '00'+ str(count) + '.png', frame)
            else:
                cv2.imwrite(path + str(count) + '.png', frame)
            count = count + 1

        c = c + 1
    else:
        break
    
    # if cv2.waitKey(1) & 0xFF == ord('q'):
    #     break
 
vc.release()
cv2.destroyAllWindows()
