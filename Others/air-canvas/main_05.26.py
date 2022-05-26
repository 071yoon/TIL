import cv2
import mediapipe as mp
from collections import deque
import pyautogui
from datetime import date

# pen
red = (0, 0, 255)
green = (0, 255, 0)
black = (0, 0, 0)
white = (255, 255, 255)

# 일단 잘보이게 기본 설정을 green
draw_color = green
draw_color_str = "green"

# 강도는 10, 커질수록 두꺼워짐
# 추후에 손가락 연산을 통해 더 두꺼워질 수 있게 설정 가능
thickness = 10
thick = "2"

# color index
black_index = 0
green_index = 0
red_index = 0 

# thick index
thick_index = 0
# camera
wCam, hCam = 1080, 720

# 노트북 내장캠 사용시 0, 별도의 웹캠 사용시 1
cap = cv2.VideoCapture(0) # camera object
cap.set(3, wCam)
cap.set(4, hCam)



# canvas = cv2.imread('canvas.jpg') # drawing canvas
# canvas_height, canvas_width, channels = canvas.shape # canvas parameters

# cache
# cache = img.copy()
# clear_canvas = img.copy()

mpHands = mp.solutions.hands # MediaPipe solution object
hands = mpHands.Hands(max_num_hands = 1) # hand object
mpDraw = mp.solutions.drawing_utils # drawing on hand

# 이전 2번쨰 손가락의 좌표
px = 0
py = 0

# 현재 그리고 있는지
cont = 0
src_cnt = 0
src = 0

# 손가락 1, 2, 3, 4, 5에 해당하는 tip
tipIds = [4, 8, 12, 16, 20]


# !rgb deque
# 여기에 계속 R,G,B 기준으로 그리는걸 데이터로 쌓는다
# 어차피 (px, py) -> (index_lm_x, index_lm_y) 로 갈 때만 그리므로
# 모든 (px, py) 의 데이터들만 기억해 두었다가
# 추후에 화면에 뿌리기 전에 연결만 해주면 된다
# 색에 따라 R,G,B 로 나누어서 저장
bpoints = [deque(maxlen=1024)]
gpoints = [deque(maxlen=1024)]
rpoints = [deque(maxlen=1024)]
thickpoints = [deque(maxlen=1024)]

# 일단 계속 돌아가게 설정
while True:

    success, img = cap.read() # reads image from camera
    img = cv2.flip(img, 1) #flip
    # cache = img.copy()
    # clear_canvas = img.copy()
    h, w, c = img.shape # image dimensions
    imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB) # BGR to RGB
    # imgRGB에 대하여 손이 있는지 mediapipe 연산을 통하여 찾는다
    results = hands.process(imgRGB) # searching for a hand

    # text 오른쪽 (가로-오른쪽방향, 세로-아래방향)
    # cv2.rectangle(img, (w-400, 60), (w-10, 500), (255, 255, 255), -1)
    cv2.putText(img, "Date: " + date.today().strftime("%Y%m%d"), (w-350, 50), cv2.FONT_HERSHEY_PLAIN, 2, black, 2)
    hand_detect = results.multi_hand_landmarks
    cv2.putText(img, "Thickness : " + str(thick), (w-350, 100), cv2.FONT_HERSHEY_PLAIN, 2, black, 2)
    cv2.putText(img, "Pen color: ", (w-350, 150), cv2.FONT_HERSHEY_PLAIN, 2, black, 2) # 색깔
    cv2.circle(img, (w-150, 140), 15, green, -1)
    cv2.circle(img, (w-100, 140), 15, black, -1)
    cv2.circle(img, (w-50, 140), 15, red, -1)
    
    c_w = w-150
    if( draw_color == black ): c_w = w-100
    if( draw_color == red ): c_w = w-50
    cv2.circle(img, (c_w, 140), 18, white, 3)

    cv2.putText(img, "Hand detect: " + str(bool(hand_detect)), (w-350, 200), cv2.FONT_HERSHEY_PLAIN, 2, black, 2) # 손 측정

    flag = 1
    # 손을 찾았다면 OK
    if hand_detect: # if the hand is found
        # !추후에 여러 손도 가능하게 도입하기 위하여 우선 손마다 연산을 가능하게 하였다
        for handLms in hand_detect: # for each hand
            # mediapipe 에서 제공하는 손 module 전부 받기
            lmList = [] #hands list 0 to 20
            for id in enumerate(handLms.landmark):
                cx, cy = handLms.landmark[id[0]].x, handLms.landmark[id[0]].y
                lmList.append([id[0], cx, cy])
            if len(lmList) != 0: #if recognized well
                fingers = []
                # !is thumb up 
                # 엄지가 Open 되어 있는지 확인하는 연산
                # mediapipe 에서 제공해주는 대로 사용
                # 2번째 마디보다 바깥에 있다면 펴져있다고 판정
                # 만약 열려있다면, 총 개수에서 추가
                #오른손일 때
                if lmList[2][1] > lmList[18][1]:
                    if lmList[4][1] > lmList[3][1]:
                        fingers.append(1)
                    else:
                        fingers.append(0)
                #왼손일 때
                else:
                    if lmList[4][1] < lmList[3][1]:
                      fingers.append(1)
                    else:
                       fingers.append(0)
                # !is other fingers up
                # 2~5 번쨰 손가락들에 대한 연산
                # 마찬가지로 mediapipe 에 대한 연산으로 실행
                # 2~5 번째 손가락은 마디가 3개 이므로
                # 3번쨰 마디보다 바깥에 있다면 손가락이 펴졌다고 판정
                for id in range(1, 5):
                    if lmList[tipIds[id]][2] < lmList[tipIds[id] - 2][2]:
                        fingers.append(1)
                    else:
                        fingers.append(0)
                # total fingers
                totalFingers = fingers.count(1)
                
                # 손가락 개수에 따른 연산과정
                if (totalFingers == 0): #screenshot
                    function = "screenshot"
                    # if (src == 0):
                    #     pyautogui.screenshot().save('./screenshot' + date.today().strftime("%Y%m%d") + str(src_cnt) + '.png')
                    #     src_cnt += 1
                    src = 1

                elif (totalFingers == 1): #draw
                    function = "draw"
                    src = 0
                    flag = 0

                elif (totalFingers == 2): #pause
                    function = "pause"
                    src = 0

                elif (totalFingers == 3): #thickness change (10->20->30->5->10..)
                    function = "thickness"
                    if (src != 2):
                        if thickness == 10:
                            thickness = 25
                            thick = "3"
                        elif thickness == 25:
                            thickness = 45
                            thick = "4"
                        elif thickness == 45:
                            thickness = 2
                            thick = "1"
                        else:
                            thickness = 10
                            thick = "2"
                    src = 2

                elif (totalFingers == 4): #color change (g->b->r->g..)
                    function = "color"
                    if (src != 3):
                        if draw_color == green:
                            draw_color = black
                            draw_color_str = "black"
                        elif draw_color == black:
                            draw_color = red
                            draw_color_str = "red"
                        else:
                            draw_color = green
                            draw_color_str = "green"
                    src = 3

                elif (totalFingers == 5): #clear
                    #draw_color = black
                    # 이때까지 쌓았던 RGB points 들을 다시 reset 해준다
                    function = "clear"
                    src = 0
                    print('clear')
                    bpoints = [deque(maxlen=512)]
                    gpoints = [deque(maxlen=512)]
                    rpoints = [deque(maxlen=512)]
                    thickpoints = [deque(maxlen=1024)]

                    black_index = 0
                    green_index = 0
                    red_index = 0
                    #thick_index = 0

                print(totalFingers)
                
                cv2.putText(img, "Finger Count: "+str(totalFingers), (w-350, 250), cv2.FONT_HERSHEY_PLAIN, 2, black, 2)
                cv2.putText(img, "Func: "+function, (w-350, 300), cv2.FONT_HERSHEY_PLAIN, 2, black, 2)

            else: # 손을 제대로 인식하지 못했을 경우 그냥 탈출
                break

            mpDraw.draw_landmarks(img, handLms, mpHands.HAND_CONNECTIONS)
            # 실제 화면에 대해서 x, y를 연산
            index_lm_x = handLms.landmark[8].x # x for 2nd finger
            index_lm_y = handLms.landmark[8].y # y for 2nd finger

            # !손가락 1개가 아니라면
            # 현상태를 유지하면서, 나의 위치는 다음번에 사용하기 위해
            # 이전 (px, py) 로 사용한다
            if (flag) : # finger is not 1
                px = int(wCam * (1 - index_lm_x))
                py = int(hCam * index_lm_y)
                bpoints.append(deque(maxlen=512))
                black_index += 1
                gpoints.append(deque(maxlen=512))
                green_index += 1
                rpoints.append(deque(maxlen=512))
                red_index += 1

                break

            # !손가락이 1개인 경우
            # 나의 위치에서 (px, py) 로 그림을 과정이 필요하다
            nx, ny = int(index_lm_x * w), int(index_lm_y * h) # relative xy pos
            cv2.putText(img, "Pen pos. ("+str(nx)+","+str(ny)+")", (w-350, 350), cv2.FONT_HERSHEY_PLAIN, 2, black, 2)

            center = (nx, ny, thickness)
            if draw_color == black:
                bpoints[black_index].appendleft(center)
            elif draw_color == green:
                gpoints[green_index].appendleft(center)
            elif draw_color == red:
                rpoints[red_index].appendleft(center)

            # cv2.circle(img, (nx, ny), 10, (255, 0, 0), 5, cv2.FILLED) #draw

            # 현재의 위치는 다음번의 전에 사용했던 좌표가 되므로
            # px, py 로 선언해주어 다음에 사용가능
            px = int(wCam * index_lm_x)
            py = int(hCam * index_lm_y)

    else:
        cont == 0

    points = [bpoints, gpoints, rpoints]
    colors = [black, green, red]
    # 이때까지 쌓아두었던 points 들에 대한 연산
    # 실제로 화면에 뿌려주기 전에 쌓여있던 데이터들을 연산해준다
    for i in range(len(points)):
        for j in range(len(points[i])):
            for k in range(1, len(points[i][j])-1):
                if points[i][j][k - 1] is None or points[i][j][k] is None:
                    continue
                cv2.line(img, points[i][j][k - 1][:2], points[i][j][k][:2], colors[i], points[i][j][k-1][2])
    #cv2.putText(img, str(totalFingers), (45, 60), cv2.FONT_HERSHEY_PLAIN, 5, (0, 0, 0), 10)
    # canvas[canvas_height - h:, canvas_width - w:] = img # adding camera image to canvas
    cv2.imshow("Drawing", img)
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()