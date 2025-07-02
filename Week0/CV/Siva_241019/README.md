## What the Script Does

1. **Read the Input Image** (Hand Drawn Doodle)
2. **Pre-Process**
   - Convert BGR → HSV
   - Using colour masking, extract path separately from image
3. **Skeletonize the binary mask**
4. **Find contours from skeletonized image and plot over input image for path visualisation**
5. **Export contour points to Output.csv file** <br>
   *Each CSV row* : **X and Y coordinates**
6. **Display helper images at each major stage for quick visual debugging.**

## Requirements
- cv2
- matplotlib
- numpy
- csv
- skimage
