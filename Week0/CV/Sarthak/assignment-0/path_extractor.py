
from skimage.morphology import skeletonize
from skimage.util import invert
import os

def show(title, img, cmap='gray'):
    plt.figure(figsize=(6,6))
    plt.title(title)
    plt.imshow(img, cmap=cmap)
    plt.axis('off')
    plt.show()

# Step 1: Load original image
img = cv2.imread('hand_drawn_sample.png', cv2.IMREAD_COLOR)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
show("Original Image", cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
show("Grayscale", gray)

# Step 2: Preprocessing - Binarization
_, binary = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)
show("Binarized (Inverted)", binary)

# Step 3: Edge detection (optional for visualization)
edges = cv2.Canny(binary, 50, 150)
show("Edges (Canny)", edges)

# Step 4: Skeletonization
skeleton = skeletonize(binary // 255)
show("Skeletonized", skeleton)

# Step 5: Extract skeleton paths (coordinates of white pixels)
coords = np.column_stack(np.where(skeleton == 1))

# Visualization: Overlay paths on original image
overlay = img.copy()
for y, x in coords:
    cv2.circle(overlay, (x, y), 1, (0, 0, 255), -1)
show("Drawable Paths Overlay", cv2.cvtColor(overlay, cv2.COLOR_BGR2RGB))

# Step 6: Export path data
with open('paths.txt', 'w') as f:
    for y, x in coords:
        f.write(f"{x},{y}\n")

print("Paths exported to paths.txt")