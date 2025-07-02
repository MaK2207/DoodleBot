import cv2
import numpy as np
from skimage.morphology import skeletonize

img = cv2.imread('hand_drawn_image.jpg')

#Convert to HSV 
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

#Setting the HSV range
lower = np.array([120, 50, 50])
upper = np.array([150, 255, 255])

# Creating a mask
mask = cv2.inRange(hsv, lower, upper)
masked_img = cv2.bitwise_and(img, img, mask=mask)
cv2.imwrite("1_masked.jpg", masked_img)

#Convert to b&w
white = np.ones(img.shape[:2], dtype = 'uint8') *255
white_mask = cv2.bitwise_and(white, white, mask=mask)
cv2.imwrite("2_white_masked.jpg", white_mask)

# Removing Noise
kernel = np.ones((3, 3), np.uint8)
eroded = cv2.erode(white_mask, kernel, iterations=2)
dilated = cv2.dilate(eroded, kernel, iterations=2)
cv2.imwrite("3_denoised_image.jpg", dilated)

# Skeletonization
binary_skel = dilated / 255.0
skeleton = skeletonize(binary_skel).astype(np.uint8) * 255
cv2.imwrite("4_skeletonized_paths.jpg", skeleton)

#Contour Detection
contours, _ = cv2.findContours(skeleton, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

#Draw contours
contour_img = np.zeros(img.shape[:2], dtype = 'uint8')
cv2.drawContours(contour_img, contours, -1, 255, 2)
cv2.imwrite("5_contours.jpg", contour_img)

skeleton_paths = []
for contour in contours:
    if len(contour) < 50:
        continue

    path = [point[0] for point in contour]

    skeleton_paths.append(path)

# Draw the skeleton paths
skeleton_img = np.zeros_like(img)
for path in skeleton_paths:
    for i in range(len(path) - 1):
        cv2.line(skeleton_img, path[i], path[i + 1], (0, 255, 0), 2)
cv2.imwrite("6_skeleton_paths.jpg", skeleton_img)

# Overlay the path on the original image
final_img = img.copy()
for path in skeleton_paths:
    for i in range(len(path) - 1):
        cv2.line(final_img, path[i], path[i + 1], (255, 0, 0), 2)

cv2.imwrite("7_final.jpg", final_img)