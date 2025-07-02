Overview
This Python script processes a hand-drawn image to extract its main path as a skeletonized line. 
It uses OpenCV, numpy and scikit-image to perform image processing tasks such as masking, noise removal, skeletonization, and contour detection. 
The final output is an image with the extracted path overlaid on the original image.

The script performs the following steps to extract the path from a hand-drawn image:

1. Load the Image: Reads the input image (hand_drawn_image.jpg) using OpenCV.
2. Convert to HSV: Converts the image to HSV color space to isolate the drawn path based on color.
3. Create a Mask: Applies a color threshold in HSV space to create a binary mask of the drawn path.
4. Convert to Black & White: Creates a white mask of the path for further processing.
5. Remove Noise: Uses morphological operations (erosion and dilation) to remove noise from the mask.
6. Skeletonization: Applies skeletonization to reduce the path to a 1-pixel-wide line using scikit-image's skeletonize.
7. Contour Detection: Detects contours in the skeletonized image to extract the path.
8. Filter Contours: Ignores small contours (less than 50 points) to avoid noise.
9. Extract Path: Converts the contour points into a list of (x, y) coordinates.
10. Draw the Path: Draws the extracted path on a blank image and overlays it on the original image.
