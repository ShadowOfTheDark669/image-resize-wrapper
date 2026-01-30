### image-resize-wrapper
A small wrapper around `ImageMagick` , written in `C` which resizes image to a `n-th` percentage of their original size 

# USAGE:
`imageresize source_image_with_absolute_path reduction_factor output_image_with_absolute_path` \


`source_image_with_absolute_path` : Absolute path of the source image to be resized. \
`reduction_factor` : `n` where `n` can be a whole or decimal number. The resulting image is `n`th percent of the source image. \
`output_image_with_absolute_path` : Output image name with absolute path. \

# COMPILING THE BINARY:
1. Download the `source code`
2. Compile with preferred options for Windows/Linux/etc. Example:
`gcc imageresize.c -o imageresize` for Linux

# ENJOY!

-------------------------------
