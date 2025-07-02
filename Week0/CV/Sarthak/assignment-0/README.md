# DoodleBot Path Extractor

This script processes a hand-drawn image and extracts drawable paths using image processing techniques suitable for a DoodleBot.

## Steps:
1. Load and convert image to grayscale
2. Apply binarization and skeletonization
3. Detect contours or edges (optional)
4. Extract skeleton coordinates as paths
5. Overlay paths and export as coordinate file

## Output:
- Visuals for each processing stage
- `paths.txt` with extracted path coordinates

## Requirements:
- OpenCV
- NumPy
- Matplotlib
- scikit-image