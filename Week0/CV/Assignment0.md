# DoodleBot Image Processing Assignment

## Objective
Process a hand-drawn image and extract clean, drawable paths suitable for a DoodleBot, using image processing techniques only.

![Description](./Input_image.jpg)

Pardon the shabby drawing ;)

## Task
Given a hand-drawn image:
- Extract all relevant drawable structures using image processing.
- Apply necessary transformations and corrections (e.g., homography).
- Display meaningful visual outputs for each major step.
- Export the path data in a suitable format.

## Requirements
Your script should visualize:
- The original image
- Preprocessed image (e.g., thresholded or binarized)
- Edge or contour detections
- Skeletonized or thinned paths
- Final processed image with drawable paths overlaid

## Deliverables
- A Google Colab notebook or Python script
- Output figures for each stage of processing
- Visualization of the path data obtained after preprocessing through img procesing techniques
- Dedicate a readme file describing the process through which the final solution was arrived

## Disclaimer
- The processes outlined in the requirements are not the only ones that must be used in the solution, they provide a basic framework to guide you. The main focus should be on extracting the most optimal path from the given input image.

# Assignment Submission Repository

All assignments should be submitted via **Pull Requests (PRs)** to this repository. Follow the instructions below to ensure your submission is valid and gets reviewed on time.

---

## 📋 Submission Guidelines

1. **Fork this repository** to your GitHub account.

2. **Clone your forked repository** to your local system:
   ```bash
   git clone https://github.com/MrigeeshAshwin/DoodleBot.git cd DoodleBot

3. **Create a new branch** for your assignment:
   ```bash
   git checkout -b assignment-<number>-<your-name>

4. **Add your assignment files** in a new directory under:
   Example:
    <pre><code>submissions/&lt;your-name&gt;/assignment-&lt;number&gt;/ 
      ├── solution.py # main code file 
      ├── README.md # (explanation of your approach)
      └── other_file.ext # any other relevant files </code></pre>

5. Commit your changes:
   ```bash
   git add .
   git commit -m "Add assignment <number> by <your-name>"

6. Push your branch to your GitHub fork:
   ```bash
   git push origin assignment-<number>-<your-name>

7. Open a Pull Request to the main repository from your fork.
   Make sure your PR title follows this format:
   Assignment <number>: <your-name>



