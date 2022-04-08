import cv2
import mediapipe as mp
from collections import deque

# pen
red = (0, 0, 255)
green = (0, 255, 0)
black = (0, 0, 0)
draw_color = green
thickness = 10

#color index
black_index = 0
green_index = 0
red_index = 0

# camera
wCam, hCam = 1080, 720
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

# previous finger coordinates
px = 0
py = 0
cont = 0 # currently drawing
tipIds = [4, 8, 12, 16, 20] #finger 1, 2, 3, 4, 5
success, img = cap.read()

#rgb deque
bpoints = [deque(maxlen=1024)]
gpoints = [deque(maxlen=1024)]
rpoints = [deque(maxlen=1024)]


while True:

    success, img = cap.read() # reads image from camera
    # cache = img.copy()
    # clear_canvas = img.copy()
    h, w, c = img.shape # image dimensions
    imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB) # BGR to RGB
    results = hands.process(imgRGB) # searching for a hand

    flag = 1
    if results.multi_hand_landmarks: # if the hand is found
        for handLms in results.multi_hand_landmarks: # for each hand
            lmList = [] #hands list 0 to 20
            for id in enumerate(handLms.landmark):
                cx, cy = handLms.landmark[id[0]].x, handLms.landmark[id[0]].y
                lmList.append([id[0], cx, cy])
            if len(lmList) != 0: #if recognized well
                fingers = []
                # is thumb up 
                if lmList[4][1] > lmList[3][1]:
                    fingers.append(1)
                else:
                    fingers.append(0)
                # is other fingers up
                for id in range(1, 5):
                    if lmList[tipIds[id]][2] < lmList[tipIds[id] - 2][2]:
                        fingers.append(1)
                    else:
                        fingers.append(0)
                # total fingers
                totalFingers = fingers.count(1)

                if (totalFingers == 0):
                    draw_color = red
                elif (totalFingers == 1):
                    flag = 0
                elif (totalFingers == 2):
                    draw_color = green
                elif (totalFingers == 3):
                    draw_color = black
                elif (totalFingers == 4):
                    print('clear')
                    bpoints = [deque(maxlen=512)]
                    gpoints = [deque(maxlen=512)]
                    rpoints = [deque(maxlen=512)]
                    ypoints = [deque(maxlen=512)]

                    black_index = 0
                    green_index = 0
                    red_index = 0

                elif (totalFingers == 5): # Exit when fingers is 5
                    print('exit')
                    # exit()

                print(totalFingers)
                cv2.putText(img, str(totalFingers), (45, 60), cv2.FONT_HERSHEY_PLAIN, 5, (0, 0, 0), 10)
            else:
                break

            mpDraw.draw_landmarks(img, handLms, mpHands.HAND_CONNECTIONS)
            index_lm_x = handLms.landmark[8].x # x for 2nd finger
            index_lm_y = handLms.landmark[8].y # y for 2nd finger

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

            nx, ny = int(index_lm_x * w), int(index_lm_y * h) # relative xy pos
            center = (nx, ny)
            if draw_color == black:
                bpoints[black_index].appendleft(center)
            elif draw_color == green:
                gpoints[green_index].appendleft(center)
            elif draw_color == red:
                rpoints[red_index].appendleft(center)
            # cv2.circle(img, (nx, ny), 10, (255, 0, 0), 5, cv2.FILLED) #draw
            # cv2.line(img, (px, py), (int(wCam * index_lm_x), int(hCam * index_lm_y)), draw_color, thickness)

            px = int(wCam * index_lm_x)
            py = int(hCam * index_lm_y)

    else: cont == 0

    points = [bpoints, gpoints, rpoints]
    colors = [black, green, red]
    for i in range(len(points)):
        for j in range(len(points[i])):
            for k in range(1, len(points[i][j])):
                if points[i][j][k - 1] is None or points[i][j][k] is None:
                    continue
                cv2.line(img, points[i][j][k - 1], points[i][j][k], colors[i], 2)
    img = cv2.flip(img, 1) #flip hand
    # canvas[canvas_height - h:, canvas_width - w:] = img # adding camera image to canvas
    cv2.imshow("Drawing", img)
    cv2.waitKey(1)