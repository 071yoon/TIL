import numpy as np
import matplotlib.pyplot as plt
import cv2
from skimage.feature import graycomatrix, graycoprops
import random

# === image read ==
img = 'grass'
def printFormat(num):
    if (num < 10):
        print(format(num, '.6f'), end='')
    elif (num >= 10 and num < 100):
        print(format(num, '.5f'), end='')
    elif (num >= 100 and num < 1000):
        print(format(num, '.4f'), end='')
    else:
        print(format(num, '.3f'), end='')

for loop in range(1, 11):
    imgNo = img + str(loop)
    image = cv2.imread(imgNo + '.jpg', cv2.IMREAD_GRAYSCALE)

    # === image grass and sky ===
    PATCH_SIZE = 32
    h, w = image.shape

    locations = []
    for i in range(10):
        x = random.randrange(0 + PATCH_SIZE / 2, w - PATCH_SIZE / 2)
        y = random.randrange(0 + PATCH_SIZE / 2, h - PATCH_SIZE / 2)
        locations.append((y, x))

    patches = list()
    for loc in locations:
        patches.append(image[loc[0] - int(PATCH_SIZE / 2):loc[0] + int(PATCH_SIZE / 2),
                            loc[1] - int(PATCH_SIZE / 2):loc[1] + int(PATCH_SIZE / 2)])
    # === cutted grass and sky area with GLCM ===
    dissim = list()
    correl = list()
    contra = list()
    homoge = list()
    energy = list()
    ASM = list()
    for patch in (patches):
        # print(patch)
        glcm = graycomatrix(patch, distances=[1], angles=[0], levels=256, symmetric=False, normed=True)
        dissim.append(graycoprops(glcm, 'dissimilarity')[0, 0])
        correl.append(graycoprops(glcm, 'correlation')[0, 0])
        contra.append(graycoprops(glcm, 'contrast')[0, 0])
        homoge.append(graycoprops(glcm, 'homogeneity')[0, 0])
        energy.append(graycoprops(glcm, 'energy')[0, 0])
        ASM.append(graycoprops(glcm, 'ASM')[0, 0])

    # print(len(dissim))
    dis = 0
    cor = 0
    con = 0
    hom = 0
    ene = 0
    asm = 0
    for i in range(len(dissim)):
        print(img + str(loop - 1) + str(i) + "\t\t", end='')
        printFormat(dissim[i])
        print("\t\t", end='')
        printFormat(correl[i])
        print("\t\t", end='')
        printFormat(contra[i])
        print("\t\t", end='')
        printFormat(homoge[i])
        print("\t\t", end='')
        printFormat(energy[i])
        print("\t\t", end='')
        printFormat(ASM[i])
        print("")