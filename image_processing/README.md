# Image Processing

- [Image Processing](#image-processing)
  - [Datasets](#datasets)
    - [First Video](#first-video)
  - [Greyscalling](#greyscalling)
  - [Image reduction](#image-reduction)
  - [Differentiation](#differentiation)

## Datasets

### First Video

[Video used for first test](https://www.idiap.ch/resource/gestures/data/ht_peipa.tar.gz)

## Greyscalling

Already grayscaled for fist video, PIL and skimage libs can easily grayscale a video (video is an "array" of picture)

## Image reduction

do not use mean on column because loose datas easily
sum_col/max(sum_col) -> can be nice to change this fct a bit (using log or something else)

filter ?

can't we do this with NN ?

## Differentiation

object detection before ?
(+) know mvt without NN
(-) need a lot of memory power

only ssim ?
(+) faster and use NN
(-) need many pictures
