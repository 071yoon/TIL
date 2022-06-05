import numpy as np
import cv2
from matplotlib import pyplot as plt
from scipy import signal as sg
import random

# === image read ==
total = [0 for i in range(9)]
img = 'brick'
for loop in range(1, 11):
    imgNo = img + str(loop)
    image = cv2.imread(imgNo + '.jpg')

    PATCH_SIZE = 32
    h, w, c = image.shape

    locations = []
    for i in range(10):
        x = random.randrange(0 + PATCH_SIZE / 2, w - PATCH_SIZE / 2)
        y = random.randrange(0 + PATCH_SIZE / 2, h - PATCH_SIZE / 2)
        locations.append((y, x))

    patches = list()
    for loc in locations:
        patches.append(image[loc[0] - int(PATCH_SIZE / 2):loc[0] + int(PATCH_SIZE / 2),
                            loc[1] - int(PATCH_SIZE / 2):loc[1] + int(PATCH_SIZE / 2)])
    cnt = 1
    cntr = 0
    for patch in (patches):
        cntr += 1
        gray = cv2.cvtColor(patch, cv2.COLOR_BGR2GRAY)
        (rows, cols) = gray.shape[:2]

    # === image processing ===
        smooth_kernel = (1/25) * np.ones((5, 5))
        gray_smooth = sg.convolve(gray, smooth_kernel, "same")
        gray_processed = np.abs(gray - gray_smooth)

        # === Law's Texture filter ===
        filter_vectors = np.array([[ 1,  4,  6,  4,  1],
                                   [-1, -2,  0,  2,  1],
                                   [-1,  0,  2,  0,  1],
                                   [ 1, -4,  6, -4,  1]])
        filters = list()
        for i in range(4):
            for j in range(4):
                filters.append(np.matmul(filter_vectors[i][:].reshape(5, 1),
                                         filter_vectors[j][:].reshape(1, 5)))
        conv_maps = np.zeros((rows, cols, 16))
        for i in range(len(filters)):
            conv_maps[:, :, i] = sg.convolve(gray_processed, filters[i], 'same')

        # texture map calculation
        texture_maps = list()
        texture_maps.append((conv_maps[:, :, 1] + conv_maps[:, :, 4]) // 2)
        texture_maps.append((conv_maps[:, :, 2] + conv_maps[:, :, 8]) // 2)
        texture_maps.append((conv_maps[:, :, 3] + conv_maps[:, :, 12]) // 2)
        texture_maps.append((conv_maps[:, :, 7] + conv_maps[:, :, 13]) // 2)
        texture_maps.append((conv_maps[:, :, 6] + conv_maps[:, :, 9]) // 2)
        texture_maps.append((conv_maps[:, :, 11] + conv_maps[:, :, 14]) // 2)
        texture_maps.append(conv_maps[:, :, 10])
        texture_maps.append(conv_maps[:, :, 5])
        texture_maps.append(conv_maps[:, :, 15])
        texture_maps.append(conv_maps[:, :, 0])

        TEM = list()
        for i in range(9):
            TEM.append(np.abs(texture_maps[i]).sum() / np.abs(texture_maps[9].sum()))

        print(img + str(loop - 1) + str(cntr - 1) + "\t\t", end='')
        cnt += 1
        for i in range(9):
            print(format(TEM[i], '.6f'), end='\t\t')
            total[i] += TEM[i]
        print("")
