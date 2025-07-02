1. Added the image.
2. Used 'medianBlur' over 'blur' as medianblur don't blur out edges as compared to noise. Used loop to do it a few times.
3. Used 'threshold' to get marked boundary.
4. Used repeated threshold and blur to smooth out the curve.
5. Cropped out the boundary (if drawn). Manually adjust 'N' for it.
6. Used contour to get a single line path.
7. Used Hierarchy to get the outermost path. Since outermost curve have no parents, used this logic to get it.
8. Extracted (x,y) coordinates out of it.
9. Lastly, used these coordinates to get the .CSV and .SVG files.
10. Later, we can modify the .SVG file to get the required path(in case of open paths).
