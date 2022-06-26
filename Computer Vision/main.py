import numpy as np
import matplotlib.pyplot as plt
import cv2
from skimage.feature import greycomatrix, greycoprops

# === image read ==
image = cv2.imread('camera.png', cv2.IMREAD_GRAYSCALE)

# === image grass and sky ===
PATCH_SIZE = 16

grass_locations = [(370, 454), (372, 22), (444, 244), (455, 455)]
grass_patches = list()
for loc in grass_locations:
    grass_patches.append(image[loc[0]:loc[0] + PATCH_SIZE,
                        loc[1]:loc[1] + PATCH_SIZE])

sky_locations = [(38, 32), (138, 28), (47, 437), (145, 379)]
sky_patches = list()
for loc in sky_locations:
    grass_patches.append(image[loc[0]:loc[0] + PATCH_SIZE,
                        loc[1]:loc[1] + PATCH_SIZE])

# === cutted grass and sky area with GLCM ===
xs = list()
ys = list()
for patch in (grass_patches + sky_patches):
    # print(patch)
    glcm = greycomatrix(patch, distances=[1], angles=[0], levels=256, symmetric=False, normed=True)
    xs.append(greycoprops(glcm, 'dissimilarity')[0, 0])
    ys.append(greycoprops(glcm, 'correlation')[0, 0])

fig = plt.figure(figsize=(8, 8))

ax = fig.add_subplot(3, 2, 1)
ax.imshow(image, cmap=plt.cm.gray, vmin=0, vmax=255)
for(y, x) in grass_locations:
    ax.plot(x + PATCH_SIZE / 2, y + PATCH_SIZE / 2, 'gs')
for(y, x) in sky_locations:
    ax.plot(x + PATCH_SIZE / 2, y + PATCH_SIZE / 2, 'bs')
ax.set_xlabel('Original Image')

ax = fig.add_subplot(3, 2, 2)
ax.plot(xs[:len(grass_patches)], ys[:len(grass_patches)], 'go',
        label='Grass')
ax.plot(xs[len(sky_patches)], ys[len(sky_patches)], 'bo',
        label='Sky')
ax.set_xlabel('GLCM Dissimilarity')
ax.set_ylabel('GLCM Correlation')
ax.legend()

for i, patch in enumerate(grass_patches):
    ax = fig.add_subplot(3, len(grass_patches),
                        len(grass_patches)*1 + i + 1)
    ax.imshow(patch, cmap=plt.cm.gray,
                vmin=0, vmax=255)
    ax.set_xlabel('Grass %d' % (i + 1))

for i, patch in enumerate(sky_patches):
    ax = fig.add_subplot(3, len(sky_patches),
                        len(sky_patches)*2 + i + 1)
    ax.imshow(patch, cmap=plt.cm.gray,
                vmin=0, vmax=255)
    ax.set_xlabel('Sky %d' % (i + 1))

plt.tight_layout()
plt.show()